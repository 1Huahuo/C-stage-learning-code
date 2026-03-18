#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	键盘输入一个位于(0, 1)范围内的浮点数，并将其转化为百分比形式，
	结果保留一位小数。例如：输入0.12转换为12.0%，而输入0.1234转换为12.3%。
*/
int main(void) {
	printf("输入一个位于(0, 1)范围内的浮点数：\n");
	float score;
	scanf("%f", &score);
	score *= 100;

	printf("其百分比形式为：%.1f%\n", score);

	return 0;
}