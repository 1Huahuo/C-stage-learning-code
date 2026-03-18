#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

// 挖洞即双指针交替交换法
void quick_sort(int* arr, int left, int right)
{
	// 如果左指针大于等于右指针，表示数组为空或只有一个元素，直接返回
	if (left >= right) {
		return;
	}

	int begin = left, end = right;
	int pivot = arr[left];  // 使用pivot来保存基准值，选择第一个数作为基准值
	int hole = left;   // 刚开始“坑”指向 left


	while (left < right) {

		while (left < right && arr[right] >= pivot) {
			right--;
		}
		if (left < right) {
			arr[hole] = arr[right]; // 即放到left上
			hole = right;
			left++;
		}


		while (left < right && arr[left] <= pivot) {
			left++;
		}
		if (left < right) {
			arr[hole] = arr[left]; // 即放到right上
			hole = left;
			right--;
		}
	}

	// 补坑位
	arr[hole] = pivot;

	//递归分治
	// [begin, hole - 1] hole [hole + 1, end]
	quick_sort(arr, begin, hole - 1);
	quick_sort(arr, hole + 1, end);

}

int main()
{
	int arr[] = { 3, 1, 4, 6, 2, 10, 9, 7, 100, 99, 0 };
	//int arr[] = { 5, 4, 3, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的序列：");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//调用快速排序
	quick_sort(arr, 0, size - 1);

	printf("快速排序后的序列：");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}