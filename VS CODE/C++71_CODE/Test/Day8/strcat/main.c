#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// strcat：拼接字符串
// 1.从 dest 字符串的空字符 '\0' 开始，替换这个空字符，
//   然后将src中表示字符串的字符数据从开头到空字符，全部拼接到dest末尾。
// 2.这个过程中，src 字符串不会被修改，所以它被 const 修饰。
void test1() {
	char str1[50] = "hello";
	char str2[50] = "world";

	printf("%s\n", str1);
	strcat(str1, str2);
	printf("%s\n", str1);
}

// 
void test2() {
	char dest[10] = "hello, ";
	char src[] = "world";

	//strncat(dest, src, 1);
	//printf("%s\n", dest);

	//strncat(dest, src, 2);
	//printf("%s\n", dest);

	strncat(dest, src, 3);
	printf("%s\n", dest); // 当前%s不是一个有效的字符串dest[9] != '\0'
}



int main(void) {
	//test1();
	test2();

	return 0;
}