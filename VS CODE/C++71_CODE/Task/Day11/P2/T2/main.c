#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
基于链表的结点定义：
以及相应的二级指针尾插法构建单链表：
后续单链表的面试题，也请基于此链表结点的定义，以及尾插法构建链表实现。
利用快慢指针法，直接求解下列两个问题：
	1.求链表中间结点的值
	2.判断单链表是否有环
注意：
不仅要定义函数实现对应功能，还需要编写测试用例，进行测试。
尤其是测试单链表有环，要自己构建出一条有环的单链表进行测试。
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

DataType get_mid_val(Node* head) { // 查找的话，一级指针就可以了
	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL && fast->next->next != NULL) { // 顺序不能变，因为后半可能会导致越界
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;
}

// 
bool is_has_loop(Node* head) { // 依旧查找，依旧一级指针
	Node* slow = head;
	Node* fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

int main(void) {
	Node node = { 0, NULL };
	Node* head = &node;
	Node* tail = head;;
	for (int i = 1; i < 5; i++) {
		insert_tail(&head, i); // 注意函数中要的是Node**，而此时head为Node*，所以要取次地址
		tail = tail->next;
	} // 此时tail指向下标为4的结点
	Node* p = tail; // 将此时的tail保存下来，tail继续指向尾结点

	for (int i = 5; i < 10; i++) {
		insert_tail(&head, i);
		tail = tail->next;
	}

	//printf("链表中间结点的值是：%d\n", get_mid_val(head));
	
	// 制造环路
	tail->next = p;
	if (is_has_loop(head))
		printf("链表中存在环路\n");
	else
		printf("链表中没有环路\n");

	return 0;
}