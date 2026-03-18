#include "linkedlist.h"

// 创建一个空的链表
LinkedList* create_linked_list() {
	LinkedList* linked_list = (LinkedList*)calloc(1, sizeof(LinkedList)); //calloc更省事
	if (linked_list == NULL) {
		printf("calloc failed in create_linked_list.");
		return NULL;
	}
	// 下面三行语句完全可以在上面用calloc代替
	//linked_list->head = NULL;
	//linked_list->tail = NULL;
	//linked_list->size = 0;
	return linked_list;
}


// 销毁链表
void destroy_linked_list(LinkedList* linked_list) {
	if (linked_list == NULL) // 若不提前返回，则会执行下面的NULL->head造成越界访问
		return;

	if (linked_list->head == NULL) {
		free(linked_list);
		return;
	}
	while (linked_list->head) { //结点不空一直向后释放结点
		Node* t = linked_list->head;
		linked_list->head = linked_list->head->next;
		free(t);
	}
	free(linked_list);
}

// 头插法
bool insert_head(LinkedList* linked_list, DataType new_val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("malloc failed in create a node.\n");
		return false;
	}

	node->data = new_val;

	if (linked_list->head == NULL) {
		linked_list->head = node;
		linked_list->tail = node;
		node->next = NULL;
	}
	else {
		node->next = linked_list->head;
		linked_list->head = node;
	}
	linked_list->size++;

	return true;
}

// 尾插法
bool insert_tail(LinkedList* linked_list, DataType new_val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("malloc failed in create a node.\n");
		return false;
	}

	node->data = new_val;

	if (linked_list->head == NULL) {
		linked_list->head = node;
		linked_list->tail = node;
		//node->next = NULL;
	}
	else {
		//Node* p = linked_list->head;
		//while (p->next != NULL)
		//	p = p->next;
		//p->next = node;
		linked_list->tail->next = node;
		linked_list->tail = node;
		//node->next = NULL; // 重复则合并
	}
	node->next = NULL; // 公共语句，给新的尾结点后面链接NULL
	linked_list->size++;

	return true;
}

// 根据索引插入一个结点
bool insert_by_index(LinkedList* linked_list, int index, DataType new_val) {
	// 1.索引越界检查
	if (index < 0 || index > linked_list->size) { // 和数组的按索引插入同理，index合法范围:0...size
		printf("index out of bounds in insert_by_index.\n");
		return false;
	}

	// 2.边界值处理
	if (index == 0)
		return insert_head(linked_list, new_val);
	if (index == linked_list->size)
		return insert_tail(linked_list, new_val);

	// 3.正常情况处理即在中间插入结点
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("malloc failed in create a node.\n");
		return false;
	}
	Node* pre = linked_list->head;
	//while (index--)
	//	p = p->next;
	//// 由于index是索引，此时p正好指向下标为index的结点，所以可插入其后再交换值来实现插入
	//node->next = p->next;
	//p->next = node;
	//node->data = p->data;
	//p->data = new_val;
	// 少移动一次直接指向索引前一个结点，插入更简单
	//while (index > 1) // 下面的改进可读性更强
	while (--index) // 想少循环一次就用--count 循环count次就用count--
		pre = pre->next;
	node->next = pre->next;
	pre->next = node;
	node->data = new_val;
	linked_list->size++;

	return true;
}

// 根据索引搜索一个结点
Node* search_by_index(LinkedList* linked_list, int index) {
	if (index < 0 || index >= linked_list->size) {
		printf("index out of bounds int search_by_index.\n");
		return NULL;
	}

	Node* cur = linked_list->head;
	while (index--)
		cur = cur->next;

	return cur;

}

// 根据数据搜索一个结点
Node* search_by_val(LinkedList* linked_list, DataType val) {
	Node* cur = linked_list->head;
	while (cur && cur->data != val)
		cur = cur->next;
	if (cur == NULL) {
		printf("the val is not exist.\n");
		return NULL;
	}
	return cur;
}

// 根据数据删除一个结点
bool delete_by_val(LinkedList* linked_list, DataType val) {
	Node* cur = linked_list->head;
	Node* pre = NULL;
	while (cur && cur->data != val) {
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL) // 未找到对应结点
		return false;

	// 删除的是头结点
	if (cur == linked_list->head) {
		linked_list->head = cur->next;
		if (cur->next == NULL) // 若此时只有一个结点，需更新尾指针
			linked_list->tail = NULL;
		//free(cur);
	}
	// 删除的是尾结点
	else if (cur->next == NULL) {
		linked_list->tail = pre;
		pre->next = NULL;
		//free(cur);
	}
	else // 正常情况
		pre->next = cur->next;
	free(cur);
	linked_list->size--;
	return true;
}

// 根据索引删除一个结点
bool delete_by_index(LinkedList* linked_list, int index) {
	if (index < 0 || index >= linked_list->size)
		return false;
	Node* cur = linked_list->head;
	Node* pre = NULL;
	int count = index;
	while (count--) { // 同时维护pre与cur指针能应对所有情况，此时可将while放在最上公共部分
		pre = cur;
		cur = cur->next;
	} // 由于后面全需要index判断，所以index值不能动，应该用一个变量代替他计数
	if (index == 0) { // 删除头结点
		linked_list->head = cur->next;
		if (cur->next == NULL) // 若此时只有一个结点，需更新尾指针
			linked_list->tail = NULL;
		//free(cur);
	}
	else if (index == linked_list->size - 1) { // 删除尾结点
		linked_list->tail = pre;
		pre->next = NULL;
		//free(cur);
	}
	else { // 正常情况
		pre->next = cur->next;
		//free(cur);
	}
	free(cur);
	return true;
}

// 打印链表 格式为：1 -> 2 -> 3 ->..
void print_linked_list(LinkedList* linked_list) {
	Node* head = linked_list->head;
	while (head->next != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("%d\n", head->data);
}

// 判断链表是否有环
bool is_has_loop(LinkedList* linked_list) { // 依旧查找，依旧一级指针
	Node* head = linked_list->head;
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

// 查找中间结点的值
DataType get_mid_val(LinkedList* linked_list) {
	Node* head = linked_list->head;
	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL && fast->next->next != NULL) { // 顺序不能变，
															 // 因为后半可能会导致越界
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;
}