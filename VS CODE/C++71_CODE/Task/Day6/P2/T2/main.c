#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
（扩展题，有时间就做一下）
给定一个整数数组，请将所有非正数(包含负数和0)全部移到数组开头，
正数则全部移到数组末尾，要求原地完成，不使用额外内存空间。
比如：
数组[1, -2, 3, 0, -9, 0, 10, 3]
最终分组完成后的效果应该是[非正数（包含0）, 正数]（稳定性不做要求）
提示：仍然可以基于双指针单向分区或夹逼法求解。
*/

void swap_elem(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void move_arr_elem(int* arr, int len) {
	int i = 0, j = len - 1;
	while (i < j) { // 判断条件先检查！越界！
		while (i < j && arr[i] <= 0) // ！！！关于数组的问题一定要有越界检查，并且判断条件先检查！越界！
			i++; // 左端右移
		while (i < j && arr[j] > 0 ) // ！！！关于数组的问题一定要有越界检查
			j--; // 右端左移
		if (i < j)
			swap_elem(&arr[i], &arr[j]);
	}
}

int main(void) {
	int arr[10] = { 1, -3, 0, 4, -6, 8, 0, -1, 1, -9 };

	move_arr_elem(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}