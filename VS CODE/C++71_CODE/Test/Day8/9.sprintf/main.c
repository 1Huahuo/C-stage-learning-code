#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// sprintf：向字符串中输出，括号内第一个参数表达要输出的地方(一定是字符串)
// 后面参数与printf一样，代表要输出什么内容的变量
// sprintf也会输出'\0'
void test2() {
	int a = 111;
	double b = 1.11;
	printf("a=%d,b=%lf\n", a, b);

	char str[] = { 0 };
	//char* p = NULL;
	//char* p = str;

	// 效果为：将"a=%d,b=%lf"即将"a=111,b=1.11"输出到str所代表的字符串中
	sprintf(str, "a=%d,b=%lf", a, b);
	
	printf("%s\n", str);

	//sprintf(p, "a=%d,b=%lf", a, b);
}

// sscanf：将字符串中的数据输入并转换成其他类型
// 第一个参数表达输入的字符串，后面的参数是是被输入的变量
void test3() {
	int a = 111;
	double b = 1.11;
	scanf("%d %lf", &a, &b);
	char str[9] = "222 2.22";
	// 效果为将str中的字符串数据输入到变量a与b中，并转换为a与b的数据类型
	// 即将"222 2.22"中的222输入给a，2.22输入给b
	sscanf(str, "%d %lf", &a, &b); // 注意""内的格式，两个说明符之间若是有其它符号可能会导致b的读入失败
	printf("a=%d,b=%lf\n", a, b);
}

// ！！！s输入与s输出的第一个参数均可用argv[]即命令行参数来代替

// argc：命令行参数个数；argv[]命令行参数的字符串指针数组
int main(int argc, char* argv[]) {
	// sprintf：往字符串输出。
	// sscanf ：从字符串输入。 

	// 效果为：将(输入的)字符串(即命令行参数)转成其他类型
	//int num = 0;
	//sscanf(argv[1], "%d", &num);
	//printf("num = %d\n", num);
	//for (int i = 0; i < num; i++) {
	//	printf("========\n");
	//}

	//test2();
	test3();



	return 0;
}