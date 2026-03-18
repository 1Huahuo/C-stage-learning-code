#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
指针两大功能：
存地址——找到内存中的具体位置
存类型——知道如何解释该位置的内存（格式：即类型和大小）

通用指针：是个指针，能存任意类型的地址的指针
void * 只用来存地址，如果涉及到使用，强制转换回它的具体类型，才能用来解引用和算术运算

通用指针：只用来存地址，无法直接使用它
		  动态内存分配函数中大量使用了通用指针（如：malloc、calloc、realloc）
*/

void test1() {
	// 通用指针(void *p)：能存任意类型的地址，因为指针有类型，但地址本质是没有类型的
	// void * 只用来存地址，如果涉及到使用（解引用与算术运算），要转换到具体类型 

	int arr[5] = { 10,20,30,40,50 };
	void* p = arr;

	//int val = *p + 100; 不合法，此时p为通用指针并非是int型，不能直接解引用

	int* p_int1 = (int*)p; 
	int* p_int2 = p; // 隐式类型转换
	int val1 = *p_int1 + 100; // 110
	int val2 = *p_int2 + 200; // 210
	printf("val1 = %d\n", val1);
	printf("val2 = %d\n", val2);

	//p + 1; 不合法，此时没有类型，对p + 1操作p具体也不知道要移动多少
}

int main(void) {
	test1();
	
	return 0;
}