#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) sizeof(arr) / sizeof(arr[0])

/*

*/

void swap(int arr[], int i, int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertion_sort(int arr[], int len) { // 插入排序要变边较边交换不能最后再移动
	for (int i = 1; i < len; i++) { // 插入排序i从1开始即从第二个元素开始，否则会导致内存循环错误
		//int t = i;
		for (int j = i - 1; j >= 0; j--) {
			//if (arr[j] <= arr[t])
			if (arr[j] <= arr[j + 1])
				break;
			else
				//swap(arr, j, t--); // 注意，这里用的是宏替换，所以t--会被执行多次
				swap(arr, j, j + 1);
		}
	}
}

int main(void) {
	int arr[] = { 1, 21, 45, 231, 99, 2, 18, 7, 4, 9 };
	int len = ARR_LEN(arr);
	insertion_sort(arr, len);

	print_arr(arr, len);

	return 0;
}