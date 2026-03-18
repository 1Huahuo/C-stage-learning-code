#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 现在，需要完成1.txt 的复制。 
	
	FILE* src_fp = fopen("1.txt", "r");
	if (src_fp == NULL) {
		printf("fopen src failed.\n");
		return;
	}

	FILE* dest_fp = fopen("1_copy.txt", "w");
	if (dest_fp == NULL) {
		printf("fopen dest failed.\n");
		fclose(src_fp);
		return;
	}

	int ch;
	while ((ch = fgetc(src_fp)) != -1) {
		printf("-------%d------%c\n", ch, ch);
		fputc(ch, dest_fp);
	}

	fclose(src_fp);
	fclose(dest_fp);
}

int main(void) {
	test1();

	return 0;
}