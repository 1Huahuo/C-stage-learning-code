#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_CAPACITY 10

typedef int ElemType;
//typedef struct { // 数组队列
//	ElemType elements[QUEUE_CAPACITY]; // 队列上限容量
//	int front; // 指向队头
//	int rear; // 指向队尾下一个元素
//	int size; // 当前队列大小
//}ArrayQueue;
typedef struct node_q {
	ElemType data;
	struct node_q* next;
}QueueNode; // 队列结点
typedef struct {
	QueueNode* front; // 指向队首结点
	QueueNode* rear; // 指向队尾结点
}LinkedQueue; // 队列

// 创建链式队列
LinkedQueue* queue_create();
// 销毁链式队列
void queue_destroy(LinkedQueue* linked_queue);
// 判空
bool queue_is_empty(LinkedQueue* linked_queue);
// 入队列
bool enqueue(LinkedQueue* linked_queue, ElemType val);
// 出队列并返回队首元素
ElemType dequeue(LinkedQueue* linked_queue);
// 访问队首元素
ElemType queue_peek(LinkedQueue* linked_queue);
// 注意：链式队列显然不具有满的概念，所以也不需要执行判满操作。

#endif // !LINKED_QUEUE_H
