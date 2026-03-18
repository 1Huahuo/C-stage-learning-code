#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

/*
用C语言编写程序实现以下需求：

编写一个函数，输入一个公元年份（如2004），判断该年是否为闰年，并返回判断结果。

平年闰年的规则如下：

如果年份不是4的倍数，则是平年。
如果年份是4的倍数但不是100的倍数，则是闰年。
如果年份是100的倍数但不是400的倍数，则是平年。
如果年份是400的倍数，则是闰年。
要求使用bool类型作为函数的返回值。
*/

bool is_leap_year(int year1) {
	if (year1 % 400 == 0 || (year1 % 4 == 0 && year1 % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int year;
	printf("输入一个公元年份（如2004）：\n");
	scanf("%d", &year);


	if (is_leap_year(year)) {
		printf("公元%d年是一个闰年\n", year);
	}
	else {
		printf("公元%d年是一个平年\n", year);

	}

	return 0;
}