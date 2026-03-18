#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
用户输入文件名，将整个文件的内容读入到字符数组中，并在后面添加空字符'\0'。
 char* read_file(const char* path);
分析思路：
1.打开文件，以只读模式打开即可。不要忘记进行打开失败，错误处理。（在Windows平台下，应该以rb只读模式打开）
2.此案例中文件的大小只能在运行时期确定，所以需要动态内存分配一个字符数组用于存储结果字符串。
3.结果字符串的长度 = 文件字节大小 + 1
4.文件字节大小怎么算？用ftell函数配合fseek函数即可计算。
5.利用fread函数一次性将整个文件中的数据，全部读到结果字符数组中，然后自己在末尾加一个空字符。
*/

char* read_file(const char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return NULL;
	}

	fseek(fp, 0L, SEEK_END);
	long int file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char* str = (char*)malloc(file_size + 1);
	if (str == NULL) {
		printf("error:malloc failed in read_file.\n");
		fclose(fp);
		return NULL;
	}

	size_t read_count = fread(str, 1, file_size, fp);
	if (read_count != file_size) {
		printf("fread failed.\n");
		free(str);
		fclose(fp);
		return NULL;
	}
	str[file_size] = '\0';

	fclose(fp);
	return str;
}

int main(void) {


	return 0;
}