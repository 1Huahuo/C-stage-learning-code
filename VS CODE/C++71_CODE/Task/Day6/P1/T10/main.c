#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_LEN(X) sizeof(X) / sizeof(X[0])

/*
以下题目功能，都要求编写函数将数组作为参数传递来实现：
*/

// 1.编写函数交换数组中两个下标的元素。函数声明如下：void swap(int *arr, int i, int j) 。
// 要求不使用[]运算符，将[]还原成解引用运算符和指针加法来完成。
void swap_arr_elem(int* arr, int i, int j) {
	*(arr + i) += *(arr + j);
	*(arr + j) = *(arr + i) - *(arr + j);
	*(arr + i) = *(arr + i) - *(arr + j);
}

// 2.数组元素的逆序。要求使用[]运算符以及纯粹指针操作两种方式来完成。
// 运算符
void reverse_arr_op(int* arr, int len) {
	for (int i = 0; i < len / 2; i++) {
		arr[i] += arr[len - 1 - i];
		arr[len - 1 - i] = arr[i] - arr[len - 1 - i];
		arr[i] = arr[i] - arr[len - 1 - i];
	}
}
// 纯粹指针操作
void reverse_arr_pointer(int* arr, int len) {
	for (int i = 0; i < len / 2; i++) {
		*(arr + i) += *(arr + len - 1 - i);
		*(arr + len - 1 - i) = *(arr + i) - *(arr + len - 1 - i);
		*(arr + i) = *(arr + i) - *(arr + len - 1 - i);
	}
}

// 3.数组元素求和。要求使用"*p++"语法结构来完成数组元素的累加。
void add_arr(int* arr, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += *arr++;
	printf("数组元素之和是：%d\n", sum);
}

// 4.给定一个int数组以及一个目标值target，请编写函数找到这个目标值的下标，要求该函数没有返回值。
void find_arr_target_index(int* arr, int len, int target, int* index) {
	for (int i = 0; i < len; i++)
		if (arr[i] == target)
			*index = i;
}

// 5.编写一个函数，检查一个整数数组是否是回文，即正序与倒序相同。例如[1,2,3,2,1]就是回文的。
// 要求使用指针的算术运算，不要使用取下标[]运算符。
bool is_palindrome(int* arr, int len) {
	for (int i = 0; i < len / 2; i++) {
		if (*(arr + i) != *(arr + len - 1 - i))
			return false;
	}
	return true;
}

// 6.给定一个非空整数数组src，再给定一个足够长的dest数组。
// 编写一个函数copy_array，使用*p++复制src数组到dest数组。
void copy_arr(int* arr, int len, int* dest) {
	int* p = arr;
	for (int i = 0; i < len; i++)
		dest[i] = *p++;
}

// 注意：这道题目要把代码写得尽量简洁！！
// 7.给定一个整数数组，将该数组中所有奇数移到数组的前面，偶数移到数组的后面。（扩展题）
void move_arr_elem(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		int j = i;
		// arr[j-1]判断不能放在左边，j-1 = -1时非法访问，会导致未定义行为，可能程序崩溃
		// while (arr[j - 1] % 2 == 0 && j != 0) {
		while (j != 0 && arr[j - 1] % 2 == 0) {
			swap_arr_elem(arr, j, j - 1);
			j--;
		}
	}
}

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };

	//swap_arr_elem(arr, 0, 1);

	//reverse_arr_op(arr, ARR_LEN(arr));
	//reverse_arr_pointer(arr, ARR_LEN(arr));

	//add_arr(arr, ARR_LEN(arr));

	//int index = -1, target;
	//printf("请输入想要找的目标值：");
	//scanf("%d", &target);
	//find_arr_target_index(arr, ARR_LEN(arr), target, &index);
	//printf("目标值%d的下标是%d\n", target, index);

	//int arr1[5] = { 1, 2, 3, 2, 1 };
	//if (is_palindrome(arr, ARR_LEN(arr1)))
	//	printf("该数组是一个回文数组\n");
	//else
	//	printf("该数组不是一个回文数组\n");

	//int dest[ARR_LEN(arr)];
	//copy_arr(arr, ARR_LEN(arr), dest);
	//for (int i = 0; i < ARR_LEN(arr); i++)
	//	printf("%d\n", dest[i]);

	//int arr2[5] = { 0, 1, 2, 3, 4 };
	//move_arr_elem(arr2, ARR_LEN(arr2));
	//for (int i = 0; i < ARR_LEN(arr2); i++)
	//	printf("%d\n", arr2[i]);

	//printf("%d\n", arr[0]);
	//printf("%d\n", arr[1]);
	//printf("%d\n", arr[2]);
	//printf("%d\n", arr[3]);
	//printf("%d\n", arr[4]);

	return 0;
}