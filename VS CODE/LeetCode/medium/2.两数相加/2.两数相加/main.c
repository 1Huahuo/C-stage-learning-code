#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = NULL, * tail = NULL;
	int sum = 0, carry = 0;
	while (l1 || l2) {
		int a = l1 != NULL ? l1->val : 0;
		int b = l2 != NULL ? l2->val : 0;
		sum = a + b + carry;
		//if (sum == 0) {	处理错误,和为0不需要进行特殊处理，应当做一般情况
		if (head == NULL) {
			head = tail = malloc(sizeof(struct ListNode));
			tail->val = sum % 10;
			tail->next = NULL;
		}
		else {
			tail->next = malloc(sizeof(struct ListNode));
			tail = tail->next;
			tail->val = sum % 10;
			tail->next = NULL;
		}
		carry = sum / 10;
		if (l1 != NULL) {
			l1 = l1->next;
		}
		if (l2 != NULL) {
			l2 = l2->next;
		}
	}
	if (carry > 0)
	{
		tail->next = malloc(sizeof(struct ListNode));
		tail->next->val = carry;
		tail->next->next = NULL;
	}
	return head;
}

int main(void) {


	printf("Hello world!\n");

	return 0;
}