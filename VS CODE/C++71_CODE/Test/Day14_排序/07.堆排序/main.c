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

// 向下调整为大根堆——0-base完全二叉树的左孩子为2i+1,右孩子为2i+2
void adjust_down(int* arr, int left, int right) { //传入数组和要向下调整的区间
	int pos = left; // 向下调整的位置
	int	t = arr[pos]; // 向下调整的值
	for (int i = left * 2 + 1; i <= right; i = i * 2 + 1) {
		// 比较左右孩子的大小
		if (i + 1 <= right && arr[i] < arr[i + 1])
			i++; // 此时指向右孩子
		// 比较要调整的值与左右孩子的较大者
		if (t < arr[i])
			arr[pos] = arr[i];
		else
			break; // 要调整的值比左右孩子都大，则不用调整，直接结束循环

		pos = i; // 若需要调整，则更新要调整的值要放的位置的下标
	}
	arr[pos] = t; // 将最开始的要调整的值存入最终确定的位置
}

void heap_sort(int arr[], int len) {
	// 先从最后一个节点的双亲结点注逐一往前进行向下调整，将数组调整为大堆
	for (int i = len / 2 - 1; i >= 0; i--) {
		adjust_down(arr, i, len - 1);
	}
	// 将最大值放置到末尾然后将其与堆的联系解除，然后再对堆顶元素向下调整
	for (int i = len - 1; i >= 1; i--){
		swap(arr, 0, i);
		adjust_down(arr, 0, i - 1);
	}
}

int main(void) {
	int arr[] = { 4, 10, 3, 5, 1 };
	int len = ARR_LEN(arr);

	heap_sort(arr, len);
	print_arr(arr, len);

	return 0;
}