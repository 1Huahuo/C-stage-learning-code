#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中的元素数目。
注意：最终，合并后数组不应由函数返回，而是存储在数组nums1中。为了应对这种情况，nums1的初始长度为m+n，
其中前m个元素表示应合并的元素，后n个元素为0，应忽略。nums2的长度为n。
*/

//从后往前合并(最优解)——“倒序双指针”
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1, p2 = n - 1, p = nums1Size - 1;
    while (p2 >= 0 /* && p1 >= 0*/) {    //完全没必要管nums1，因为是非严格有序数组
                                        //因为当nums2全部拷贝到nums1中时，
                                        //无论nums1中前半部分还有没有未移动的都处于最终的合法位置
        if (p1 >= 0 && nums1[p1] > nums2[p2]) //p2的越界可能已经在while判断条件中被杜绝了
            nums1[p--] = nums1[p1--];
        else
            nums1[p--] = nums2[p2--];

        //完全写反，因为在进入到while中后p1(数组下标)仍存在越界的可能
        /*if (nums2[p2] >= nums1[p1] || p1 < 0) //不要忘记考虑p1 < 0的情况
            nums1[p--] = nums2[p2--];
        else
            nums1[p--] = nums1[p1--];*/
    }
    /*if (p2 < 0)
        while (p >= 0)
            nums1[p--] = nums1[p1--];
    else
        while (p >= 0)
            nums1[p--] = nums2[p2--];*/
}

/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0;  // nums1 的当前位置
    int j = 0;  // nums2 的当前位置

    //！！！核心在于仅优先插入数组2当前小于数组1当前值的值，若大于暂时不管
    //！！！（因为仅知道大概位置即数组1当前值之后，若要确定具体位置则会增加工作量
    //！！！并且，即使不管之后也能自动处理即暂且跳过数组1当前值即i++）

    while (j < n) {
        // 如果 nums1 已经处理完所有原始有效元素，直接把 nums2 剩余元素放到后面
        if (i >= m + j) {
            nums1[i] = nums2[j];
            i++;
            j++;
            continue;
        }

        // 如果当前 nums1 的元素大于 nums2 的元素，需要插入
        if (nums1[i] > nums2[j]) {
            // 把从 i 到 m+j-1 的元素后移一位
            for (int k = nums1Size - 1; k > i ; k--) {//k的初值一定不能是nums1Size，不然会越界导致未定义行为，从而导致进程崩溃
                nums1[k] = nums1[k - 1];
            }
            nums1[i] = nums2[j];
            j++;  // nums2 指针前进
            i++;  // nums1 指针前进（因为插入了新元素）
        }
        else {
            // nums1[i] <= nums2[j]，直接跳过 nums1 的这个元素
            i++;
        }
    }
}*/

/*
1, 2 ,!2 ,3 ,0 ,0
2, !5, 6
1, 2, 2, 5, 3, 0
*/
int main(void) {
	int nums1[] = { 1, 2, 3, 0, 0 ,0 };
	int nums2[] = { 2, 5, 6 };

	int m = 3, n = 3;
	merge(nums1, 6, m, nums2, 3, n);
	for (int i = 0; i < 6; i++) {
		printf("%d\n", nums1[i]);
	}

	return 0;
}