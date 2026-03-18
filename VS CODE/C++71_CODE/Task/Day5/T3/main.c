#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define a operand1
#define b operand2

/*
要求至少提供四种运算加减乘除，如下：

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
并且在结束进程时，打印总共执行操作的次数。（也就是这些函数调用的次数）
注意：除法的实现，要求判断除数不为0，并且在除数为0时使用exit表示异常退出进程。
要求：需要编写一个函数，用于随时随地打印当前操作的执行次数，也就是打印上述四个函数的调用次数。
思考一下：这个变量应该设置为什么变量呢？
*/

int count = 0;

int add(int a, int b) {
	count++;
	return a + b;
}

int subtract(int a, int b) {
	count++;
	return a - b;
}

int multiply(int a, int b) {
	count++;
	return  a * b;
}
float divide(int a, int b) {
	if (b == 0)
		exit(1); // #include <stdlib.h>
	else {
		count++;
		return (float)a / b;
	}

}

int main(void) {
	int operand1, operand2, is_continue = 1;
	char op;

	while (is_continue) {
		printf("请输入要计算的表达式（例如，5 + 3）：");
		scanf("%d %c%d", &operand1, &op, &operand2);
		while (getchar() != '\n');
		switch (op) {
		case '+':
			printf("结果：%d\n", add(a, b));
			break;
		case '-':
			printf("结果：%d\n", subtract(a, b));
			break;
		case '*':
			printf("结果：%d\n", multiply(a, b));
			break;
		case '/':
			printf("结果：%.2f\n", divide(a, b));
			break;
		default:
			printf("无效的运算符。\n");
			break;
		}

		printf("是否继续？（y/n）：");
		char c;
		scanf("%c", &c);
		printf("\n");
		if (c == 'y' || c == 'Y')
			is_continue = 1;
		else {
			is_continue = 0;
			printf("总共执行的次数为：%d次\n", count);
		}
	}

	return 0;
}