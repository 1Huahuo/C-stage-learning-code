#include "linked_queue.h"

// 创建链式队列
LinkedQueue* queue_create() {
	LinkedQueue* linked_queue = (LinkedQueue*)calloc(1, sizeof(LinkedQueue));
	if (linked_queue == NULL) {
		printf("malloc failed in queue_create.\n");
		return NULL;
	}
	return linked_queue;
}

// 销毁链式队列
void queue_destroy(LinkedQueue* linked_queue) {
	//if (linked_queue == NULL)
	//	return; // 不要直接返回，会导致内存泄露，这两句可以直接删，反正free(NULL)无事发生,合法
	
	//if (linked_queue == NULL) { // 改正：需要判断，防止下面while判断中越界风险
	//	free(linked_queue);
	//	return;
	//} // 或者直接加入while：while(linked_queue && linked_queue->front)即二者均不等于NULL

	while (linked_queue && linked_queue->front) {
		QueueNode* p = linked_queue->front;
		linked_queue->front = linked_queue->front->next;
		free(p); // 释放队列结点结构体
	}
	free(linked_queue); // 队列结构体别忘记释放
}

// 判空
bool queue_is_empty(LinkedQueue* linked_queue) {
	//if (linked_queue == NULL || linked_queue->front == NULL) // 加前半判断防止后半越界
	if (!linked_queue|| !linked_queue->front)
		return true;
	return false;
}

// 入队列
bool enqueue(LinkedQueue* linked_queue, ElemType val) {
	// 若是队列不存在
	if (linked_queue == NULL) {
		printf("queue is not exist.\n");
		exit(-1);
	}
	QueueNode* node = (QueueNode*)calloc(1, sizeof(QueueNode));
	if (node == NULL) {
		printf("malloc failed in enqueue.\n");
		return false;
	}
	node->data = val;
	if (queue_is_empty(linked_queue)) // 如果队列为空
		linked_queue->front = linked_queue->rear = node;
	else {
		linked_queue->rear->next = node;
		linked_queue->rear = node;
		//node->next = NULL; // 冗余，初始化已置零
	}
	return true;
}

// 出队列并返回队首元素
ElemType dequeue(LinkedQueue* linked_queue) {
	if (queue_is_empty(linked_queue)) {
		printf("queue is empty.\n");
		exit(-1);
	}
	ElemType val = linked_queue->front->data;
	QueueNode* p = linked_queue->front;
	linked_queue->front = p->next;
	free(p);
	if (queue_is_empty(linked_queue))
		linked_queue->rear = NULL;
	return val;
}

// 访问队首元素
ElemType queue_peek(LinkedQueue* linked_queue) {
	if (queue_is_empty(linked_queue)) {
		printf("queue is empty.\n");
		exit(-1);
	}
	return linked_queue->front->data;
}