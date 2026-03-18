#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 文件流操作的标准步骤
	// 
	// 1.打开文件流
	FILE* fp = fopen("1.txt", "r");

	// 2.检查是否打开成功
	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	// 3.使用
	// fgetc fputc fgets fputs fscanf fprintf 都是在对流的操作。 

	// 4.关闭文件流——；类似于free，不要忘记关闭文件流
	fclose(fp);
}



int main(void) {

	return 0;
}