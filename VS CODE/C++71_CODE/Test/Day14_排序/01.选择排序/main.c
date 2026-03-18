#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) sizeof(arr) / sizeof(arr[0])
//#define SWAP(arr, i, j) int t = arr[i]; arr[i] = arr[j];arr[j] = t; 
// 宏是简单的文本替换，当这个宏用在 if/for 等语句后且没有加花括号时，若后续有同层级代码，会导致语法错误或逻辑错乱。
//#define SWAP(arr, i, j) {int t = arr[i]; arr[i] = arr[j];arr[j] = t;} // 加个花括号就没问题了

/*
选择排序：
	i表示未排序序列的开头元素
	最后一轮选择排序时, 未排序序列的开头元素是数组倒数第二个元素
	i的每个取值都表示一轮选择排序
	也就是选择排序一共执行9趟
工作原理如下：
第一轮选择排序：一开始整个数组都处于未排序状态，记录未排序序列的开头位置(第一轮就是数组首元素)，遍历整个数组找到最小值，将最小值放在未排序序列的开头，然后在未排序的序列中去掉该元素。
第二轮选择排序：除了首元素外，数组所有元素处于未排序状态，记录未排序序列的开头位置(第二轮就是数组的第二个元素)，遍历剩余未排序序列中的元素找到最小值，将最小值放在未排序序列的开头，然后在未排序的序列中去掉该元素。
....
重复过程：重复1和2两个过程，每一轮选择排序中，都会从剩余未排序的元素中继续寻找最小元素，然后放到未排序的序列的开头。
最后一轮选择排序：直到未排序序列的开头已经是倒数第二个元素，进行最后一轮选择排序。随后未排序序列就只剩最后一个元素，此元素一定就是数组元素最大值，选择排序结束。
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

void selection_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) { // 可少循环一次，因为最后两个数据找出最小值，剩下为全局最大值
		int min = i;
		for (int j = i + 1; j < len; j++) { // 可少循环一次，因为不必和自身相比
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr, i, min);
	}
}

int main(void) {
	int arr[] = { 1,10,2,5,3,4,5,6,3,2 };
	int len = ARR_LEN(arr);

	selection_sort(arr, len);

	print_arr(arr, len);
	
	return 0;
}