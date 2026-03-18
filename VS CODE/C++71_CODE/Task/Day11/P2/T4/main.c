#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
合并两条有序的单向链表，使得合并后的链表也是有序的 (要求: 不能额外申请堆内存空间)。
输入：
   list1: 1 --> 3 --> 5
   list2: 2 --> 4 --> 6
输出：
   1 --> 2 --> 3 --> 4 --> 5 -->6
函数声明可以直接写:
Node* merge_two_lists(Node* list1, Node* list2);
*/

typedef int DataType;
typedef struct node {
	DataType data;
	struct node* next;
} Node;

Node* merge_two_lists(Node* list1, Node* list2) {
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	if (list1->data < list2->data) {
		list1->next = merge_two_lists(list1->next, list2);
		return list1;
	}
	list2->next = merge_two_lists(list1, list2->next);
	return list2;
}

int main(void) {


	printf("1\n");

	return 0;
}