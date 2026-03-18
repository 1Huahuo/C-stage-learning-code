#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
标准库函数strcat会将一个字符串追加到另一个字符串的末尾。
现在我们编写一个函数把两个字符串拼接起来，返回拼接的结果，
但要求不改变其中任何一个字符串。其函数声明如下：
 char* my_strcat(const char* prefix, const char* suffix);
形参prefix表示前缀，suffix表示后缀，拼接的结果是prefix + suffix
比如：my_strcat("abc", "d")，拼接的结果是"abcd"。
思路：
	在堆上分配内存空间，用于存储结果字符串。
	将prefix和suffix两个字符串的字符信息复制进去。
*/

char* my_strcat(const char* prefix, const char* suffix) {
	int len1 = strlen(prefix);
	int len2 = strlen(suffix);
	char* res = (char*)malloc((len1 + len2 + 1) * sizeof(char));
	strcpy(res, prefix);
	strcpy(res + len1, suffix);

	return res;
}

int main(void) {
	char prefix[] = "abcd"; // char *str[]; 是指针数组而不是字符串变量！
	char suffix[] = "efg";

	char* p = my_strcat(prefix, suffix);
	printf("%s\n", p);

	//printf("%d\n", strlen(p)); // 7
	//printf("%d\n", sizeof(p)); // 8

	free(p); // 不需要时要释放
	p = NULL;
	return 0;
}