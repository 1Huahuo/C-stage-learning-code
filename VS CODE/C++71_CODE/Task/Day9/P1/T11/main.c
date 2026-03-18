#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
编写程序，从键盘输入输入中读取一个整数n，动态分配一个长度为n的整型数组。
将数组元素初始化为1, 2, 3, ..., n，并输出打印数组内容，最后释放内存。
注意:
	初始化内存块时可以直接使用下标来操作内存块。
	遍历打印数组元素取值时，请使用指针来实现操作。
非常简单且基础的语法练习题，如果还不太会做，不妨直接查看参考代码。
*/

int main(void) {
	int n;
	printf("enter the number of elements in the array:");
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		printf("a[0]=%d\n", *(a + i));
	}

	free(a);
	a = NULL;
	return 0;
}