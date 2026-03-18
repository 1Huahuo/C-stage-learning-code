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

void shell_sort(int arr[], int len) {
	int gap = len / 2;
	while (gap > 0) {
		gap = gap / 2;
		for (int i = gap; i < len; i++) { // 保证每条序列中都有一个元素已经进去了即防止j-gap越界
			int j = i;
			while (j >= 0) {
				if (arr[j - gap] <= arr[j])
					break;
				else {
					swap(arr, j, j - gap);
					j -= gap;
				}
			}
		}
	}
}

int main(void) {
	int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
	int len = ARR_LEN(arr);
	shell_sort(arr, len);

	print_arr(arr, len);

	return 0;
}