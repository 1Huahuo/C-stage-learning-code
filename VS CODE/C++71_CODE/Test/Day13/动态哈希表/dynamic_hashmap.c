#include "dynamic_hashmap.h"

// 初映射
static uint32_t hash(const void* key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;
        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}
// 再映射
static void rehash(KeyValueNode* cur, KeyValueNode** new_buckets, int new_capacity, uint32_t seed) {
    // 计算 key 的哈希值 , 即再映射rehash
    int index = hash(cur->key, strlen(cur->key), seed) % new_capacity;
    // 头插法插入新的对应链表
    cur->next = new_buckets[index];
    new_buckets[index] = cur;
}
// 扩容
static void hashmap_capacity_grow(DynamicHashMap* map) {
    /*
    * 扩容策略：
    * 1.如果容量没有达到阈值，那就每次将长度扩大为原先的2倍
    * 2.如果容量达到阈值，此时哈希表已经很长了，为了避免扩容过程性能损耗过大
    *   所以扩容保守一些，每次只扩容阈值长度的容量
    *
    * 扩容的过程：
    * 1.每个键值对结点都要重新计算哈希值，重新映射到新哈希桶中(新数组)
    * 2.原先的动态数组的链表很复杂，难以进行重哈希操作，建议直接丢弃它
    * 重新创建一个新动态数组
    */
    int new_capacity =
        (map->capacity <= CAPACITY_THRESHOLD) ? 
            (map->capacity << 1) : (map->capacity + CAPACITY_THRESHOLD);

    // 动态数组扩容需要使用 calloc
    KeyValueNode** new_buckets = calloc(new_capacity, sizeof(KeyValueNode*));
    if (new_buckets == NULL) {
        printf("Error: calloc failed in grow_capacity\n");
        exit(1);
    }
    // 每次扩容都更改一次哈希种子，提高安全性
    uint32_t seed = time(NULL);

    // 将所有键值对重新映射到新数组中
    for (int i = 0; i < map->capacity; i++) {
        KeyValueNode* cur = map->buckets[i];
        while (cur != NULL) {
            KeyValueNode* next = cur->next;
            // 重新进行哈希映射，并且重新插入到新的哈希表中
            rehash(cur, new_buckets, new_capacity, seed);
            cur = next;
        }
    }
    // 将旧动态数组free，但是注意不要free键值对结点，结点已经被链接到新数组中了。
    free(map->buckets);
    // 更新 HashMap 的信息
    map->buckets = new_buckets;
    map->capacity = new_capacity;
    map->seed = seed;
}

// 创建一个固定容量的哈希表
DynamicHashMap* hashmap_create() {
	DynamicHashMap* map = (DynamicHashMap*)calloc(1, sizeof(DynamicHashMap));
	if (map == NULL) {
		printf("calloc failed in hashmap_create.\n");
		return NULL;
	}
	map->buckets = (KeyValueNode**)calloc(HASHMAP_INIT_CAPACITY, sizeof(KeyValueNode*));
	if (map->buckets == NULL) {
        free(map); // 不要忘记先释放哈希表结构体map
		printf("calloc failed in hashmap_create.\n");
		return NULL;
	}
	map->capacity = HASHMAP_INIT_CAPACITY;
	map->seed = time(NULL);

    return map;
}

// 销毁一个哈希表
void hashmap_destroy(DynamicHashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        KeyValueNode* cur = map->buckets[i];
        while (cur) {
            KeyValueNode* t = cur;
            cur = cur->next;
            free(t);
        }
    }
    free(map->buckets); // 多一个步骤，销毁动态哈希桶
    free(map);
}

// 插入一个键值对，若有重复返回旧值
ValueType hashmap_put(DynamicHashMap* map, KeyType key, ValueType val) {
    int index = hash(key, strlen(key), map->seed) % map->capacity;

    KeyValueNode* cur = map->buckets[index];
    while (cur) { // 能在表中找到相同的key的，则更新
        if (strcmp(key, cur->key) == 0) {
            ValueType old_val = cur->val;
            cur->val = val;
            return old_val;
        }
        cur = cur->next;
    }

    // 找不到相同key结点，则直接插入，但这时插入需注意扩容问题
    double load_factor = (1.0 * map->size) / (map->capacity); // 哈希表总元素个数/哈希桶数组长度
    if (load_factor >= LOAD_FACTOR_THRESHOLD) {
        hashmap_capacity_grow(map); // 注意这是新结点，所以与再映射无关
        index = hash(key, strlen(key), map->seed) % map->capacity;
    }
    // 开始插入
    KeyValueNode* node = malloc(sizeof(KeyValueNode));
    if (node == NULL) {
        printf("malloc failed in hashmap_put.\n");
        exit(1);
    }
    node->key = key;
    node->val = val;
    node->next = map->buckets[index];
    map->buckets[index] = node;
    map->size++;
    return NULL;
}

// 查询一个键值对
ValueType hashmap_get(DynamicHashMap* map, KeyType key) {
    int index = hash(key, strlen(key), map->seed) % map->capacity;
    KeyValueNode* cur = map->buckets[index];
    while (cur) {
        if (strcmp(key, cur->key) == 0)
            return cur->val;
        cur = cur->next;
    }
    return NULL;
}

// 删除某个键值对
bool hashmap_remove(DynamicHashMap* map, KeyType key) {
    int index = hash(key, strlen(key), map->seed) % map->capacity;
    KeyValueNode* pre = NULL;
    KeyValueNode* cur = map->buckets[index];

    // !别忘记对应链表直接为空，所以可以把cur!=NULL的情况全写进一个循环内
    if (cur == NULL)
        return false;

    if (strcmp(key, cur->key) == 0) {
        map->buckets[index] = cur->next;
        free(cur);
        map->size--;
        return true;
    }

    pre = cur;
    cur = cur->next;
    while (cur) {
        if (strcmp(key, cur->key) == 0) {
            pre->next = cur->next;
            free(cur);
            map->size--;
            return true;
        }
        pre = cur;
        cur = cur->next;
    }
    return false;
}