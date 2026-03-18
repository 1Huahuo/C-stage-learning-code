#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	写一个程序，实现分数相加。用户以分子/分母的形式输入分数，程序打印相加后的结果(化为最简分数)。
*/

int main(void) {
	int dividend1, dividend2, divisor1, divisor2;
	printf("请输入第一个分数（分子/分母）：\n");
	scanf("%d/%d", &dividend1, &divisor1);
	printf("请输入第二个分数（分子/分母）：\n");
	scanf("%d/%d", &dividend2, &divisor2);

	dividend1 = dividend1 * divisor2 + dividend2 * divisor1;
	divisor1 *= divisor2;

	int t, a = dividend1, b = divisor1;
	while (b > 0) {
		t = a % b;
		a = b;
		b = t;
	}
	int dividend = dividend1 / a;
	int divisor = divisor1 / a;

	if (divisor == 1) {
		printf("两个分数的和是一个整数，即：%d\n", dividend);
	}
	else {
		printf("两个分数的和是一个分数，即：%d/%d\n", dividend, divisor);
	}

	return 0;
}