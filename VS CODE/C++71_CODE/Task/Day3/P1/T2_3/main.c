#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定一个不为0的整数，编写函数找出它值为1的最低有效位 (称之为Last Set Bit)。LSB是1表示此整数的最低位就是1,
2则表示倒数第二位是第一个1,4表示倒数第三位是第一个1....

一个示例如下：

输入：n = 24

输出：8

解释：24的二进制表示为 11000，值为 1 的最低有效位是倒数第四位，则输出 2^3，即输出的结果8。
*/

int LSB_num(int num) {
	return num & -num;
}

int main(void) {
	int num;
	printf("Please enter a number:\n");
	scanf("%d", &num);
	printf("LSB_num:%d\n", LSB_num(num));

	return 0;
}