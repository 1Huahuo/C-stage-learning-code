#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定两个不同的整数 a 和 b，请交换它们两个的值。（不要定义函数来实现，直接在main函数里实现）
*/

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	a = a + b;
	b = a - b;
	a = a - b;

	printf("a:%d,b:%d\n", a, b);

	return 0;
}