#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

struct ListNode {
	int val;
	struct ListNode* next;
};


// 优化后的
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy = { 0, head };
    struct ListNode* p0 = &dummy;
    struct ListNode* cur = p0->next;
    struct ListNode* pre = NULL;

    int list_size = 0;
    // struct ListNode* test = head;
    // while (test != NULL) { // 可优化，改为for循环
    // 	test = test->next;
    // 	list_size++;
    // }
    // int sublist_num = list_size / k;
    for (struct ListNode* p = head; p; p = p->next)
        list_size++;

    // int count = 0;
    // while (sublist_num) { // 可优化，改为两个嵌套的for循环
    // 	struct ListNode* next = cur->next;
    // 	cur->next = pre;
    // 	pre = cur;
    // 	cur = next;
    // 	count++;
    // 	if (count == k) {
    // 		count = 0;
    // 		sublist_num--;
    // 		struct ListNode* temp = p0->next;
    // 		p0->next->next = cur;
    // 		p0->next = pre;
    // 		p0 = temp;
    // 	}
    // }
    for (; list_size >= k; list_size -= k) {
        for (int i = 0; i < k; i++) {
            struct ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        struct ListNode* temp = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = temp;
    }

    return dummy.next;
}

int main(void) {
	struct ListNode node1;
	struct ListNode node2;
	struct ListNode node3;
	struct ListNode node4;
	struct ListNode node5;
	node1.val = 1;
	node2.val = 2;
	node3.val = 3;
	node4.val = 4;
	node5.val = 5;

	struct ListNode* head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;
	struct ListNode* head_new = reverseKGroup(head, 2);

	while (head_new != NULL) {
		printf("%d\n", head_new->val);
		head_new = head_new->next;
	}
	
	//printf("1\n");

	return 0;
}