#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

void test1() {
	char str1[80 + 1];
	char* str2;

	// str1和str2有没有区别？

	// str1, 这是一个数组的声明。 向系统要了81个字节的空间。 
	// 这个空间，是可以直接用于存储数据的。 

	// str2,是一个指针。 是指针指向的内存，是否有效，是否能用。 
	// 所以，str2只用于指向一块存在的内存。 
	str2[0] = 'h';
	str2[1] = 'e';
	str2[2] = 'l';
	str2[3] = 'l';
	str2[4] = '\0';

	// 必须 str2 = str1; 让str2指向str1才能开始使用这块内存。 
}

int main(void) {
	

	printf("1\n");
}