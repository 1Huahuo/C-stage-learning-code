#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定一个非空的整数数组nums，已知某个元素只出现了一次，其余元素均出现两次，那么请你找出这个只出现一次的元素。
（不要定义函数来实现，直接在main函数里实现）
*/

int main(void) {
	int nums[ ] = { 1, 2 , 3, 4, 1, 2, 3 };
	int one_num = nums[0];
	for (int i = 1; i < 7; i++) {
		one_num ^= nums[i];
	}

	printf("The number that appears only once is:%d\n", one_num);

	return 0;
}