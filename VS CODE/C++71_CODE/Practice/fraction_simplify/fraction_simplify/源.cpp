#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
约分最简分式:分子/分母，输入一个分式将其化为最简形式，分子=分母时候为1/1
*/


//此题目需要掌握最大公约数的固定写法
//    int t;
//    while(b>0){
//        t=a % b;
//        a=b;
//        b=t;
//    }
int main(void) {
    int dividend, divisor;  //被除数、除数 即 分子、分母
    scanf("%d %d", &dividend, &divisor);

//检查分母是否为0
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        return 1;
    }

    int a = dividend;
    int b = divisor;
    int t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    printf("%d/%d\n",dividend/a,divisor/a);

    return 0;
}