#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
定义一个函数，判断某个整数是否为奇数。
*/

int is_odd(int num) {
	if (num % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	int num;
	printf("Please enter a number:\n");
	scanf("%d", &num);
	if (is_odd(num)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}