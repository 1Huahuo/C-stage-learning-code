#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node* next;
}Node;
typedef struct {
	Node* head;
	Node* tail;
	int size;
}LinkedList;

// 创建一个空的链表
LinkedList* create_linked_list();
// 销毁链表
void destroy_linked_list(LinkedList* linked_list);
// 头插法 —— 最好为布尔型
bool insert_head(LinkedList* linked_list, DataType new_val);
// 尾插法 —— 最好为布尔型
bool insert_tail(LinkedList* linked_list, DataType new_val);
// 根据索引插入一个结点
bool insert_by_index(LinkedList* linked_list, int index);
// 根据索引搜索一个结点
Node* search_by_index(LinkedList* linked_list, int index);
// 根据数据搜索一个结点
Node* search_by_val(LinkedList* linked_list, DataType val);
// 根据数据删除一个结点
bool delete_by_val(LinkedList* linked_list, DataType val);
// 根据索引删除一个结点
bool delete_by_index(LinkedList* linked_list, int index);
// 打印链表 格式为：1 -> 2 -> 3 ->..
void print_linked_list(LinkedList* linked_list);
// 判断链表是否有环
bool is_has_loop(LinkedList* linked_list);
// 查找中间结点的值
DataType get_mid_val(LinkedList* linked_list); 

#endif // !LINKED_LIST_H

