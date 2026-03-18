#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// strcpy——字符串复制
char* my_strncpy(char* dest, const char* src, int n) {
	int min = strlen(src) < n ? strlen(src) : n; // 先把有效字符复制进去，个数取二者最小值
	char* temp = dest;
	while (min--) // 使用指针操作的话可以省去辅助变量i
		*dest++ = *src++;
	if (strlen(src) < n) { // 只有还未复制够n个字符时才填充
		int count = n - strlen(src);
		while (count--)
			*dest++ = '\0';
	}
	// else // strlen(src) >= n，不用操作
	return temp;
}

void test1() {
	 
	char str1[50] = { 0 };
	char str2[] = "123456";

	 //str1 = str2;——不合法，数组名不能被赋值
	 //str1 = "876554564";——同理，不合法，'='右值看作字符串首地址指针

	char* ret = strcpy(str1, str2); // ret在正常情况下，返回的就是副本首地址dest 

	printf("str1 = %s\n", str1); // 123456
	printf("str2 = %s\n", str2); // 123456
	printf("ret = %s\n", ret); // 123456
	printf("(ret == str1) = %d\n", (ret == str1)); // 测试二者是否指向同一个地址空间

	
}

// strcpy 只会把要复制的字符串给全部复制进去(包括结尾空字符)， 不会考虑越界问题
void test2() {
	char str1[10] = { 0 };

	char* p1 = "1234567";
	char* ret = strcpy(str1, p1);
	printf("str1 = %s\n", str1); // 1234567

	char* p2 = "987654321";
	char* ret2 = strcpy(str1, p2);
	printf("str1 = %s\n", str1); // 987654321


	char* p3 = "abcabcabcabcabc";
	char* ret3 = strcpy(str1, p3);
	printf("str1 = %s\n", str1); // abcabcabcabcabc——产生越界
}
// 使用strcpy的时候，一定要注意越界问题
void test3() {
	char* p1 = "123456789";
	char* p2 = "000";

	// p1指向只读数据段，不能将p2数据写入即复制到p1中，会直接报错。
	//strcpy(p1, p2);——不合法
}

// strncpy: 仅复制n个字符进去，可以控制复制的个数
// n 小于 strlen(src) + 1，会复制n个字节，没有补\0
// n 等于  strlen(src) + 1，会复制n个字节，结尾补一个\0
// n 大于  strlen(src) + 1，会复制src中所有字符包括\0，并且后面继续补若干个\0
void test4() {
	char dest[10] = "1234567890";
	char src[5] = "abcd";

	strncpy(dest, src, 2);
	strncpy(dest, src, 4);
	strncpy(dest, src, 5);
	strncpy(dest, src, 8);
}

char* my_strncpy_optimize(char* dest, const char* src, size_t n) {
	char* tmp = dest;

	while (n-- && (*dest++ = *src++));

	while (n-- && !(*dest++ = '\0'));

	return tmp;
}

int main(void) {

	//test1();
	//test2();
	//test3();
	//test4();

	return 0;
}