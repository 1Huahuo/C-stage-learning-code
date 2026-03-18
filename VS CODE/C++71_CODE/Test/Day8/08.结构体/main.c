#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
结构体：给一组变量，规定一个名字
下一次使用结构体的时，可以直接认为结构体中就有这些变量
*/

// int num;
// 这个只是在定义一个自己的类型。 这个类型和int类似。 
 struct student {
	int student_id;
	char name[20];
	char gender;
	int chinese;
	int math;
	int english;
};
typedef struct student Student;

// 给结构体初始化：依次挨个赋值
// 如果初始化的个数不够，后续补0 
void test1() {
	struct student s1 = { 10, "zhangsan", 'm', 100,80,60 };
	struct student s2 = { 11, "lisi", 'm' };
	struct student s3 = { 12 };
	printf("id=%d, name=%s, gender=%c, chinese=%d, math=%d, english=%d\n",
		s1.student_id, s1.name, s1.gender, s1.chinese, s1.math, s1.english);
	printf("id=%d, name=%s, gender=%c, chinese=%d, math=%d, english=%d\n",
		s2.student_id, s2.name, s2.gender, s2.chinese, s2.math, s2.english);
	printf("id=%d, name=%s, gender=%c, chinese=%d, math=%d, english=%d\n",
		s3.student_id, s3.name, s3.gender, s3.chinese, s3.math, s3.english);
	// s3.student_name与s3.student.gender均为0即空字符'\0'，无法打印出来
}

// typedef 起别名
typedef struct triangle { // struct triangle 等价于 Triangle
	int edge1;
	int edge2;
	int edge3;
	double area;
}Triangle; // 大驼峰

// 结构体对齐
//typedef struct triangle {
//	char flag1;
//	int edge1;
//	int edge2;
//	int edge3;
//	char test2[20];
//}Triangle;
void test2(){
	// 这个结构体，占据多大的空间：1 + 12 + 20 = 33 ×   实际占：1(+3) + 12 + 20 = 36B
	// 实际内存中会有对齐操作，具体见笔记

	// 结构体的成员访问：使用 .进行访问

	// 结构体指针的成员访问：* 或者 ->
	// ①(*p_s1).student_id; 注意 * 要先与指针名运算，因为要先将结构体指针转为结构体，
	//												后半部分才合法
	// ②p_s1->student_id;
}

// 需要在函数内部，修改外部的结构体值，需要传递结构体指针。
void change_student(Student* pstu) {
	printf("before:id=%d, name=%s\n", pstu->student_id, pstu->name);

	pstu->student_id = 987654;
	//pstu->name = "lisi";
	strcpy(pstu->name, "lisi");

	printf("change:id=%d, name=%s\n", pstu->student_id, pstu->name);
}
void test3() {
	Student s1 = { 10, "zhangsan", 'm', 99, 98, 97 };
	//Student *ps1 = &s1;
	change_student(&s1);
	printf("after:id=%d, name=%s\n", s1.student_id, s1.name);
}

int main(void) {
	// 类似于int num，相当于声明了一个 类型是：struct student，名字是：s1 的变量
	struct student s1;

	//test1();
	//test2();
	test3();

	return 0;
}