#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个C程序，实现一个简易的文件拷贝功能。
要求以字节为单位从 `source.dat` 读取内容，并将其逐个写入到 `dest.dat` 中。
要求：
1. 使用 `fopen()` 以二进制模式打开文件。
2. 使用 `fgetc()` 和 `fputc()` 函数进行字节级的读写操作。
3. 循环读取直到文件末尾（EOF）。
4. 操作完成后务必关闭所有文件流。
*/

int main(void) {
	FILE* fp1 = fopen("source.dat", "rb");
	FILE* fp2 = fopen("dest.dat", "wb");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return -1;
	}

	int c;
	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}