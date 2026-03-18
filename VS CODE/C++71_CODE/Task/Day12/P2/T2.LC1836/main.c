#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
给定一个单链表，请编写一个函数来删除链表中所有重复的节点，只保留第一次出现的节点，
注意这里不再强调重复结点连续出现，允许间断出现。
举例：
输入: 1 -> 2 -> 3 -> 2 -> 4 -> 3 -> 5
输出: 1 -> 2 -> 3 -> 4 -> 5
注意：要求在O(n)的时间复杂度内，完成这个问题的求解。
提示：计数去重，这是非常典型的哈希表的应用场景，不妨考虑使用哈希表来完成这个操作。
节点个数范围：[1, 10^5]
节点值范围：1 <= Node.val <= 10^5
*/

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicatesUnsorted(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	int hash[100001] = { 0 }; // 舍弃下标0，下标1...100000分别对应1...100000的出现次数
	int flag[100001] = { 0 }; // 标记下标对应值是否为第一次出现，默认0为第一次出现，1为已经出现
	struct ListNode* cur = head;
	while (cur) {
		hash[cur->val]++;
		cur = cur->next;
	}

	// 若是pre初始化为NULL导致需要特殊处理，那么就加哨兵结点！
	//struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	struct ListNode dummy = {0, head}; // 局部变量也可以，但是不要创建成指针了，指针不对应实体结点
	struct ListNode* pre = &dummy;
	cur = head;

	while (cur) {
		if (hash[cur->val] > 1 && flag[cur->val] == 1) { // 这么一看其实只要1个哈希表就行：flag
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else { // 链表中只出现1次(这个逻辑不重要)或第一次出现——可以归类在一起
			flag[cur->val] = 1;
			pre = cur;
			cur = cur->next;
		}
	}
	head = dummy.next;
	//free(dummy);
	return head;
}

int main(void) {


	printf("1\n");

	return 0;
}