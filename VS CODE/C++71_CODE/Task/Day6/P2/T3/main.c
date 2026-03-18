#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
荷兰国旗问题（也称为三色排序问题）是一个计算机科学中的经典问题，
常用于讨论快速排序算法的三向分区(three-way-partitioning)策略。
这个问题来源于荷兰国旗的三种颜色：红色、白色和蓝色，目标是将含有三种颜色的条带
（通常用0, 1, 2来代表三种颜色）重新排序，
使得同一颜色的条带聚集在一起，并且顺序是红、白、蓝（或0、1、2）。
现在给定一个整型数组，其中包含不确定数量的三个元素0、1、2，请将该整数数组分区为三个部分：
0在前面，1在中间，2在最后面。
举例：
整型数组为：[0, 1, 2, 2, 1, 0, 0, 2, 1, 1, 0, 2]
分区后的结果是：[0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2]
*/

void swap_elem(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 三指针同时移动-双向夹逼——修改自己代码
void three_color_sort(int* arr, int len) {
	int left = 0, mid = 0, right = len - 1;

	// 根本问题：不能让三个指针独立移动后再判断，
	// 荷兰国旗问题需要以 mid 为核心，left 和 right 只是"边界标记"。
	while (mid <= right) { // !!!循环条件必须要有mid，因为就是靠mid来遍历数组的
		while (mid <= right && arr[mid] == 0) { //由于mid从最左端开始移动，所以mid左边不包括mid一定只有0和1
			swap_elem(&arr[left], &arr[mid]);
			left++;
			mid++;
		} // 此while对于 mid从未遇到过1过一直遇到都是0 与 遇到过1后再次遇到0 两种情况都能处理
		while (mid <= right && arr[right] == 2)
			right--;

		// 现在 mid 指向 1 或 2，right 指向非 2
		if (mid > right) // 即代表mid已经遍历完待排序的元素了，即结束
			return;
		if (arr[mid] == 2) // 遇到2，放到右边
			swap_elem(&arr[mid], &arr[right--]);
		else // 遇到1，直接跳过继续右移
			mid++;
	}
}
// 标准荷兰旗算法
/*
void three_color_sort(int* arr, int len) {
	int left = 0;      // 0区的右边界（下一个放0的位置）
	int mid = 0;       // 当前遍历的指针
	int right = len - 1; // 2区的左边界（下一个放2的位置）

	while (mid <= right) {  // mid 遍历到 right 为止
		if (arr[mid] == 0) {
			// 遇到0：放到左边，left和mid都右移
			swap_elem(&arr[left], &arr[mid]);
			left++;
			mid++;
		}
		else if (arr[mid] == 1) {
			// 遇到1：不用动，mid右移
			mid++;
		}
		else { // arr[mid] == 2
		 // 遇到2：放到右边，right左移（mid不动，要检查新换过来的）
			swap_elem(&arr[mid], &arr[right]);
			right--;
		}
	}
}
*/


int main(void) {
	int arr[] = { 0, 1, 2, 2, 1, 0, 0, 2, 1, 1, 0, 2 };

	three_color_sort(arr, 12);

	for (int i = 0; i < 12; i++)
		printf("%d \n", arr[i]);

	return 0;
}