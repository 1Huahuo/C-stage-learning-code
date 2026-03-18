#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
*/

// 常量指针(Constant Pointer)
// 含义：指针本身是一个常量，指针无法指向一个新的对象。但可以利用该指针修改指向的对象！
void constant_pointer() {
	int a = 10;
	int b = 20;
	// p指针是一个常量,它无法指向新的对象,但利用该指针可以修改指向的对象
	int* const p = &a;  // const修饰的是指针p，所以指针p本身是一个常量
	*p = 30;
	// p = &b; error
}

// 指针常量(Pointer to Constant)
// 含义：无法利用指针修改指向的内容，但指针本身可以指向不同的对象。
void pointer_to_constant() {
	int a = 10;
	int b = 20;

	// 无法使用指针p修改变量a的取值,但该指针可以指向新的对象
	const int* p = &a;  // 也可以用"int const *p"; 此时const修饰的*p，也就是指针指向的对象是一个常量
	//*p = 30; error
	p = &b;
}

// 指向不可变内容的常量指针
// 两个语法综合一下，就得到一个"指向不可变内容的常量指针"（Constant Pointer to Constant）
// 这样的指针既不能修改指向，也无法修改指向的内容：
void constant_pointer_to_constant() {
	int a = 10;
	int b = 20;

	const int* const p = &a;
	// p = &b; error
	// *p = 30; error
}

int main(void) {
	

	printf("1\n");
}