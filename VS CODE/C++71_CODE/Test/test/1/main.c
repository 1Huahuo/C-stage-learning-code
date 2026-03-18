#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
// 虚拟内存： 虚拟的内存。 相对的是物理内存。
// 程序运行过程中看到的内存都是虚拟的内存地址。
// 1.进程间隔离更容易。
// 2.内存碎片问题
// 3.程序员管理内存麻烦
*/

int main(void) {
	//int matrix[5][5] =
	//{ {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	//printf("%d\n", *(*(matrix + 2) + 3));

	
	int num = 10;
	int num2 = 20;
	int* p1 = &num;
	// 改变p1的指向。 
	p1 = &num2;
	// 二级指针，就是指针的指针。 也就是，存储指针地址的
	int** pp1 = &p1;
	*pp1 = &num2; // p1 = &num2

	//char str[5];
	//scanf("%4s", str);
	//printf("%s\n", str);
	//"hello"[0] = 'H';
	return 0;
}