#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	编写一个程序，要求用户键盘录入十名学生的语文成绩(百分制)，然后存储在一个一维数组中。
	最后计算全班的平均成绩、最高分和最低分，并打印出来。
注意：
1.要求使用一个int数组来存放成绩，平均成绩保留2位小数。
2.如果你还不理解将数组作为参数传递的话，请不要提取函数，直接将所有代码写到main函数里。	
*/

int main(void) {
	int score[10];
	for(int i = 0; i < 10; i++)
		scanf("%d", &score[i]);
	
	double average = 0;
	int max = score[0], min = score[0];
	for (int i = 0; i < 10; i++) {
		if (score[i] > max)
			max = score[i];
		if(score[i] < min)
			min = score[i];
		average += score[i];
	}
	
	printf("平均成绩为：%.2lf\n最高分为：%d\n最低分为：%d\n", average / 10, max, min);

	return 0;
}