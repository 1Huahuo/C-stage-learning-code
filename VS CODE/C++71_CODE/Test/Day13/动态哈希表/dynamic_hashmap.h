#ifndef DYNAMIC_HASHMAP_H
#define DYNAMIC_HASHMAP_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define HASHMAP_INIT_CAPACITY 10
#define LOAD_FACTOR_THRESHOLD  0.75     // 负载因子的阈值
#define CAPACITY_THRESHOLD 1024     // 数组容量的阈值

typedef char* KeyType;
typedef char* ValueType;

typedef struct node_s {
    KeyType key;
    ValueType val;
    struct node_s* next;
} KeyValueNode;

typedef struct {
    KeyValueNode** buckets;		// 此时哈希桶是一个动态数组，指向char*元素的指针，所以是一个二级指针
    int size;				// 键值对的个数
    int capacity;			// 数组的长度
    uint32_t seed;		// 哈希函数需要的种子值
} DynamicHashMap;

// 创建一个固定容量的哈希表
DynamicHashMap* hashmap_create();
// 销毁一个哈希表
void hashmap_destroy(DynamicHashMap* map);
// 插入一个键值对，若有重复返回旧值
ValueType hashmap_put(DynamicHashMap* map, KeyType key, ValueType val);
// 查询一个键值对
ValueType hashmap_get(DynamicHashMap* map, KeyType key);
// 删除某个键值对
bool hashmap_remove(DynamicHashMap* map, KeyType key);

#endif // !DYNAMIC_HASHMAP_H
