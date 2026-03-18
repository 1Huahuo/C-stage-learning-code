#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
键盘输入一名学生的语文、数学和英语成绩（均为整数百分制）。计算其平均成绩，并保留两位小数打印显示。
*/
int main(void) {
	float chinese, math, english;
	scanf("%f %f %f", &chinese, &math, &english);
	float averag = (chinese + math + english) / 3;
	
	printf("平均成绩为%.2f", averag);

	return 0;
}