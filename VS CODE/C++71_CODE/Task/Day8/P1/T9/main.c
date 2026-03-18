#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
定义一个枚举类型Month（别名），包含一年中12个月份的英文单词。并从一月份开始，为枚举成员分配一个从1开始的数字值。

例如：JANUARY=1，FEBRUARY=2，依此类推....

编写一个函数，接收Month类型的参数，返回该月份有多少天。

注意：

不考虑平年闰年，2月份一律输出28天。

不要把12个case分支做12个处理，那也太笨了！

枚举值应当采用英文单词字母全部大写的命名风格，类似宏定义。
*/

enum month_trans {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

// 注意：接收Month类型的参数
int how_many_days(enum month_trans month) { // <——int month
	if (month < 1 || month > 12)
		return 0;
	if (month == 2) // if (month == FEBRUARY)
		return 28;
	// (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
	// 法②：
	// 采用switch
	//switch (month) {
	//case FEBRUARY:
	//	return 28;
	//case APRIL:
	//case JUNE:
	//case SEPTEMBER:
	//case NOVEMBER:
	//	return 30;
	//default:
	//	return 31;
	//}
	// 法③：
		//               1   2   3   4   5   6   7   8   9  10  11  12
	//int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//if (month < JANUARY || month > DECEMBER)
	//	return 0;
	//return days[month];
}

int main(void) {
	enum month_trans mon = FEBRUARY;
	printf("February has %d days.\n", how_many_days(mon));
}