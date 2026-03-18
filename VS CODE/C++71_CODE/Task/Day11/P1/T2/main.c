#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
你的任务是使用qsort函数对这个结构体数组进行排序：
	规则1：将全体结构体对象，按照学生成绩从高到低进行排序。
	规则2：先将全体结构体对象，按照学生成绩从低到高进行排序，
	如果成绩一致，则那么按照名字的字典顺序进行排序。
	最后，你还需要实现一个函数用于打印整个学生数组：
 void print_students(Student stus[], int size);
*/

typedef struct {
	char name[25];
	int score;
} Student;

void print_students(Student stus[], int size) {
	for (int i = 0; i < size; i++)
		printf("姓名：%s，成绩：%d\n", stus[i].name, stus[i].score);
}

int sort_from_high_to_low(const void* a, const void* b) {
	if ((*(Student*)a).score != (*(Student*)b).score)
		return  (*(Student*)b).score - (*(Student*)a).score;
	return strcmp((*(Student*)a).name, (*(Student*)b).name);
}

int sort_from_low_to_high(const void* a, const void* b) {
	if ((*(Student*)a).score != (*(Student*)b).score)
		return  (*(Student*)a).score - (*(Student*)b).score;
	return strcmp((*(Student*)a).name, (*(Student*)b).name);
}

int main(void) {
	Student stus[] = { {"Alice", 85},{"Bob", 92},{"Charlie", 85},{"David", 85},{"Eve", 92},{"Frank", 75},{"Grace", 85},{"Hannah", 95},{"Ivy", 78},{"Jack", 85} };

	qsort(stus, 10, sizeof(Student), sort_from_high_to_low);
	print_students(stus, 10);

	printf("\n");

	qsort(stus, 10, sizeof(Student), sort_from_low_to_high);
	print_students(stus, 10);

	return 0;
}