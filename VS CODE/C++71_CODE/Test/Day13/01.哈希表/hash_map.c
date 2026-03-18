#include "hash_map.h"

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

// 创建一个固定容量的哈希表
HashMap* hashmap_create() {
	HashMap* map = (HashMap*)calloc(1, sizeof(HashMap));
	if (map == NULL) {
		printf("calloc failed in hashmap_create.\n");
		return NULL;
	}
	map->length = HASHMAP_CAPACITY;
	map->seed = time(NULL);

	return map;
}

// 销毁一个哈希表
void hashmap_destroy(HashMap* map) {
	if (map->size)
		for (int i = 0; i < HASHMAP_CAPACITY; i++) {
			KeyValueNode* cur = map->buckets[i];
			while (cur) {
				KeyValueNode* t = cur;
				cur = cur->next;
				free(t->key); // 不要忘记释放键key和值val
				free(t->val);
				free(t);
			}
		}
	free(map);
}

// 插入一个键值对，若有重复返回旧值
ValueType hashmap_put(HashMap* map, KeyType key, ValueType val) {
	uint32_t hash_num = hash(key, strlen(key), map->seed); // 1.key值转整数
	int index = hash_num % map->length; // 2.取余得哈希表中下标
	KeyValueNode* cur = map->buckets[index]; // 3.看这个下标对应链表中是否有数据，若有则遍历找重复值，没有直接插入

	while (cur) { //遍历找重复值
		if (strcmp(key, cur->key) == 0) {
			ValueType old_val = cur->val;
			cur->val = val;
			return old_val;
		}
		cur = cur->next;
	}

	// 此时cur对应链表中无数据，或者有数据但是没重复，均可头插到此链表
	KeyValueNode* node = (KeyValueNode*)calloc(1, sizeof(KeyValueNode));
	node->key = key;
	node->val = val;
	node->next = map->buckets[index];
	map->buckets[index] = node;
	map->size++;

	return NULL;
}

// 查询一个键值对
ValueType hashmap_get(HashMap* map, KeyType key) {
	uint32_t hash_num = hash(key, strlen(key), map->seed);
	int index = hash_num % map->length;

	KeyValueNode* cur = map->buckets[index];

	while (cur) {
		if (strcmp(key, cur->key) == 0)
			return cur->val;
		cur = cur->next;
	}
	return NULL; // 对应链表为空或者没找到
}
// 删除某个键值对
bool hashmap_remove(HashMap* map, KeyType key) {
	uint32_t hash_num = hash(key, strlen(key), map->seed);
	int index = hash_num % map->length;
	KeyValueNode* cur = map->buckets[index];

	// 要删除的是对应链表的首结点，需特殊处理
	if (strcmp(key, cur->key) == 0) {
		KeyValueNode* t = cur;
		cur = cur->next;
		free(t);
		map->size--;
		return true;
	}
	
	// 要删除的是非首结点
	KeyValueNode* pre = cur;
	cur = cur->next;
	while(cur) { // 若是有哨兵结点的话，就是cur->next != NULL，但不是很复杂的问题则没必要用哨兵
		if (strcmp(key, cur->key) == 0){
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


