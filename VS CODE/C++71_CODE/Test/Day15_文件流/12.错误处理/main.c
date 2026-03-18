#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h> // errno全局变量、perror函数
#include <string.h> // strerror函数

void test1() {
	printf("errno1 = %d\n", errno);
	printf("--------%s\n", strerror(errno));
	// C中没有错误处理，基本上只能通过返回值告诉你出错了。 
	FILE* fp = fopen("1.txt", "r");

	printf("errno2 = %d\n", errno);
	printf("--------%s\n", strerror(errno));
	printf("--------%s\n", strerror(1));
	printf("--------%s\n", strerror(2));
	printf("--------%s\n", strerror(3));
	printf("--------%s\n", strerror(4));

	// fp如果打开失败了，具体是什么原因导致的失败

	// C提供了一个全局变量errno，就是用于记录错误原因，出错之后取这个全局变量，就能知道出错原因
}

void test2() {
	// 直接让它打印错误信息——void perror(const char *s);
	//perror(NULL);
	perror("1111");
	FILE* fp = fopen("1.txt", "r");
	perror("1.txt");
	//perror(NULL);

	// perror用于打印信息，给进去的字符串，就是特征性的描述，加到错误信息之前 
}


int main(void) {

	//test1();
	test2();

	return 0;
}