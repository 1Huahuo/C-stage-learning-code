#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

void test1() {
	// 字符串字面值： 是使用字符数组存储。\0 结尾。、 
	// 存储位置，是在 只读数据段上。 
	printf("%s", "hello world");

	// 大小是6.  hello占5. \0 自动补一个。 
	printf("%d\n", sizeof("hello"));

	// p指针，指向只读数据段这块空间。 
	char* p = "nihao";

	*p = 'H'; // 只读数据段是无法修改的，一修改就报错。
	printf("%c", *p++);
	printf("%c", *p++);
	printf("%c", *p++);
	printf("%c", *p++);
	// 返回一个非0值，并且没有修改成功
}


void test2() {
	// 以下场景中，"hello"在代码中会被视为数组名，也即首元素指针

	// &"hello"是允许的，类型是 char (*)[6]，即指向6个字符数组的指针类型。但这种语法不常见，了解即可
	char* p2 = &"hello";    // 隐式类型转换，指针——>数组指针

	// 既然被视为数组名，就支持索引运算。字符c1此时是'o'
	char c1 = "hello"[4];

	// 指针p_element指向字符'o'
	char* p_element = "hello" + 4;

	// 索引运算就是算术运算和解引用运算的语法糖。字符c此时是'o'
	char c2 = *("hello" + 4); // c2也是'o'
}

int main(void) {
	//test1();
	test2();

	printf("1\n");
}