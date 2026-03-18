#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
编写一个程序实现以下需求：

用户键盘录入一整行字符数据，包含数字和字母。

当用户按下回车键后结束数据录入。

请统计用户输入的一整行字符数据中，数字和字母分别有多少个。
*/

int main(void) {
	char ch;
	int letters = 0, numbers = 0;

	while ((ch = getchar()) != '\n') {
		if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A')) {
			letters++;
		}
		if (ch <= '9' && ch >= '0') {
			numbers++;
		}
	}

	printf("字母数：%d，数字数：%d\n", letters, numbers);

	return 0;
}