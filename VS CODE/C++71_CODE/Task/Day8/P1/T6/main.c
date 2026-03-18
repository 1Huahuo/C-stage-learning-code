#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
题目一：
先输出一下当前命令行参数的个数，再循环打印一下命令行参数字符串数组，
输出的格式你可以自己来决定。

题目二：
使用sscanf函数将两个额外的命令行参数，转换成它们对应的基本数据类型（int和double）。

题目三：
在完成前两个命令行参数的类型转换后，请计算它们之和。
然后利用sprintf函数，加上最后一个命令行参数字符串，
按照下面的格式来构建字符串并输出到字符数组中：
"10 + 8.8 = 18.80hello"
最后打印这个字符数组表示的字符串。
*/

void command_operation() {

}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("命令行参数数量不正确,请重新输入!\n");
		return;
	}
	// 命令行参数的个数
	int num = argc;
	printf("命令行参数的个数:%d\n", argc);
	// 效果
	//D:\VS CODE\C++71_CODE\Task\Day8\P1\x64\Debug > T6.exe 10 8.8 hello
	//命令行参数的个数 : 4

	// 打印所有命令行参数
	// 命令行参数也是实际存在的，所以不用废大力气才将它sprintf输出到二维数组里，如：
	//char str[4][100]; // 字符二维数组
	//for (int i = 0; i < num; i++)
	//	sprintf(str[i], "argv[%d]:%s", i, argv[i]);
	//for (int i = 0; i < num; i++)
	//	printf("%s\n", str[i]);
	// 而是可以直接打印：
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	// 使用sscanf函数将两个额外的命令行参数，转换成它们对应的基本数据类型（int和double）
	// 第一个参数与第二个参数需要转换，所以需要sscanf函数
	int a = 0;
	double b = 0.0;
	sscanf(argv[1], "%d", &a);
	sscanf(argv[2], "%lf", &b);
	printf("a=%d,b=%lf\n", a, b);
	// 效果：
	//D:\VS CODE\C++71_CODE\Task\Day8\P1\x64\Debug > T6.exe 10 8.8
	//命令行参数的个数:3
	//a = 10, b = 8.800000
	
	// 第三个参数（命令行参数的本质也是字符串，所以说明符是%s）
	//char str[100] = { 0 };
	//sscanf(argv[3], "%s", str); // 这是没有必要的，因为argv[3]="hello",与str同类型都是字符串，
								  // 所以不用通过sscanf函数来输入
	char* str = argv[3]; // 即等于字符串变量的初始化：char *str = "hello";
	//printf("--------------%s\n", str);

	char res_str[99+1]; // 字符串变量的声明
	sprintf(res_str, "%d + %.1lf = %.2lf%s", a, b, a + b, argv[3]);
	printf("结果字符串：%s\n", res_str);
	// 效果：
	//命令行参数的个数:4
	//a = 10, b = 8.800000
	//argv[0] : T6.exe
	//argv[1] : 10
	//argv[2] : 8.8
	//argv[3] : hello
	//结果字符串：10 + 8.8 = 18.80hello

	//command_operation(); // 最好直接在主函数操作，子函数能否传命令行参数？
	return 0;
}

// 参考答案
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("命令行参数数量不正确,请重新输入!\n");
		return;
	}

	printf("argc = %d\n", argc);

	// 打印所有命令行参数
	for (int i = 0; i < argc; ++i) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	// 第1个参数：转换为int
	int int_num = 0;
	sscanf(argv[1], "%d", &int_num);

	// 第2个参数：转换为double
	double double_num = 0.0;
	sscanf(argv[2], "%lf", &double_num);

	// 第3个参数：字符串无需转换
	char *string = argv[3];

	// 计算和，并构建输出字符串
	char result[100];
	sprintf(result, "%d + %.1f = %.2f%s", int_num, double_num, int_num + double_num, string);

	// 打印最终结果
	printf("结果字符串：%s\n", result);

	return 0;
}
*/