#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	// fopen 用于打开一个文件流。 
	// 入参有两个：
	//		第一个是路径（绝对路径/相对路径）
	//		第二个是打开的模式，也就是打开用于读还是写

	// 返回值：返回的是FILE * 结构体指针
	//		结构体指针用于存储文件的一些信息，但是具体的字段不用关心
	//		这个东西，只是一个 “信物”，用于给后续的函数使用。 

	FILE* fp = fopen("1.txt", "r"); // 只读

	// 打开一个文件，有两种情况：打开成功/打开失败
	if (fp == NULL) { // fp为NULL，表明打开失败。
		printf("fopen failed.\n");
		return;
	}

	// 打开成功
	printf("fopen success.\n");

	return 0;
}