#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/*
编写函数实现以下功能：
键盘录入一个正整数，请判断它是否是一个素数，然后控制台输出对应的结果。
要对键盘录入的数据做参数校验，素数是一个大于1的自然数，它仅能被1和自身整除。

键盘录入两个整数：底(base)和幂指数(exponent)，计算base的exponent次幂，并打印输出对应的结果。（注意底和幂指数都可能是负数）
提示：求幂运算时，基础的思路就是先无脑把指数转换成正数，然后累乘，最后再根据指数是否是负数决定是否取倒数。
*/

//判断是否为素数
bool is_prime_number(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

//求幂——有待优化，特别是求幂的算法
double power(int base, int exponent) {
	double res = 1;
	int exponent_abs = abs(exponent);
	if (exponent == 0)
		return 1;

	if (base == 0) {
		if (exponent > 0)
			return 0;
		else {
			printf("此次幂运算不合法。\n");
			exit(1);
		}
	}

	while (exponent_abs--)
		res *= base;

	if (exponent > 0)
		return res * (base > 0 ? 1 : (exponent % 2 == 0 ? 1 : -1));
	else
		return 1 / res * (base > 0 ? 1 : (exponent % 2 == 0 ? 1 : -1));


}

int main(void) {
	int num;
	printf("请输入一个正整数:");
	scanf("%d", &num);
	if (num <= 1) {
		printf("输入不合法!\n");
		exit(1);
	}

	if (is_prime_number(num))
		printf("是一个素数。\n");
	else
		printf("不是一个素数。\n");
	//---------------------------------------------------------------
	printf("\n\n\n");
	//---------------------------------------------------------------
	printf("请分别输入所求幂的底和指数：");
	int base, exponent;
	scanf("%d %d", &base, &exponent);

	printf("%d的%d次幂是：%lf\n", base, exponent, power(base, exponent));

	return 0;
}