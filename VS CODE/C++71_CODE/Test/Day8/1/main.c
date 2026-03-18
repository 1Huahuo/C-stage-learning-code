#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

int main(void) {
	char str[] = "123";

	// 两种方式均能表示字符串
	char* p1 = str; // 字符指针，存字符串(字符数组)首地址
	char* p2 = &str; // 数组指针，隐式类型转换：& + 数组名 = 数组指针

	printf("%s\n", p2);

	//printf("%d\n", sizeof(size_t)); // X86：4		X64：8
}