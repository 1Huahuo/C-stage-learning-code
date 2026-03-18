#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*

*/

void test1() {
	//char str1[50] = {'n', 'i', 'h', 'a', 'o', 'z', 'h'....};
	char str1[50] = "nihaozhangsan jinwan ganfan";
	// str1 这个只是一个简写形式。 
	// 它和上面的写法是一个意思。 

	char str2[] = "hello"; // 6
	char str3[5] = "hello"; // 5
	char str4[20] = "hello"; // 20

}


void test2() {
	char str[] = "Showmaker"; // 这块空间，在栈上，可以修改的。
	char* p = "Showmaker"; // 不可修改
	// 均代表字符串
	// 第一种写法，只是一个语法糖，它的本质，其实还是数组的初始化。 
	printf("%s\n", str);

	str[0] = 's';
	str[1] = 'H';
	printf("%s\n", str);

	printf("%s\n", p);
	p[0] = 's';
	p[1] = 'H';
	printf("%s\n", p); // 无法成功执行，报错，返回非0值
}

int main(void) {
	test2();

	//printf("1\n");
}