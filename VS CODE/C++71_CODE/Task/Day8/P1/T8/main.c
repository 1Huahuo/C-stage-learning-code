#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
第一题：
下面结构体类型的变量的内存布局是怎样的？请使用VS的Debug模式查看它的内存布局
// 结构体对象的声明和初始化
Student s1 = { 1, "Jack", 'm', 100, 100, 100 };
要求：截图展示内存窗口中的对齐填充，然后提交截图。
第二题：
基于上述的结构体类型的定义，实现以下功能：
1.从键盘输入5个学生的信息，将这些同学的信息采用结构体数组的方式存储起来。（代码直接写在main函数里）
2.编写一个函数，用于打印单个结构体信息。然后在main函数里调用该函数，打印这个结构体数组。
3.编写一个函数，用于求三个学科的平均分。然后在main函数里调用该函数，打印这三个学科的平均分。
*/
typedef struct stundent_s {
	int number;
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
} Student;

void printf_info(Student s, int i) {
	printf("\n第%d个学生的信息：\n", i + 1);
	printf("学号: %d", s.number);
	printf("   姓名: %s", s.name);
	printf("   性别: %c", s.gender);
	printf("   语文 数学 英语成绩: %d %d %d", s.chinese, s.math, s.english);
}

void print_average_score(Student s[], int n) {
	double average[3] = { 0 };
	for (int i = 0; i < n; i++) {
		average[0] += s[i].chinese;
		average[1] += s[i].math;
		average[2] += s[i].english;
	}
	for (int i = 0; i < 3; i++)
		average[i] /= n;
	printf("语文，数学，英语的平均成绩分别为：%.2lf,%.2lf,%.2lf\n", average[0], average[1], average[2]);
}

int main(void) {
	Student s1 = { 1, "Jack", 'm', 100, 100, 100 };

	Student students[5];
	printf("请输入5个学生的信息：\n");
	for (int i = 0; i < 5; i++) {
		printf("第%d个学生的信息：\n", i + 1);
		printf("学号: ");
		scanf("%d", &students[i].number);
		printf("姓名: ");
		scanf("%s", students[i].name);
		printf("性别(m/f): ");
		scanf(" %c", &students[i].gender);  // 加空格用来匹配空格与回车
		printf("语文 数学 英语成绩: ");
		scanf("%d %d %d", &students[i].chinese, &students[i].math, &students[i].english);
	}

	// 打印信息
	for (int i = 0; i < 5; i++) {
		printf_info(students[i], i);
		if (i == 5 - 1)
			printf("\n");
	}
	
	//计算并打印平均分
	printf("\n");
	print_average_score(students, 5);

	return 0;
}