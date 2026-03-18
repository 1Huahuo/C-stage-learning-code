#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// free的时候崩溃了怎么查：
// 要顺着数据的链条来查，每个p从哪来，被谁改过，给的p具体是什么值 
void test3(int* p) {
	free(p);

	 //free(p - 1); // 正常释放
	 //printf("already released\n");
}

void test2(int* p) {
	test3(p + 1);
}


void test1() {
	int* p = malloc(40);
	test2(p);
}



int main(void) {
	test1(); 
	// 报错， 原因：
	// test1调用test2并将p传入其中
	// 而test2再次调用test3，并且在调用的时候将p+1传入到test3
	// test3把p+1当作申请空间首地址p，free(p)即对非首地址free，所以产生未定义行为

	return 0;
}