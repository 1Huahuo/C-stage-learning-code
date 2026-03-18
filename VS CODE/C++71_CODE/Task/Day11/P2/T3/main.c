#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
给定一条单链表，请反转这条单链表。
举例，
输入: 1 --> 2 --> 3
输出: 3 --> 2 --> 1
基于以下函数的声明实现：
Node* reverse(Node *list); // 反转当前单链表并返回新的头指针
*/

typedef int DataType;
typedef struct node {
	DataType data;
	struct node* next;
} Node;

// 实现尾插法构建链表
void insert_tail(Node** head, int new_data) {
	// 1.分配新结点，初始化它
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("error: malloc failed in insert_tail.\n");
		exit(1);
	}
	new_node->data = new_data;
	new_node->next = NULL;
	// 3.链表非空时,让原本最后一个结点指向新结点
	if (*head != NULL) {
		// 2.遍历找到最后一个结点
		Node* end = *head;
		while (end->next != NULL) {
			end = end->next;
		} // while循环结束时, end指向最后一个结点
		end->next = new_node;
		return;
	}
	// 链表尾插之前是空的,那就直接更新头指针就行了
	*head = new_node;
}

Node* reverse(Node* list) {
	if (list == NULL || list->next == NULL) // 出口
		return list;

	// 递归操作
	Node* head = reverse(list->next); // 这个问题需要先递归后操作
	list->next->next = list;
	list->next = NULL; // 暂时先使当前子链表的尾结点指向NULL，能保证最终完整的尾结点也指NULL

	return head; // 返回值
}

int main(void) {
	Node* head = NULL;

	//insert_tail(&head, 0);
	//Node* tail = head;
	//for (int i = 1; i < 5; i++) {
	//	insert_tail(&head, i); // 注意函数中要的是Node**，而此时head为Node*，所以要取次地址
	//	tail = tail->next;
	//} // 此时tail指向下标为4的结点
	//Node* p = tail; // 将此时的tail保存下来，tail继续指向尾结点
	//for (int i = 5; i < 10; i++) {
	//	insert_tail(&head, i);
	//	tail = tail->next;
	//}

	for (int i = 0; i < 10; i++)
		insert_tail(&head, i);
	head = reverse(head);
	Node* p1 = head;
	for (int i = 0; i < 9; i++) {
		printf("%d --> ", p1->data);
		p1 = p1->next;
	}
	printf("%d\n", p1->data);

	for (int i = 0; i < 10; i++) {
		Node* p2 = head;
		head = head->next; // 下面这两行顺序一定不能错，此时p2和head还指向同一个结点
		free(p2);
	}
	return 0;
}