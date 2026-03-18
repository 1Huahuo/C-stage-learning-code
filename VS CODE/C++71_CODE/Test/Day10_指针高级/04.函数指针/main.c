#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

typedef int DataType;

// 函数指针区别名
typedef int (*FuncPtr)(int, int); // int (*ptr1)(int, int); 等价 Funcptr ptr1;

void test0() {
	printf("test2 test.\n");
}

void test1() {
	// ptr1 就是一个函数指针。 
	//FuncPtr ptr1; // int (*ptr1)(int, int);

   // int num; 与 Funcptr ptr2;
   // FuncPtr： 别名，相当于是int 是类型
   // ptr2: 是一个变量，相当于是num


}

// 函数指针初始化
void test2() {
	// func_ptr1: 直接使用函数名，给一个函数指针初始化。 
	void (*func_ptr1)(void) = test0;

	// 函数指针怎样使用。  (*指针名)(); 其实*可以省略，因为C会在表达式中对其自动转换
	(*func_ptr1)();
	func_ptr1(); // 推荐这种, 函数指针会自动转换成函数
}

int test3(int a, int b) {
	//printf("test4 test.\n");
	printf("test5 test.\n");
	return a + b + 100;
}

void test4() {
	// 入参两个int，返回值int
	int (*func_ptr1)(int, int) = test3;

	//int res = (*func_ptr1)(10, 20);
	int res = func_ptr1(10, 20); // 两种形式均可
	printf("res = %d\n", res);
}

void test5() {
	int (*func_ptr2)(int, int) = test3; // 函数指针声明时*是必写的，这个没法省略
	//printf("res = %d\n", (*func_ptr2)(10, 20));
	printf("res = %d\n", func_ptr2(10, 20));
}

void compute_and_show(int num1, int num2, int ptr1(int, int)) {
	printf("compute result = %d\n", ptr1(num1, num2));
}

int sum(int num1, int num2) {
	return num1 + num2;
}
int sub(int num1, int num2) {
	return num1 - num2;
}

int mul(int num1, int num2) {
	return num1 * num2;
}

int main(void) {
	//test2();
	//test4();
	//test5();

	// 函数指针，就是传递函数的，为后续的扩展留下可能
	// 函数指针的作用：就是一个指向函数的指针，传递这个指针，就等价于传递这个函数
	// 传递函数的作用：可以在不改动代码的情况下，传进自己的特定逻辑
	// 例如：
	compute_and_show(10, 20, sum);
	compute_and_show(10, 20, sub);
	compute_and_show(10, 20, mul);

	return 0;
}