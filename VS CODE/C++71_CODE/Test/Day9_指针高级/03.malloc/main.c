#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
void *p = malloc(10 * sizeof(int));——代表从堆区中申请了40个字节。
返回值表明：申请得到的地址（空间是连续的，只返回首地址。）
返回值有两种情况：
	1.得到一个地址（非NULL）表明申请成功
	2.得到一个 NULL 表明申请失败
*/

void test1() {
	// 动态内存申请的标准步骤
	// 1.申请空间
	void* p = malloc(10 * sizeof(int));
	// 2.判断是否申请成功
	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}
	// 3.使用：直接当数组使用
	// p[0] = 0;不能直接使用，还需要转换一下类型，如：
	int* p_int = (int*)p;
	for (int i = 0; i < 10; i++) {
		p_int[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		printf("int:p_int[%d] = %d\n", i, p_int[i]);
	}
	// 4.释放。 
	free(p_int);
}

void test2() {
	// 申请20个char:
	//void *p = malloc(20 * sizeof(char));
	char* p = malloc(20 * sizeof(char));
	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}
	for (int i = 0; i < 20; i++) {
		p[i] = 'a' + i;
	}
	for (int i = 0; i < 20; i++) {
		printf("char:p[%d] = %c\n", i, p[i]);
	} // 连续内存
}

void test3() {
	// malloc不知道也不关心申请的是int还是char亦或是double
	// 而程序员需要知道和关心，程序员通过指针告诉它怎样对待这块内存
	//int *p = malloc(40);
	//float *p = malloc(40);
	float* p = malloc(10 * sizeof(int));
	if (p == NULL) {
		printf("malloc failed.\n");
		return;
	}
	for (int i = 0; i < 10; i++) {
		p[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("p[%d] = float:%f\n", i, p[i]);
	}
}

int main(void) {
	test1();
	printf("-------------------------\n");
	test2();
	printf("-------------------------\n");
	test3();

	return 0;
}