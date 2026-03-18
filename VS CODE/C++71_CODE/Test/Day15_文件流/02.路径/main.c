#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 路径分两种：
	// 1.绝对路径 ：windwos从盘符开始。 C:\cproject\1.txt 
	//				Linux 从 / 开始，例如：/home/zhou/2222.txt
	// 2.相对路径 ：从某一个位置开始，也就是需要知道相对路径的起点，才能知道路径

	//FILE *fp = fopen("C:\\Users\\zhoubing\\Desktop\\cpp71_code\\Day15_文件流\\03_路径\\666.txt","r");
	FILE* fp = fopen("C:\\Users\\zhoubing\\Desktop\\cpp71_code\\Day15_文件流\\03_路径\\777.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");
}

void test2() {
	// 在工作中，使用相对路径居多。 
	// 相对路径的起点是： 当前“项目”根目录，例如：当前源文件的项目根目录就是“02.路径”
	//FILE *fp = fopen("777.txt", "r");
	//FILE *fp = fopen("888.txt", "r");
	FILE* fp = fopen("test1\\test2\\123123.txt", "r"); // C语言中用\\来代表\

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");
}


int main(void) {

	//test1();
	test2();

	return 0;
}