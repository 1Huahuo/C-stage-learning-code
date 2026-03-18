#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
在网盘项目中，常需要保存文件的元数据（如文件名、大小）。定义一个文件信息结构体 `FileInfo`，
将其实例以二进制块的方式写入磁盘，再重新读入内存。
要求：
1. 定义结构体 `FileInfo`，包含 `char filename[64]` 和 `long filesize`。
2. 使用 `fwrite()` 将结构体变量整体写入 `index.db`。
3. 使用 `fread()` 将数据读回到新的结构体变量中并输出。
*/

typedef struct {
	char filename[64];
	long filesize;
}FileInfo;

int main(void) {
	FILE* fp = fopen("index.db", "wb");
	if (fp == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return -1;
	}

	FileInfo f1 = { "baiduwangpan", 123 };
	fwrite(&f1, sizeof(f1), 1, fp);
	fclose(fp);

	fp = fopen("index.db", "rb");
	if (fp == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return -1;
	}
	FileInfo f2 = { 0 };
	fread(&f2, sizeof(f2), 1, fp);
	fclose(fp);
	printf("filename:%s,filesize:%ld\n", f2.filename, f2.filesize);

	return 0;
}