#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 如果在代码中，写一个 \n
	char ch = '\n';
	// 换行符在
	// windonws中	\r\n 
	// C中			\n   

	// 在代码中，fputc('\n') 最终存储到文件中，会存储 \r\n
	// 如果读的时候， 会将 \r\n----> \n

	// 所以一般在windows中要以二进制模式进行读取文件，即"rb""wb"

	FILE* fp = fopen("1.txt", "w");

	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('\n', fp);
	fputc('d', fp);
	fputc('d', fp);

	fclose(fp);
}


void test2() {
	FILE* fp = fopen("1.txt", "r");

	int ch;
	while ((ch = fgetc(fp)) != -1) { 
		printf("========%d========%c\n", ch, ch);
	}

	fclose(fp);
}

int main(void) {

	//test1();
	test2();

	return 0;
}