#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 复制二进制文件即图片与视频

int main(int argc, char* argv[]) {
	FILE* fp1 = fopen(argv[1], "rb"); // 注意第一个参数为地址，所以不是"argv[1]"
	FILE* fp2 = fopen(argv[2], "wb"); // 传给agrv[]的就是文件名，而文件名就是文件地址

	int c = 0; // 使用int 可接收到EOF即文件结束符，因为其不在ASCII码中，整型值为-1
	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);
	
	return 0;
}