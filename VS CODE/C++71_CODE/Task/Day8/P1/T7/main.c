#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
定义一个Date结构体，包含年、月、日数据项。编写一个函数，计算两个日期之间的天数差。
不考虑平年闰年，不考虑月份天数不同。
假设每个月都是30天，每年是360天，以简化计算。
*/

struct Date {
	int year;
	int month;
	int day;
};

int days_difference(struct Date st1, struct Date st2) {
	// 基准：公元0年1月0日
	//int days1 = st1.year * 360 + (st1.month - 1) * 30 + st1.day;
	//int days2 = st2.year * 360 + (st2.month - 1) * 30 + st2.day;
	// 基准：公元0年0月0日
	int days1 = st1.year * 360 + st1.month * 30 + st1.day;
	int days2 = st2.year * 360 + st2.month * 30 + st2.day;
	// 上面两种形式效果相同没有区别，因为只要基准一样，那么真实差值也一样

	return days1 > days2 ? days1 - days2 : days2 - days1;
}

int main(void) {
	struct Date st1, st2;
	printf("请分别输入日期一的年月日：");
	scanf("%d %d %d", &st1.year, &st1.month, &st1.day);
	printf("请分别输入日期二的年月日：");
	scanf("%d %d %d", &st2.year, &st2.month, &st2.day);

	printf("两日期之间的天数差是：%d\n", days_difference(st1, st2));
}