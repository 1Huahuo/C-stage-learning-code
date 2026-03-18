#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test1() {
	int len;

	len = strlen("abc"); // 3
	len = strlen("");    // 0

	char str[] = "abcd";
	char str2[10] = "12345";
	char str3[5] = { 'a','\0','c' };
	len = strlen(str);  // 4
	len = strlen(str2); // 5
	len = strlen(str3); // 1
}

void test2() {
	char str4[4] = "1234";   // str4实际只能存储1234这四个字符,无法表示一个字符串
	int len = strlen(str4);     // str4不能表示一个字符串,该函数调用会引发未定义行为
}


void test3() {
	char str1[] = "abcd";
	char str2[10] = "12345";
	char str3[5] = { 'a','\0','c' };

	// 传入参数为字符数组/字符串的首地址，sizeof与strlen的区别
	// sizeof——当前字符数组所占空间大小
	// strlen——当前字符串的长度

	printf("%d\n", sizeof(str1)); // 5 
	printf("%d\n", strlen(str1)); // 4

	printf("%d\n", sizeof(str2)); // 10
	printf("%d\n", strlen(str2)); // 5

	printf("%d\n", sizeof(str3)); // 5
	printf("%d\n", strlen(str3)); // 1

	char* p = "1234567890";
	printf("%d\n", sizeof(p)); // 4——地址指针p所占空间大小，x64中为8
	printf("%d\n", sizeof(*p)); // 1——字符串首字符所占空间大小
	printf("%d\n", sizeof("1234567890")); // 11——字符串所占空间大小
	printf("%d\n", strlen(p)); // 10——字符串长度
}

size_t my_strlen(const char* src) {
	size_t count = 0;

	while (*src != '\0') { // 遍历计算字符串长度
		count++;
		src++;
	}

	return count;
}


int main(void) {
	char* p = "1234567890";

	//test1();
	//test2();
	//test3();
	printf("%d\n", my_strlen(p)); // 10

	return 0;
}