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
	double operand1, operand2;
	char op;
	double res;
	int is_continue = 1;
	do {
		printf("请输入需要计算的表达式（例如：12.7 + 3.5）：");
		int matching_num = scanf("%lf %c %lf", &operand1, &op, &operand2);
		if (matching_num != 3) {
			printf("Error：输入的表达式不合法！请重新输入。\n\n");
			while (getchar() != '\n');	//// 清空缓冲区，避免影响下次输入，仅清空到！第一个！换行符
			continue;
		}

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
				printf("Error：除数为0！请重新输入\n\n");
				continue;
			}
			res = operand1 / operand2;
			break;
		}
		printf("计算的结果是：%.2lf %c %.2lf = %.2lf\n", operand1, op, operand2, res);

		printf("\n是否继续计算？（输入'y/Y'继续，其他任意键结束）：");
		char c;
		//c = getchar();	此时c无法正确读入，因为输入缓冲区中还有'\n'，
		//要么先用getchar()刷新一下 或者 scanf( %c)中在%c前加空格把所有空白字符匹配掉
		while (getchar() != '\n');
		c = getchar();		//scanf(" %c", &c);
		printf("\n");

		if (c != 'y' && c != 'Y') {
			is_continue = 0;
		}
	} while (is_continue);

	return 0;
}