#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写函数，查找一个int数组中的最大元素和第二大元素，
并将它们分别存放在由 largest 和 second_largest 指向的变量中。
按照下面的函数声明来实现这个函数。
void find_two_largest(int arr[], int n, int* largest, int* second_largest);
注意：为了简化实现，数组不存在重复元素，请不要考虑存在重复元素的情况。
*/

void find_two_largest(int arr[], int n, int* largest, int* second_largest) {
	*largest = *second_largest = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > *largest)
			*largest = arr[i];
	for (int i = 0; i < n; i++)
		if (arr[i] > *second_largest && arr[i] < *largest)
			*second_largest = arr[i];
}

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int largest, second_largest;

	find_two_largest(arr, sizeof(arr) / sizeof(arr[0]), &largest, &second_largest);
	printf("最大元素：%d\n第二大元素：%d\n", largest, second_largest);

	return 0;
}