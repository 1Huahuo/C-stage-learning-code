#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*

*/

typedef struct student {
	int a;
	char b[10];
}Student;

Student create_s() {
	struct student s1 = { 1, "hello" };
	return s1;
}

void test1() {

	// 关于它存储的位置，怎么确定。 
	// 1. 字符串字面值"hello" 存储在只读数据段。 
	// 如果你用指针接收，就是只读数据段。 
	char* p = "zhangsan";


	// 2.如果左边的写法是一个数组，则不在只读数据段上，即使内容相同也与数据段上不是同一个字符串 
	// 存储的位置，完全取决于左值的具体类型 
	char str[20] = { 0 };
	strcpy(str, "zhangsan"); // 或char str[20] = { "zhangsan" };
	char str2[] = "lisihubei";
	char str21[] = { 'l', 'i', 's', 'i', 'h', 'u', 'b', 'e', 'i' };
	char str22[] = { 'l', 'i', 's', 'i', 'h', 'u', 'b', 'e', 'i' , '\0' };
}

int main(void) {
	struct student s2 = create_s();

	printf("%d\n", s2.a);
	printf("%s\n", s2.b);
	return 0;
}