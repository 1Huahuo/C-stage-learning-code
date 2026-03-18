#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;	// 该队列当前存储int元素
#define DEFAULT_CAPACITY 10	// 数组队列的初始长度是10
#define THRESHOLD 1000	// 超过阈值每次扩容1.5倍扩，否则2倍的扩

// 定义队列结构体
typedef struct {
	ElemType* data;   // 动态数组存储队列元素
	int front;           // 标记队头元素的索引
	int rear;            // 标记队尾元素下一个位置的索引
	int size;            // 当前队列中元素数量
	int capacity;        // 队列容量
} DynamicQueue;

// 队列基本操作函数声明
// 创建动态数组队列
DynamicQueue* create_queue();
// 销毁动态数组队列
void destroy_queue(DynamicQueue* q);
// 判空
bool is_empty(DynamicQueue* q);
// 判满
bool is_full(DynamicQueue* q);
// 入队列
bool enqueue(DynamicQueue* q, ElemType data);
// 出队列并且返回队头元素
ElemType dequeue(DynamicQueue* q);

#endif // DYNAMIC_QUEUE_H