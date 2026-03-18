#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
在main函数中定义两个局部变量：
int a = 10;
int b = 20;
请实现以下两个函数，用于完成局部变量a和b的交换：
	void swap(int *pa, int *pb);
	void swap2(int **pa, int **pb);
这两个函数都应该可以实现交换a和b的值。
*/

void swap(int* pa, int* pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

void swap2(int** pa, int** pb) {
	int t = **pa;
	**pa = **pb;
	**pb = t;
}

int main(void) {
	int a = 1, b = 0;
	printf("a = %d, b = %d\n", a, b);
	//swap(&a, &b);
	int* pa = &a, * pb = &b;
	swap2(&pa, &pb);
	printf("new_a = %d, new_b = %d\n", a, b);

	return 0;
}