#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN(arr) sizeof(arr) / sizeof(arr[0])
int count = 0;
/*

*/

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_arr1(int arr[], int left, int right) {
	for (int i = left; i <= right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// 用来完成合并过程中的局部排序
static void merge(int arr[], int left, int mid, int right, int a[]) {
	int t_idx = left, left_idx = left, right_idx = mid + 1;
	/*
	* t_idx: 用于存放合并结果的临时数组首元素下标
	* left_idx: 左子数组的首元素下标
	* right_idx: 右子数组的首元素下标
	*/
	while (left_idx <= mid && right_idx <= right) {
		if (arr[left_idx] <= arr[right_idx])
			a[t_idx++] = arr[left_idx++];
		else
			a[t_idx++] = arr[right_idx++];
	}

	// while结束时，左右子数组必然有一个没有元素了,此时另一个数组必然还有元素
	while (left_idx <= mid)
		a[t_idx++] = arr[left_idx++];
	while (right_idx <= right)
		a[t_idx++] = arr[right_idx++];

	for (int i = left; i <= right; i++)
		arr[i] = a[i];
	
	//print_arr1(arr, left, right); // 打印大于1个元素的一轮归并排序的元素
}

// 用来递归二路划分
static void divide_merge(int arr[], int left, int right, int a[]) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	
	divide_merge(arr, left, mid, a);
	divide_merge(arr, mid + 1, right, a);

	merge(arr, left, mid, right, a);
	
}

// 合并排序主体
void merge_sort(int arr[], int len) {
	int* a = (int*)calloc(len, sizeof(int));
	if (a == NULL) {
		printf("calloc is failed in merge_sort.\n");
		return;
	}

	divide_merge(arr, 0, len - 1, a);
	free(a);
}

int main(void) {
	int arr[] = { 8, 3, 2, 6, 9, 7, 1, 0, 4, 5 };
	int len = ARR_LEN(arr);

	merge_sort(arr, len);
	print_arr(arr, len);

	return 0;
}