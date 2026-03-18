#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct node_s {
	ElemType data;
	struct node_s* next;
}StackFrame;
typedef struct {
	StackFrame* top; // 栈顶指针，直接指向栈顶元素，不要加头结点
}LinkedStack;

// 创建链式栈
LinkedStack* stack_create();
// 销毁链式栈
void stack_destroy(LinkedStack* linked_stack);
// 判空
bool stack_is_empty(LinkedStack* linked_stack);
// 入栈/压栈
void stack_push(LinkedStack* linked_stack, ElemType val);
// 出栈并返回栈顶元素
ElemType stack_pop(LinkedStack* linked_stack);
// 访问栈顶元素
ElemType stack_peek(LinkedStack* linked_stack);

#endif // !LINKED_STACK_H
