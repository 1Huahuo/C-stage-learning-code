#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// 创建
Vector* vector_create() {
	Vector* vec = (Vector*)malloc(sizeof(Vector));
	if (vec == NULL) {
		printf("malloc failed in vector_create.\n");
		return NULL; // 注意返回值
	}

	// vec不能装数组数据
	// vec->table 指向的空间才能装数组数据
	vec->table = (DataType*)malloc(VECTOR_INIT_CAPACITY * sizeof(DataType));
	if (vec->table == NULL) {
		printf("malloc failed int vectortable_create in vector_create.\n");
		free(vec); // 空间申请失败直接释放vector容器指针，防止内存泄露
		return NULL;
	}

	vec->size = 0;
	vec->capacity = VECTOR_INIT_CAPACITY;

	return vec;
}

// 销毁
void vector_destroy(Vector* vec) {
	if (vec == NULL) return;

	if (vec->table != NULL) { // 注意先后顺序，避免不可到达内存区域
		free(vec->table);
	}
	free(vec);
}

// 打印
void vector_print(Vector* vec) {
	if (vec->size == 0) { // 空数组检查
		printf("[]\n");
		return;
	}

	printf("[");
	for (int i = 0; i < vec->size - 1; i++)
		printf("%d, ", vec->table[i]);
	printf("%d]\n", vec->table[vec->size - 1]);
}

// 扩容-副操作
void vector_grow(Vector* vec) {
	int new_capacity = vec->capacity * 2; // 最好使用一个新变量来暂存新的容量，防止无法复原

	// 最好使用新指针来暂存新的指针，防止扩容失败无法复原
	DataType* new_table = (DataType*)realloc(vec->table, new_capacity * sizeof(DataType));
	if (new_table == NULL) {
		printf("realloc failed in vector_grow\n");
		return;
	}

	vec->table = new_table;
	vec->capacity = new_capacity;
}

// 向动态数组末尾添加一个元素
void vector_push_back(Vector* vec, DataType val) {
	if (vec->size == vec->capacity) // 扩容的时机
		vector_grow(vec);

	vec->table[vec->size] = val;
	vec->size++;
}

// 在动态数组最前面添加元素，所有元素依次后移
void vector_push_front(Vector* vec, DataType val) {
	if (vec->size == vec->capacity)
		vector_grow(vec);

	for (int i = vec->size - 1; i >= 0; i--)
		vec->table[i + 1] = vec->table[i];
	vec->table[0] = val;
	vec->size++;
}

// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void vector_insert(Vector* vec, int idx, DataType val) {
	if (idx < 0 || idx > vec->size) { // 索引检查，后半判断是因为数组是连续的不能离散插入
		printf("index out of range in vector_insert.\n");
		return;
	}

	if (vec->size == vec->capacity)
		vector_grow(vec);

	for (int i = vec->size - 1; i >= idx; i++)
		vec->table[i + 1] = vec->table[i];
	vec->table[idx] = val;
	vec->size++;
}

// 按下标删除
DataType vector_delete_by_idx(Vector* vec, int idx) {
	DataType deleted_val;
	if (idx < 0 || idx >= vec->size) { // 与添加元素的检查略有不同，多个"="
		printf("index out of range in vector_delete_by_idx.\n");
		return 0;
	}

	// 删除元素不可能用得上扩容
	deleted_val = vec->table[idx];
	for (int i = idx; i < vec->size - 1; i++)
		vec->table[i] = vec->table[i + 1];
	vec->size--;
	return deleted_val;
}

// 按值删除
void vector_delete_by_val(Vector* vec, DataType delete_val) {
	int idx = -1;
	for (int i = 0; i < vec->size; i++)
		if (vec->table[i] == delete_val) {
			idx = i;
			break;
		}

	if (idx == -1) {
		printf("delete failed in vector_delete_by_val.\n"); // 查找失败
		return;
	}

	for (int i = idx; i < vec->size - 1; i++)
		vec->table[i] = vec->table[i + 1];
	vec->size--;
}

// 获取元素
DataType vector_get_val_by_idx(Vector* vec, int idx) {
	if (idx < 0 || idx >= vec->size) {
		printf("index out of range in vector_get_val_by_idx.\n");
		return 0;
	}
	return vec->table[idx];
}

// 修改元素
void vector_set(Vector* vec, int idx, DataType val) {
	if (idx < 0 || idx >= vec->size) {
		printf("Index out of range in vector_set\n");
		return;
	}
	vec->table[idx] = val;
}

// 获取下标
int vector_get_idx_by_val(Vector* vec, DataType val) {
	//int idx = -1; // 变量非必须
	for (int i = 0; i < vec->size; i++)
		if (vec->table[i] == val)
			return i; // 找到直接返回

	printf("val is nonexistent in vector_get_idx_by_val.\n"); // 查找失败
	return -1;
}