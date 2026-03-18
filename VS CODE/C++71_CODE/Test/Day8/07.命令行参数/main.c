#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*

*/

int main(int argc, char *argv[]) { // 用指针数组来保存命令行参数
	// 在C程序中，可以接收到外部给的参数，在“main函数”这里处理。 
	// main(void)表明不接受参数。
	// main(int argc, char *argv[])
	// 第一个参数：传进来了几个参数；第二个参数：参数分别是什么(以字符串为单位)

	printf("argc = %d\n", argc);

	for (int i = 0; i < argc; i++) {
		char* arg = argv[i];
		printf("argv[i]：%s\n", arg); // 命令行参数本质上就是字符串，所以说明符为%s
	}

	// 最少可以接受到一个参数，用户输入的全是额外参数
	// argc = 1时，argv[0] 是程序的路径 argv[1]开始才是额外参数

	return 0;
}