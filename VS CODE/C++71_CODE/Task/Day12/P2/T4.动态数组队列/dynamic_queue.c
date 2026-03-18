#include "dynamic_queue.h"

// 创建动态数组队列
DynamicQueue* create_queue() {
    DynamicQueue* q = calloc(1, sizeof(DynamicQueue));
    if (q == NULL) {
        printf("error: calloc failed in create_queue.\n");
        return NULL;
    }
    
    q->data = calloc(DEFAULT_CAPACITY, sizeof(ElemType));    // 使用calloc直接置零
    if (q->data == NULL) {
        printf("calloc failed in create_queue.\n");
        free(q);
        return NULL;
    }
    q->capacity = DEFAULT_CAPACITY;
    return q;
}

// 销毁队列
void destroy_queue(DynamicQueue* q) {
    free(q->data);
    free(q);
}

// 扩容
static bool resize_queue(DynamicQueue* q) {
    int old_capacity = q->capacity;
    int new_capacity = (old_capacity < THRESHOLD) ? 
        (old_capacity << 1) : (old_capacity + (old_capacity >> 1));

    // 重新分配一个新的,更长的动态数组
    ElemType* new_data = malloc(new_capacity * sizeof(ElemType));
    if (new_data == NULL) {
        printf("realloc failed in resize_queue.\n");
        return false;
    }

    int curr = q->front;    // curr索引用于遍历整个队列中的元素
    int index = 0;
    while (index < q->size) {
        new_data[index] = q->data[curr];
        curr = (curr + 1) % q->capacity;
        index++;
    } // while循环结束时,new_data就从头开始包含了队列的所有元素 
    free(q->data);
    q->data = new_data;
    q->front = 0;
    q->rear = q->size;
    q->capacity = new_capacity;
    return true;
}

// 检查队列是否为空
bool is_empty(DynamicQueue* q) {
    return q->size == 0;
}

// 检查队列是否已满
bool is_full(DynamicQueue* q) {
    return q->size == q->capacity;
}

// 入队操作
bool enqueue(DynamicQueue* q, ElemType data) {
    if (is_full(q)) {
        if (!resize_queue(q)) {
            printf("resize failed.\n");
            return false;
        }
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->capacity;  // 循环队列
    q->size++;
    return true;
}

// 出队操作
ElemType dequeue(DynamicQueue* q) {
    if (is_empty(q)) {
        printf("queue is empty.\n");
        exit(1);
    }
    ElemType item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity; // 循环队列
    q->size--;
    return item;
}

