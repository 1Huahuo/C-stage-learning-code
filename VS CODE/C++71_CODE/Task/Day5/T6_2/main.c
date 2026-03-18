#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
(2) 十进制转换成二进制
给定任意一个非负十进制整数，请利用递归的方式，求解它的二进制表示方式
基本的思路是：把该整数除以2得到余数，然后倒着输出余数。
思考一下：如何实现倒着打印余数呢？
*/

void trans_binary(int x) {
	if (x / 2 == 0) {
		printf("%d", x);
		return;
	}
	int bit = x % 2;
	trans_binary(x / 2);
	printf("%d", bit);
	return;
}

int main(void) {
	int num;
	printf("Please enter a number:");
	scanf("%d", &num);

	printf("%d的二进制形式是:", num);
	trans_binary(num);

	printf("\n");

	return 0;
}