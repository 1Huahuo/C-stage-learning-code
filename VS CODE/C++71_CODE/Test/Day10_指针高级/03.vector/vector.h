#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 10

typedef int DataType;
typedef struct vector {
	DataType* table;
	int capacity;
	int size;
}Vector;

//函数声明：
// 创建
Vector* vector_create();
// 销毁
void vector_destroy(Vector* vec);
// 打印
void vector_print(Vector* vec);
// 向动态数组末尾添加一个元素
void vector_push_back(Vector* vec, DataType val);
// 在动态数组最前面添加元素，所有元素依次后移
void vector_push_front(Vector* vec, DataType val);
// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void vector_insert(Vector* vec, int idx, DataType val);
// 扩容-副操作
void vector_grow(Vector* vec);
// 按下标删除
DataType vector_delete_by_idx(Vector* vec, int idx);
// 按值删除
void vector_delete_by_val(Vector* vec, DataType delete_val);
// 获取元素
DataType vector_get_val_by_idx(Vector* vec, int idx);
// 修改元素
void vector_set(Vector* vec, int idx, DataType val);
// 获取下标
int vector_get_idx_by_val(Vector* vec, DataType val);

#endif // !VECTOR_H