#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
指针数组，是数组。 这个数组里面是装指针的。
数组指针，是指针。 这个指针是指向数组的。 +1偏移量不一样。
*/

void pointer_array() {
	// 指针数组： 是一个数组，数组里面装的一个一个的指针。 

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	// 地址中0值——即NULL(空地址)
	int* p1[6] = { &a, &b, &c, &d, &e }; // p1[5] = NULL;

	printf("%d\n", *p1[0]);
	printf("%d\n", *p1[1]);
	printf("%d\n", *p1[2]);
	printf("%d\n", *p1[3]);
	printf("%d\n", *p1[4]);
	*p1[0] = 888;
	printf("%d\n", *p1[0]);
	printf("%d\n", a);
}

void array_pointer() {
	// 数组指针。指针，指向数组 
	int arr[5] = { 10,20,30,40,50 };
	// 得到的是整个数组的地址。 或者说&arr现在是一个数组指针。 

	// 数组指针， +1 偏移 数组占据的空间大小个字节。
	int (*p1)[5] = &arr; // +1——即+20(B)
}

int main(void) {
	// []  优先级高。  *的优先级低。 
	// [] 优先级高，所以上来就决定了它是个数组。 
	int* p1[10];

	// (*p2): 是个指针，指向int[5]
	int (*p2)[5]; // 是一个数组指针。

	pointer_array();

	printf("1\n");
}