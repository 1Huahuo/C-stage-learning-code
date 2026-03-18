#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	FILE* fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	// 使用
	int ch1 = fgetc(fp);
	printf("ch1 = %c\n", ch1);

	int ch2 = fgetc(fp);
	printf("ch2 = %c\n", ch2);

	// fgetc 就是从文件中，一个字节一个字节的拿数据,第一个字节拿完，拿第二个、第三个...
	// 等到所有的数据都拿完之后，返回一个终止标志 EOF即-1

	printf("ch3 = %c\n", fgetc(fp));
	printf("ch4 = %c\n", fgetc(fp));
	printf("ch5 = %c\n", fgetc(fp));
	printf("ch6 = %c\n", fgetc(fp));
	printf("ch7 = %c\n", fgetc(fp));
	printf("ch8 = %c\n", fgetc(fp));
	printf("ch9 = %c\n", fgetc(fp)); // 以字符形式输出 EOF
	printf("ch10 = %c\n", fgetc(fp)); // 以字符形式输出 EOF
	printf("ch11 = %d\n", fgetc(fp)); // 以整型形式输出 -1
	printf("ch12 = %d\n", fgetc(fp)); // 以整型形式输出 -1

	fclose(fp);
}



void test2() {
	FILE* fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}
	// 在fgetc中，会一个字节一个字节拿，最终终止的标识符是 -1
	int ch;
	while ((ch = fgetc(fp)) != -1) {
		printf("-------%c\n", ch);
	}

	fclose(fp);
}

int main(void) {
	//test1();
	test2(); 

	return 0;
}