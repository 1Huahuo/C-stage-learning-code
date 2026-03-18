#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define ARR_LEN(arr) sizeof(arr) / sizeof(arr[0])

/*
工作原理如下(按照从小到大排序)：
1.	第一轮冒泡排序：从数组的第一个元素开始，比较相邻的元素。如果第一个元素比第二个元素大，则交换它们的位置。然后，移动到下一对相邻元素，重复这个过程，直到比较最后一对元素。每一轮冒泡排序都会使当前比较序列的最大值到达数组末尾，随后第二轮排序过程中，需要比较的元素就减1。(将尾部最大的元素减去不再排序)
2.	第二轮冒泡排序：重复第一轮的过程，但这次只比较和交换直到倒数第二个元素（因为最后一个元素已经是最大的了）。在这一轮结束时，倒数第二大的元素会被“冒泡”到倒数第二的位置。
3.	...
4.	结束条件：
	a.	在不设置任何额外结束条件的前提下，冒泡排序每一轮都会将未排序序列的最大值"冒泡"到末尾。冒泡排序需要进行固定的(n - 1)轮！
	b.	但实际上在这(n - 1)轮冒泡排序的过程中，只要某一轮完全不存在元素的交换，就说明数组已经完全有序了，排序就可以结束了。
	c.	所以我们可以设定一个布尔值来标记此轮冒泡排序是否存在元素交换，如果没有元素交换，直接结束整个排序。这种做法可以优化冒泡排序的性能，尤其是当原数组已基本有序时。
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

void bubble_sort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		bool is_swap = false;
		for (int j = 1; j < len - i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
				is_swap = true;
			}
		}
		if (!is_swap)
			return;
	}
}

int main(void) {
	int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
	int len = ARR_LEN(arr);
	bubble_sort(arr, len);

	print_arr(arr, len);

	return 0;
}