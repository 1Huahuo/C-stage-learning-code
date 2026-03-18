#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
只申请内存，但在使用完毕之后不释放，最终会导致内存泄露
程序中可用的内存越来越少，最终会导致程序无法运行。

free只能传入堆区的数据，不能传栈区的
	1.不要将栈区的数据放进去。
	2.只能放申请得到的堆区的首字节指针。
如果传递的不是首地址，而是后面的指针，同样报错
*/

// 对栈上空间free，对非首地址free——均为未定义操作
void test1() {
	//int arr[10] = { 10,11,12,13 };
	//free(arr);
	//int *p = arr;
	//free(p); // 报错，不能释放栈上的内存

	int* q = malloc(24);
	for (int i = 0; i < 6; i++) {
		q[i] = i + 100;
		printf("%d\n", q[i]);
	}

	//free(q); // 正常释放

	*q++ = 10;
	*q++ = 20;
	free(q); // 报错，不能对非申请空间的首地址释放

}

// 如果移动指针的操作
// 建议再定义一个指针，存储旧指针，最后释放旧指针，以此来防止丢失首地址造成内存泄漏
void test2() {
	
	int* p = malloc(24);

	int* old_p = p;

	*p++ = 10;
	*p++ = 11;
	*p++ = 12;
	*p++ = 13;
	*p++ = 14;

	free(old_p);
}

// double free——对同样一块内存free释放了两次——
void test3() {
	int* p = malloc(40);
	free(p);
	free(p); // 报错，不能free同一个申请空间首地址两次
}

int main(void) {
	int* a = malloc(3 * sizeof(int));

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	for (int i = 0; i < 3; i++)
		printf("%d\n", a[i]);

	free(a); // 释放空间，并未释放指针a

	a[2] = 2; // 操作可运行，但不合法，对已释放的内存操作
	printf("a[2] = %d\n", a[2]);

	printf("a[2] = %d\n", a[1]); // 申请的空间释放后，空间内数据会被清空变成其他值并不会保留
	char* p = malloc(100);
	strcpy(p, "Hello World");  // 存入数据
	printf("%s\n", p);         // 正常输出 "Hello World"
	free(p);
	//printf("%s\n", p);         // 输出乱码，VS在释放瞬间主动填充0xDD来替换原本数据

	printf("-----------------------------\n");
	//test1();
	test2();
	//test3();

	return 0;
}