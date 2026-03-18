#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define years 10
/*
固定投资的初始资金是100元，用户先输入年利率（rate）和要投资的年份（years）
投资收益后的资产每年计算一次，随后此程序将打印此利率在投资年份内每年的资产总价值，和紧随其后的4个更高的利率（总计5个利率）下投资的总价值。
余额考虑复利，第一年的余额是(本金 + 本金 * 利率)，第二年则可以在第一年余额的基础上累加(本金 * 利率)。
*/

int main(void) {
	double capital[6];	//不同利率下的本金数组
	for (int i = 1; i < 6; i++)
		capital[i] = 100;	
	int rate, years;
	double rates[6];	//不同利率

	printf("请输入年利率：");
	scanf("%d", &rate);
	printf("请输入要投资的年份：");
	scanf("%d", &years);
	printf("\nYears       6%%        7%%        8%%        9%%       10%%\n");
	//初始化利率数组
	for (int i = 1; i < 6; i++)
		rates[i] = 0.01 * rate + 0.01 * (i-1);
	
	//两层循环嵌套，一个外层对应一年的五个利率下的本金——可用二维数组优化？
	//double capital[years][5];

	for (int j = 1; j <= 5; j++) {
		printf("   %-7d", j);
		for (int i = 1; i <= years; i++) {
			capital[i] += capital[i] * rates[i];
			printf("%-10.2lf", capital[i]);
		}
		printf("\n");
	}

	return 0;
}