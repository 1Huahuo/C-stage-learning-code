#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
请自行熟悉文件流的操作函数，实现以下文件流基础操作：
*/

// 1.逐字符文本文件复制，函数声明是：
void copy_file_char(const char* src_file, const char* dest_file) {
	FILE* fp1 = fopen(dest_file, "w");
	FILE* fp2 = fopen(src_file, "r");

	if (fp1 == NULL || fp2 == NULL) {
		printf("文件打开失败！\n");
		return;
	}

	int c;
	while ((c = fgetc(fp2)) != EOF)
		fputc(c, fp1);

	fclose(fp1);
	fclose(fp2);
}

// 2.逐行文本文件复制，函数声明式：
void copy_file_line(const char* src_file, const char* dest_file) {
	FILE* fp1 = fopen(dest_file, "w");
	FILE* fp2 = fopen(src_file, "r");

	if (fp1 == NULL || fp2 == NULL) {
		printf("文件打开失败！\n");
		return;
	}

	char buffer[1024] = { 0 };
	while (fgets(buffer, sizeof(buffer), fp2) != NULL)
		fputs(buffer, fp1);

	fclose(fp1);
	fclose(fp2);
}

// 3.用fread和fwrite函数实现二进制文件的复制, 函数声明如下：
void binary_file_cpy(const char* src_file, const char* dest_file) {
	FILE* fp1 = fopen(dest_file, "wb");
	FILE* fp2 = fopen(src_file, "rb");

	if (fp1 == NULL || fp2 == NULL) {
		printf("文件打开失败！\n");
		return;
	}

	char buffer[4096];
	size_t read_count;
	while ((read_count = fread(buffer, 1, sizeof(buffer), fp2)) > 0)
		fwrite(buffer, 1, read_count, fp1);

	fclose(fp1);
	fclose(fp2);
}

typedef struct {
	char name[25];
	int age;
	char gender;
} Student;

// 4.用fread和fwrite函数实现二进制的序列化和反序列化操作。
// 此操作可以不提取函数，直接在main函数中实现即可。但只允许使用一个FILE流。
int main(void) {
	Student s1 = { "hello", 18, 'm' };

	FILE* fp1 = fopen("1.dat", "wb");
	if (fp1 == NULL) {
		fprintf(stderr, "无法打开文件 1.dat 用于写入\n");
		exit(1); // #include <stdlib.h>
	}
	fwrite(&s1, sizeof(Student), 1, fp1);
	fclose(fp1);

	FILE* fp2 = fopen("1.dat", "rb");
	if (fp2 == NULL) {
		fprintf(stderr, "无法打开文件 1.dat 用于读取\n");
		exit(1);
	}
	Student s2;
	fread(&s2, sizeof(Student), 1, fp2);
	fclose(fp2);

	printf("Name:%s\nAge:%d\nGender:%c\n", s2.name, s2.age, s2.gender);
	return 0;
}