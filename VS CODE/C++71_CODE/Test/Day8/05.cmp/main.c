#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1.不能使用'=='来进行比较的
  字符串比较大小，其实就是比较字符串的内容，而不是地址
2.strcmp,用于比较两个字符串内容是否相同
  如果相同，返回0；不相同，则返回ASCII码表上的差值
实际上，C 标准只规定：
	如果 s1 < s2，返回一个负数
	如果 s1 == s2，返回 0
	如果 s1 > s2，返回一个正数

3.在实际应用当中，strcmp函数的返回值我们普遍更关注0或正负号，
  至于具体返回值的数据是多少，并不重要。
*/
void test() {
	char str[] = "abc";
	char str2[] = "123";
	char str3[] = "bbb";
	char str4[] = "aaa";
	char str5[] = "abcd";
	char str6[] = "abc";

	printf("%d\n", strcmp(str, str2)); // 1
	printf("%d\n", strcmp(str, str3)); // -1
	printf("%d\n", strcmp(str, str4)); // 1
	printf("%d\n", strcmp(str, str5)); // -1
	printf("%d\n", strcmp(str, str6)); // 0
}

int main(void) {

	test();

	return 0;
}