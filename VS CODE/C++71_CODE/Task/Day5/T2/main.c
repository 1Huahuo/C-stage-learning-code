#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
要求基于下列两个函数完成这个编程题：
// 判断abc是否可以组成三角形，true表示可以组成，false表示不可以
bool is_triangle(int a, int b, int c);
// 利用海伦公式在abc可以构成三角形的前提下，求三角形面积
double get_area(int a, int b, int c);
注意：不要忘记使用sqrt函数要包含头文件<math.h>
*/

bool is_triangle(int a, int b, int c) {
	if (a + b > c && a + c > b && b + c > a)
		return true;
	else
		return false;
}	

double get_area(int a, int b, int c) {
	double p = (double)(a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(void){
	int a, b, c;
	printf("Please enter the lengths of the three sides of the triangle:\n");
	scanf("%d%d%d", &a, &b, &c);

	if(is_triangle(a,b,c))
		printf("It is a triangle.\nThe area of this triangle is:%lf\n", get_area(a, b, c));
	else
		printf("It is not a triangle.\n");

	return 0;
}