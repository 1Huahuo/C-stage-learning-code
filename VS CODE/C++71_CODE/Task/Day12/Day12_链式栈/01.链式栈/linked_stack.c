#include "linked_stack.h"

// ----------------------链式栈没有必要用头结点----------------------
// 创建链式栈
LinkedStack* stack_create() {
	LinkedStack* linked_stack = (LinkedStack*)calloc(1, sizeof(LinkedStack)); // 直接置零
	if (linked_stack == NULL) {
		printf("malloc failed in stack_create\n");
		return NULL;
	}
	return linked_stack;
}

// 销毁链式栈
void stack_destroy(LinkedStack* linked_stack) {
	if (linked_stack == NULL) // 防止下面while判断条件中越界
		return;

	while (linked_stack->top != NULL){
		StackFrame* p = linked_stack->top;
		linked_stack->top = linked_stack->top->next;
		free(p);
	}
	free(linked_stack);
}

// 判空
bool stack_is_empty(LinkedStack* linked_stack) {
	if (linked_stack == NULL || linked_stack->top == NULL)
		return true;
	return false;
}

// 入栈/压栈
void stack_push(LinkedStack* linked_stack, ElemType val) {
	StackFrame* node = (StackFrame*)calloc(1, sizeof(StackFrame));
	if (node == NULL) {
		printf("malloc failed in stack_push.\n");
		return;
	}
	node->data = val;
	node->next = linked_stack->top;
	linked_stack->top = node;
}

// 出栈并返回栈顶元素
ElemType stack_pop(LinkedStack* linked_stack) {
	if (stack_is_empty(linked_stack)) { // 栈若为空
		printf("linked_stack is empty.\n");
			exit(-1);
	}

	ElemType val = linked_stack->top->data;
	StackFrame* p = linked_stack->top;
	linked_stack->top = p->next;
	free(p);
	return val;
}

// 访问栈顶元素
ElemType stack_peek(LinkedStack* linked_stack) {
	if (stack_is_empty(linked_stack)) {
		printf("linked_stack is empty.\n");
		exit(-1);
	}
	return linked_stack->top->data;
}