#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN(X) sizeof(X) / sizeof(X[0])

/*
第一题：
查找数组的最大值和最小值，但要将最大值作为返回值返回，最小值则依靠传入的指针完成赋值。
要求不能使用"[]"运算符。
函数的声明如下：
int max_min(int *arr, int len, int *pmin);

第二题：
求平均值，给定一个double数组，求平均值，并且返回。
要求使用while循环遍历数组，然后配合"*p++"的语法实现。
函数的声明如下：
double get_ave(double *arr, int len);
*/

int max_min(int* arr, int len, int* pmin) {
	int max = *arr;
	*pmin = *arr;
	for (int i = 1; i < len; i++){
		if (*(arr + i) > max)
			max = *(arr + i);
		if (*(arr + i) < *pmin)
			*pmin = *(arr + i);
	}
	return max;
}

double get_ave(double* arr, int len) {
	double sum = 0;
	int count = len;
	while (count--)
		sum += *arr++;
	return sum / len;
}

int main(void) {
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int pmin;

	//printf("最大值：%d\n", max_min(arr, ARR_LEN(arr), &pmin));
	//printf("最小值：%d\n", pmin);

	double arr1[5] = { 1, 2, 3, 4, 5 };
	printf("平均值：%lf\n", get_ave(arr1, ARR_LEN(arr1)));
	
	return 0;
}