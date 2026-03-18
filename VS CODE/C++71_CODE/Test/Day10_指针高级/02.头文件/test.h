// 头文件保护性语法：
// 如果引入了一次，就不要再引入第二次了。 
#ifndef TEST_H // 上下两个名字相同即可
#define TEST_H
#include <stdio.h>
// 系统的头文件，也有这种头文件保护性语法

// #ifndef 是一个预处理指令。 
// #ifndef if not define 
// 如果没有这个宏定义，就将 if-end之间的内容复制过去； 
// 如果有这个宏定义，不复制过去，而是直接跳到endif
struct student {
	int id;
	char name[20];
};

#endif // !TEST_H