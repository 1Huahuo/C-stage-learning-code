#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	编写一个程序实现一个简单的计算器，能够处理加法、减法、乘法和除法。
	输入：用户输入两个数字(可以带小数)和一个操作符（+、-、*、/）。
	输出：显示计算的表达式及结果。
	注意以下几个要求：
	1. 代码可以直接写在main函数里，不需要提取函数。
	2. 输入的表达式应当符合格式要求，应当正常录入两个操作数和一个运算符，否则直接退出程序。
	3. 在进行除法操作时，需要保证除数不为0，若除数为0，则直接退出程序。
*/

int main(void) {
	printf("请输入需要计算的表达式（例如：12.7 + 3.5）：");
	double operand1, operand2;
	char op;
	scanf("%lf %c %lf", &operand1, &op, &operand2);
	double res;
	switch (op) {
	case '+':
		res = operand1 + operand2;
		break;
	case '-':
		res = operand1 - operand2;
		break;
	case '*':
		res = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0) {
			printf("Error：除数为0！\n");
			return 0;
		}
		res = operand1 / operand2;
		break;
	}

	printf("计算的结果是：%.2lf %c %.2lf = %.2lf\n", operand1, op, operand2, res);

	return 0;
}