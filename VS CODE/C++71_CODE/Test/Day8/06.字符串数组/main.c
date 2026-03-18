#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
字符串：字符数组，以空字符'\0'结尾。
'\0'本质就是ASCII码表中ASCII值为0的字符
	char ch1 = '0';		×
	char ch2 = '\0';	√
	char ch3 = 0;		√
*/

// 字符串变量
void test() {
	// 两种形式
	//char str[80 + 1];
	//char *p;
	// p一定要正确指向一个空间，才能当做字符串使用
	char str1[10 + 1] = "1234567890"; // 字符串变量
	char* p1 = str1; // 字符串变量
	// str1与p1可以互换使用，但str1是数组名不可能重新赋值，而p1是指针可以指向其他地方

	char* p2 = *str1; // 不合法，左边是指针，右边是字符'1'
	char* p3 = &str1; // 不合法，左边是指针，右边是数组指针char (*)[11]（str1是char[11]）

	int* p4 = str1; // 合法，但可能产生错误,char*读取1个字节，int*读取4个字节
}

int main(void) {
	// 字符串字面值：只读数据段，以数组的形式存储
	// 只读数据段：不能修改，但可以读取 
	//printf("%d\n", sizeof("hello")); // 6
	// 对于数组，参数为：数组+长度。 
	// 字符串：也是一个字符数组，但不关心长度，因为有'\0'作为结尾字符

	test();

	return 0;
}