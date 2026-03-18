#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
编写一个C程序，实现以下功能：
1.程序尝试以"r"模式，打开一个名为 "1.txt" 的文件进行读操作。
2.如果文件成功打开，程序则读取文件的第一行内容，并将其输出到终端上。
3.如果文件打开失败，程序应使用 perror 函数打印此文件名以及相关错误信息，并输出 errno 当前的值。
把代码编写完成后，执行以下操作从而测试代码：
1.一开始，1.txt文件不存在，观察程序的输出。
2.在工作目录下创建1.txt文件，并在文件开头手动写入一行字符串，再观察程序的输出。
3.将1.txt文件的权限改成只读模式，然后将打开模式改成"a"模式，尝试写入一行字符串，观察程序的输出。
4.将1.txt文件的权限重新改为正常模式，再尝试写入一行字符串，观察程序的输出。
*/

int main(void) {
	/*FILE* fp = fopen("1.txt", "r");
	if (fp == NULL) {
		printf("%d\n", errno);
		puts(strerror(errno));
		perror("1.txt");
		return -1;
	}
	char buffer[1024];
	fgets(buffer, 1024, fp);
	printf("%s\n", buffer);*/

	//FILE* fp = fopen("1.txt", "a");
	// if (fp == NULL) {
	//	printf("%d\n", errno);
	//	puts(strerror(errno));
	//	perror("1.txt");
	//	return -1;
	//}
	//char str[] = "hello";
	//fputs(str, fp);
	//char buffer[1024] = { 0 };
	////fseek(fp, 0L, SEEK_SET); // 没有用，a模式，读时指针在文件开头，写时在文件结尾
	//fgets(buffer, 1024, fp);
	//printf("%s\n", buffer);

	FILE* fp = fopen("1.txt", "w+");
	if (fp == NULL) {
		printf("%d\n", errno);
		puts(strerror(errno));
		perror("1.txt");
		return -1;
	}
	char str[] = "hello";
	fputs(str, fp);
	char buffer[1024] = { 0 };
	fseek(fp, 0L, SEEK_SET);
	fgets(buffer, 1024, fp);
	printf("%s\n", buffer);

	fclose(fp);
	return 0;
}