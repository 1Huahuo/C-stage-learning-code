#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 如果选择w模式打开文件，此模式一定会操作改变原文件：
//		若原文件不存在，则新建一个空的文件
//		若原文件存在，将原文件截断清空数据

void test1() {
	FILE* fp = fopen("2.txt", "w");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('d', fp);
	fputc('\n', fp);
	fputc('e', fp);
	fputc('f', fp);
	fputc('g', fp);

	fclose(fp);
}


int main(void) {
	test1();

	return 0;
}