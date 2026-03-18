/*
判断单链表有环的最佳实现是利用快慢指针法，但哈希表也是一个不算太差的求解方式。
    你可以在遍历链表的过程中，将链表的每一个结点存入哈希表，若发现有重复结点被存入哈希表，
则确定单链表有环。
*/
// 你可以基于下面头文件来实现哈希表：
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CAPACITY 10  // 哈希表的底层数组长度是10
bool is_has_loop = false;

typedef struct node {
    int data;
    struct node* next;
}Node;	// 哈希表当中存储的链表结点类型

// 此哈希表只存储键,不存储value
// key值存储链表结点的指针
typedef Node* KeyType;

// 键值对结点，此时无需存储值了
typedef struct node_s {
    KeyType key;    // 键
    struct node_s* next;
} HashNode; // 键值对结点类型

typedef struct {
    HashNode* buckets[CAPACITY];
    uint32_t seed;
    int size;
    int length;
} HashMap;    // 哈希表结构体类型

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
    map->seed = time(NULL);
    map->length = CAPACITY;
    return map;
}
// 销毁哈希表
void hashmap_destroy(HashMap* map) {
    if (map->size)
        for (int i = 0; i < CAPACITY; i++) {
            HashNode* cur = map->buckets[i];
            while (cur) {
                HashNode* t = cur;
                cur = cur->next;
                free(t->key); // 不要忘记释放键key和值val
                free(t);
            }
        }
    free(map);
}

/*
    尝试将链表结点的指针(地址)插入哈希表
    若发现结点已存入哈希表, 则函数返回true
    若结点未存入, 则将结点地址存入哈希表并返回false
*/
bool hashmap_put(HashMap* map, KeyType key) {
    uint32_t hash_num = hash(key, strlen(key), map->seed); // 1.key值转整数
    int index = hash_num % map->length; // 2.取余得哈希表中下标
    HashNode* cur = map->buckets[index]; // 3.看这个下标对应链表中是否有数据，若有则遍历找重复值，没有直接插入

    while (cur) { //遍历找重复值
        if (strcmp(key, cur->key) == 0) {
            is_has_loop = true;
            printf("插入失败，有重复值\n");
            return false;
        }
        cur = cur->next;
    }

    // 此时cur对应链表中无数据，或者有数据但是没重复，均可头插到此链表
    HashNode* node = (HashNode*)calloc(1, sizeof(HashNode));
    node->key = key;
    node->next = map->buckets[index];
    map->buckets[index] = node;
    map->size++;

    return NULL;
}

//构建有环单链表的代码如下：
// 实现尾插法
void insert_behind_tail(Node** head, int data) {
    // 1.新建结点
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("malloc failed in insert_behind_tail.\n");
        exit(1);
    }
    // 初始化新结点
    new_node->next = NULL;
    new_node->data = data;

    // 2.判断尾插前链表是否为空
    if (*head == NULL) {
        // 链表尾插之前为空
        *head = new_node;
        return;
    }
    // 链表尾插时 不为空
    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }	// while循环结束时, curr指向当前的尾结点
    tail->next = new_node;
}

int main(void) {
    Node* head = NULL;	// 头指针是空指针, 表示链表为空
    insert_behind_tail(&head, 1);
    insert_behind_tail(&head, 2);
    insert_behind_tail(&head, 3);
    insert_behind_tail(&head, 4);
    insert_behind_tail(&head, 5);

    // 希望构建一个 8->3 的有环链表 希望尾结点指向链表的第三个结点, 第三个结点索引是2
    int count = 0;
    Node* third_node = NULL;
    Node* tail = head;
    while (tail->next != NULL) {
        count++;
        if (count == 3) {
            // tail就指向了第三个结点
            third_node = tail;
        }
        tail = tail->next;
    }	// 循环结束时, tail指向尾结点, third_node指向链表第三个结点
    tail->next = third_node;

    // 测试一下环路有没有构建成功
    //Node* p = head;
    //for(int i = 0; i < 10; i++){
    //    printf("%d->", p->data);
    //    p = p->next;
    //}
    //printf("\n");

    Node* p = head;
    HashMap* map = hashmap_create();
    while (p) {
        hashmap_put(map, p);
        if (is_has_loop) {
            printf("存在环路\n");
            return 0;
        }
        p = p->next;
    }
    printf("不存在环路\n");
    return 0;
}