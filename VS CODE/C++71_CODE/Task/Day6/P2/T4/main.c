#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
（扩展题，有时间就做一下，可以直接看文档做这道题）
如果你已经搞清楚了荷兰国旗问题，那么这个问题就比较简单了。
比如：
数组[1, -2, 3, 0, -9, 0, 10, 3]
最终分组完成后的效果应该是[负数, 0, 0, 正数]（稳定性不做要求）
思路是：仍然是三个索引：
left索引标记下一个负数放置的位置
mid索引用于遍历数组，并且标记0元素放置的位置
right索引用标记下一个正数放置的位置
核心操作逻辑是：
当mid索引发现一个负数时，交换left和mid索引位置的元素，并后移1位mid和left索引（原理是一样的）
当mid索引发现一个0时，不需要交换元素，仅需要mid索引后移1位
当mid索引发现一个正数时，交换right和mid索引位置的元素，仅后移1位right索引，mid索引不动。
当mid索引遍历完整个数组，这个三向分区操作就完成了。
*/

void swap_elem(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void three_pointer_question(int* arr, int len) {
	int left = 0, mid = 0, right = len - 1;
	while (mid <= right) {
		if (mid <= right && arr[mid] < 0) {
			swap_elem(&arr[mid], &arr[left]);
			mid++;
			left++;
		}
		else if (mid <= right && arr[mid] == 0) {
			mid++;
		}
		else {
			swap_elem(&arr[mid], &arr[right]); // mid换来的正/负/零都有可能，不能直接继续移动mid
			right--;
		}
	}
}

int main(void) {
	int arr[10] = { 1, -3, 0, 4, -6, 8, 0, -1, 1, -9 };

	three_pointer_question(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}