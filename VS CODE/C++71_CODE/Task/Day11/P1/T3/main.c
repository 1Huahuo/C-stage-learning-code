#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
（扩展题，可以放到最后做）
编写一个C语言程序，完成以下任务：
首先，从键盘录入一个整数，表示接下来要录入的字符串的数量。
紧接着根据这个数量，从键盘连续录入字符串，每次都会将一整行键盘录入成一个字符串
这些被录入的字符串需要存入一个字符串数组，然后将该字符串数组按照以下两种规则排序遍历打印：
1.按照字符串的长度，从长到短排序
2.先按照字符串的长度从短到长排序
长度一致的字符串按照字典顺序排序。
程序的执行图，大致如下：
注意：
使用fgets读一整行字符串的话，不要忘记去除字符串中的换行符。
假设每个字符串的长度都不会超过1024.
*/

int cmp_from_long_to_short(const void* a, const void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;
	if (strlen(str1) != strlen(str2))
		return strlen(str2) - strlen(str1);
	return strcmp(str1, str2);
}

int cmp_from_short_to_long(const void* a, const void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;

	if (strlen(str1) != strlen(str2))
		return strlen(str1) - strlen(str2);
	return strcmp(str1, str2);
}

void print_str(char** str, int n) {
	for (int i = 0; i < n; i++)
		printf("%s\n", str[i]);
}

int main(void) {
	int n;
	printf("请输入字符串数组的长度：");
	scanf("%d", &n);
	int c;
	while ((c = getchar()) != '\n'); // getchar之前一定要清输入缓冲区
	// 特别是getchar之前有scanf时

//char* str[];
	char** str = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		str[i] = (char*)malloc(1024 * sizeof(char));
		int j = 0;
		printf("请输入第 %d 个字符串：", i + 1);
		while ((str[i][j] = getchar()) != '\n') {
			j++;
		}
		str[i][j] = '\0';
	}

	qsort(str, n, sizeof(char*), cmp_from_long_to_short);
	printf("按长度从长到短排序的结果：\n");
	print_str(str, n);

	qsort(str, n, sizeof(char*), cmp_from_short_to_long);
	printf("按长度从短到长排序，长度一致时按照字典顺序的结果：\n");
	print_str(str, n);

	for (int i = 0; i < n; i++)
		free(str[i]);
	free(str);
	return 0;
}