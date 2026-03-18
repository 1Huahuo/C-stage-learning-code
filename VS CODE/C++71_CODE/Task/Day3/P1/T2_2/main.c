#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定一个正整数，请定义一个函数判断它是否为2的幂(1, 2, 4, 8, 16, ....)。
*/

is_2_power(int num) {
	return (num & num - 1) == 0;
}

int main(void) {
	int num;
	printf("Please enter a number:\n");
	scanf("%d", &num);
	if (is_2_power(num)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}