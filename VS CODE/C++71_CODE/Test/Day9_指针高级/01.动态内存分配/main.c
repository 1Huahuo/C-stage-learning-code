#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*

*/

void test1() {
	// 局部变量存储在栈帧中的。 
	int num = 10;
	int arr[10];
}


void test2() {
	int len = 80;
	//int arr[80]; 局部变量，函数结束直接消失
	int* arr = malloc(len * sizeof(int)); // 手动释放之前一直存活
	if (arr == NULL) {
		printf("malloc failed.\n");
		return;
	}
	for (int i = 0; i < 80; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 80; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
}

void test3() {
	// 动态内存分配，其实就是使用一系列的函数
	// 来从 堆区 申请内存
}

int main(void) {
	

	printf("1\n");
}