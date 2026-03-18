#include "dynamic_stack.h"

// 创建动态数组栈
DynamicStack* stack_create() {
	DynamicStack* s = (DynamicStack*)calloc(1, sizeof(DynamicStack));
	if (s == NULL) {
		printf("malloc is failed in stack_create.\n");
		return NULL;
	}
	s->data = (ElemType*)calloc(STACK_CAPACITY, sizeof(ElemType));
	if (s->data == NULL) {
		printf("malloc is failed in stack_create.\n");
		free(s);
		return NULL;
	}
	s->capacity = STACK_CAPACITY;
	return s;
}

// 销毁动态数组栈
void stack_destroy(DynamicStack* s) {
	if (s == NULL)
		return;
	if (s->data != NULL)
		free(s->data);
	free(s);
}

// 扩容
void grow_capacity(DynamicStack* s) {
	if (s == NULL)
		return;
	ElemType* p = (ElemType*)realloc(s->data, 2 * s->capacity * sizeof(ElemType));
	if (p == NULL) {
		printf("malloc failed in grow_capacity.\n");
		return;
	}
	s->capacity *= 2;
	s->data = p;
}

// 入栈
void stack_push(DynamicStack* s, ElemType val) {
	if (s == NULL)
		return;

	// !size指向要入栈的位置，栈顶指针
	if (s->size == s->capacity) // 栈已满
		grow_capacity(s);
	s->data[s->size] = val;
	s->size++;
}

// 判空
bool stack_is_empty(DynamicStack* s) {
	if (s == NULL)
		return true;
	if (s->size == 0)
		return true;
	else
		return false;
}

// 出栈并返回栈顶元素
ElemType stack_pop(DynamicStack* s) {
	if (s == NULL)
		exit(-1);
	if (stack_is_empty(s)) {
		printf("stack is empty.\n");
		exit(-1);
	}
	s->size--;
	return s->data[s->size];
}

// 访问栈顶元素
ElemType  stack_peek(DynamicStack* s) {
	if (s == NULL)
		exit(-1);
	if (stack_is_empty(s)) {
		printf("stack is empty.\n");
		exit(-1);
	}
	return s->data[s->size - 1];
}
