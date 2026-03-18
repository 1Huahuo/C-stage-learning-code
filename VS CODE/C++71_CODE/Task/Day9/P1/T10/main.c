#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
先在堆上申请创建一个长度为10的int数组，
编写一个函数用于以"[xx, xx, ..., xx]"的格式打印这个int数组。
紧接着执行以下操作：
	在申请int数组成功后，直接调用函数打印这个int数组，思考一下：应该用哪个函数来申请创建这个数组？
	截断这个int数组，将其变为长度为5的int数组，然后再打印这个数组。
	将长度为5的int数组，再次扩容回10个元素，将最后五个元素初始化为888，最后再次打印这个数组。
	最后不要忘记free释放内存块。
非常简单且基础的语法练习题，如果还不太会做，不妨直接查看参考代码。
重点需要注意realloc函数的调用格式！
*/

void print_arr(int* a, int n) {
	printf("[%d", a[0]);
	for (int i = 1; i < n; i++)
		printf(", %d", a[i]);
	printf("]\n");
}

int main(void) {
	int n = 10;
	int* a = (int*)malloc(n * sizeof(int));
	printf("enter 10 number:");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	print_arr(a, n);

	n = 5;
	int* b = (int*)realloc(a, n * sizeof(int)); // 第二个参数是字节数，不是元素个数！
	print_arr(b, n);
	printf("%d\n", a == b);

	n = 10;
	int* c = (int*)realloc(a, n * sizeof(int));
	for (int i = 5; i < n; i++)
		*(c+i) = 888; // c[i] = 888; 最好以指针操作为主，不会有警告
	print_arr(c, n);
	printf("%d\n", a == c);

	free(a);
	a = b = c = NULL;

	return 0;
}