#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_CAPACITY 10

typedef char ElemType;
typedef struct node_s {
	ElemType* data; // 指向动态数组首元素的指针
	int size; // 本质top 当前栈中元素的个数——即小标对应栈顶指针，指向下一次入栈的位置
	int	capacity; // 动态数组的当前最大容量
}DynamicStack;

// 创建动态数组栈
DynamicStack* stack_create();
// 销毁动态数组栈
void stack_destroy(DynamicStack* s);
// 扩容
void grow_capacity(DynamicStack* s);
// 判空
bool stack_is_empty(DynamicStack* s);
// 入栈
void stack_push(DynamicStack* s, ElemType val);
// 出栈并返回栈顶元素
ElemType stack_pop(DynamicStack* s);
// 访问栈顶元素
ElemType  stack_peek(DynamicStack* s);

#endif // !DYNAMIC_STACK_H
