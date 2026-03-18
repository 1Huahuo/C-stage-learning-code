#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
首先给定以下字符数组：
char* strings[] = {
 "4show ",
 "1code.",
 "5cheap, ",
 "6is ",
 "7Talk ",
 "2the ",
 "3me "
};
请你先利用qsort函数将此字符串数组,按照逆字典顺序排序。
然后将这个字符串数组中的每一个字符串，按照从前到后的顺序，拼接组装成一个新字符串，
并且在拼接时删除每个子字符串的第一个字符。
这样你将得到Linux之父Linus Torvalds的名言：“Talk is cheap, show me the code.”
要求使用动态分配内存来存储结果字符串，函数声明如下：
char* concat_strs(char* strings[], int count);
*/

int cmp(const void* a, const void* b) {
	char* pa = *(char**)a;
	char* pb = *(char**)b;
	return -strcmp(pa, pb);
}

void my_strcat(char str1[], char str2[]) {
	while (*str1 != '\0')
		str1++;
	str2++;
	while (*str2 != '\0')
		*str1++ = *str2++;
	*str1 = '\0';
}

char* concat_strs(char* strings[], int count) {
	char* str = (char*)calloc(count, sizeof("5cheap, "));
	for (int i = 0; i < count; i++)
		my_strcat(str, strings[i]);
	return str;
}

int main(void) {
	char* strings[] = { "4show ","1code.","5cheap, ","6is ","7Talk ","2the ","3me " };
	//printf("%d\n", strlen(strings[2]));
	qsort(strings, 7, sizeof(char*), cmp);
	//for (int i = 0; i < 7; i++)
	//	printf("%s\n", strings[i]);

	char* str = concat_strs(strings, 7);
	printf("%s\n", str);

	free(str);
	return 0;
}