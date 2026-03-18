#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[25];
    int age;
    char gender;
} Student;

// 二进制文件的序列化和反序列化
void main1() {
    Student s1 = { "hello", 18, 'm' };

// .dat 是一种通用、无固定格式的文件后缀名，它本身不代表一种特定的文件类型，
//      只是用来存放二进制数据或自定义格式数据的 “容器”。

    // 序列化：将结构体对象写入文件
    FILE* fp = fopen("1.dat", "wb");
    if (fp == NULL) {
        fprintf(stderr, "无法打开文件 1.bin 用于写入\n");
        exit(1);
    }
    // 用fwrite进行序列化操作更简洁，效率也会更高
    fwrite(&s1, sizeof(s1), 1, fp);
    fclose(fp); // 序列化结束关闭文件

    // 用fread进行反序列化操作更简洁，效率也会更高
    fp = fopen("1.dat", "rb");  // 重新打开文件，确保文件指针处于文件开头
    if (fp == NULL) {
        fprintf(stderr, "无法打开文件 1.bin 用于读取\n");
        exit(1);
    }
    Student s2;
    fread(&s2, sizeof(s2), 1, fp);
    fclose(fp);

    // 打印读取的数据，以验证反序列化是否成功
    printf("Name: %s\nAge: %d\nGender: %c\n", s2.name, s2.age, s2.gender);
}

int main(void) {
	

    main1();

	return 0;
}