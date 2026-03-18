#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
利用二级指针语法实现以下函数：
*/

typedef int ElementType;
typedef struct node {
	ElementType data;
	struct node* next;
} Node;

// 修改第一个结点的元素值，如果链表为空，则用new_val初始化第一个结点
void modify_first_node(Node** head, int new_val) {
	if (*head == NULL) { // 链表为空，初始化第一个结点
		*head = (Node*)malloc(sizeof(Node));
		if (*head == NULL) {
			printf("malloc failed in modify_first_node.\n");
			return;
		}
		(*head)->data = new_val;
		(*head)->next = NULL;
	}
	else { // 链表非空
		(*head)->data = new_val;
	}
}

// 打印单链表 格式为：1 -> 2 -> 3 ->...
void print_list(Node* head) {
	while (head->next != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("%d\n", head->data);
}

// 头插法新增一个结点
void insert_head(Node** head, ElementType new_val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL){
		printf("malloc failed in create a node.\n");
		return;
	}
	node->data = new_val;
	if (*head == NULL) {
		*head = node;
		node->next = NULL;
	}
	else {
		node->next = *head;
		*head = node;
	}
}

// 尾插法新增一个结点
void insert_tail(Node** head, ElementType new_val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("malloc failed in create a node.\n");
			return;
	}
	node->data = new_val;
	if (*head == NULL) {
		*head = node;
		//node->next = NULL;
	}
	else {
		Node *p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = node;
		//node->next = NULL; // 重复则合并
	}
	node->next = NULL;
}

int main(void) {
	Node* head = NULL;

	return 0;
}