#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
在main函数当中，先写出下列代码，用两种不同的方式来定义实现字符串数组：
// char类型二维数组实现字符串数组
char fruits1[][10] = {
"apple",
"banana",
"cherry"
};
// char*指针数组实现字符串数组
char *fruits2[] = {
"apple",
"banana",
"cherry"
};
请完成以下编程或者回答相应的问题。
*/

void test(char fruits1[][10], char* fruits2[]);

// 题目一：
// 请分别遍历 fruits1 和 fruits2这两个字符串数组，输出每个字符串的内容及其长度。
//void q1(char fruits1[][10], char* fruits2[]) {
//	for (int i = 0; i < 3; i++)
//		printf("%s\n", fruits1[i]); // 或*(fruits1 + i)
//	printf("------------------------------------------\n");
//	for (int i = 0; i < 3; i++)
//		printf("%s\n", fruits2[i]); // 或*(fruits2 + i)
//}

// 题目二：
// 请分别将两个字符串数组中的第一个字符串，修改成"orange"。
// 首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？
// 提示：通过一定的手段，两个都可以完成修改。参考代码仅提供一种实现方式，若你能够实现，亦可采用自己的实现。
void q2(char fruits1[][10], char* fruits2[]) {
	// fruits1[0] = "orange"; 不允许，因为 fruits1[0] 是数组名，数组名是不能用"="重新赋值的。
	// fruits2[0] = "orange"; 允许，因为 fruits2[0] 就是一个指针元素，指针是可以用"="改变指向的。
	
	// ①一个字符一个字符的读入	            
	char c;
	int i;
	printf("enter orange:");
	for (i = 0; (c = getchar()) != '\n'; i++) { 
		fruits1[0][i] = c;
	}
	fruits1[0][i] = '\0';
	// ②或strcpy(fruits1[0], "orange");

	//char str[] = "orange"; // 此为局部变量，修改效果无法延续到主函数
	//fruits2[0] = &str;
	// ①<stdlib.h>，主函数中再释放
	fruits2[0] = (char*)malloc(strlen("orange") + 1); // 或sizeof("orange")
	strcpy(fruits2[0], "orange");
	// ②或
	//fruits2[0] = "orange"; // 字符串字面值在只读数据区，函数返回后仍存活
	//*fruits2[0] = "orange"; 注：这样是错误的，因为等号左边是一个字符

	printf("%s\n", fruits1[0]);
	printf("%s\n", fruits2[0]);

}

// 题目三：
// 请分别将两个字符串数组中的第二个字符串"banana"中的第一个字符'b'，修改成'B'。
// 首先你需要回答：基于"="运算符直接赋值修改，能不能完成这样的操作？如果不能为什么？
// 提示：通过一定的手段，两个都可以完成修改。参考代码仅提供一种实现方式，
// 若你能够实现，亦可采用自己的实现。
void q3(char fruits1[][10], char* fruits2[]) {
	// 1能，2不能，字符串字面值在只读数据区，无法修改
	fruits1[1][0] = 'B';
	//fruits2[1][0] = 'B';c

	// 法①
	fruits2[1] = "Banana";
	// 法②—限定于主函数，否则传不回去，因为此时是局部变量
	//char banana_str[] = "banana";   // 栈上存储的字符串"banana"
	//fruits2[1] = banana_str;    // 修改指针的指向
	//fruits2[1][0] = 'B';  //修改成功

	printf("%s\n", fruits1[1]);
	printf("%s\n", fruits2[1]);
}

// 题目四：
// 请自行定义初始化一个字符串数组fruits3，
// 使得这个字符串数组既可以通过"="直接修改整个字符串的内容，
// 也可以利用"="修改某个字符串的某个字符。
// 提示：实现方式不唯一，参考代码仅提供一种实现参考。
void q4() { // 字符串变量+指针数组：相当于二级指针？
	char str1[] = "apple";
	char str2[] = "banana";
	char str3[] = "cherry";
	// fruits3是指针数组，指向字符串变量首地址的数组
	char* fruits3[] = { str1, str2, str3 };

	// 修改字符串内容——外层用指针数组，可以随时替换任意一整个字符串
	//strcpy(fruits3[0], "orange");
	fruits3[0] = "orange";
	// 修改单个字符——内层用字符串变量(地址)，保证单个字符内容可修改
	fruits3[1][0] = 'B';

	for (int i = 0; i < 3; i++)
		printf("fruits3[%d]: %s\n", i, fruits3[i]);

}

int main(void) {
	char fruits1[][10] = { "apple","banana","cherry" };
	char* fruits2[] = { "apple","banana","cherry" };
	//printf("fruits2[0] = %d\n", sizeof(fruits2[0])); // 8
	//printf("fruits2[1] = %d\n", sizeof(fruits2[1])); // 8
	//printf("fruits2[2] = %d\n", sizeof(fruits2[2])); // 8

	//q1(fruits1, fruits2);
	// 问题一（修正）：
	//int size2 = sizeof(fruits2) / sizeof(fruits2[0]);
	//printf("fruits2_elem_nums = %d\n", size2);		 // 3
	//int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
	//printf("fruits1_elem_nums = %d\n", size1);		 // 3
	//printf("Fruits1:\n");
	//for (int i = 0; i < size1; ++i) {
	//	printf("第%d个字符串是:%s, 字符串长度是:%zu\n", (i + 1), fruits1[i], strlen(fruits1[i]));
	//}
	//printf("\nFruits2:\n");
	//for (int i = 0; i < size2; ++i) {
	//	printf("第%d个字符串是:%s, 字符串长度是:%zu\n", (i + 1), fruits2[i], strlen(fruits2[i]));
	//}

	q2(fruits1, fruits2);

	//q3(fruits1, fruits2);

	//q4();

	//test(fruits1, fruits2);

	//printf("%s\n", fruits2[0]);
	return 0;
}

void test(char fruits1[][10], char* fruits2[]) {
	// 通过调用计算是不会得到正确答案的，因为数组作为函数参数时传送会退化为指针！！！
	// 所以计算元素大小与个数时最好在主函数中进行

	// 虽然逻辑上它们加上结尾空字符所占空间大小分别为：6,7,7
	// 但64位系统默认8字节(即一个计算机字长)对齐, 所以实际：
	printf("fruits2[0] = %d\n", strlen("apple") + 1);  // 6  "apple" ：实际size: 8
	printf("fruits2[1] = %d\n", strlen("banana") + 1); // 7  "banana"：实际size: 8
	printf("fruits2[2] = %d\n", strlen("cherry") + 1); // 7  "cherry"：实际size: 8

	int size2 = sizeof(fruits2) / sizeof(fruits2[0]);
	printf("fruits2_elem_nums = %d\n", size2); // 1

	int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
	printf("fruits1_elem_nums = %d\n", size1); // 0
}
