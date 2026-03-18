#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
汉诺塔移动轨迹的扩展题，感兴趣且学有余力可以研究一下，不做统一要求。
现在你已经知道如何打印n个盘子汉诺塔问题的移动轨迹了，那么在这个的基础上，我们进行以下扩展：
对于n个盘子的汉诺塔问题，给定一个整数m，要求在控制台打印出m + 1步的移动轨迹。
提示：
既然要打印m + 1步的移动轨迹，那么肯定需要计数器记录移动的步骤，需要用什么变量呢？
核心思路就还是move函数的递归，但要加上一个计数器，实际编码时注意边界值就可以了。
*/

static int step_count = 0;

//后三个参数分别代表 起点 中间点 终点
void hanoi_m_track(int n, char first, char second, char third, int m) {
	if (n == 1) {// 边界
		step_count++;
		if (step_count == m)
			printf("%c --> %c\n", first, third, m);
		return;
	}
	hanoi_m_track(n - 1, first, third, second, m);

	step_count++;
	if(step_count == m)
		printf("%c --> %c\n", first, third);
	hanoi_m_track(n - 1, second, first, third, m);
}

int main(void){
	int N, m;
	scanf("%d %d", &N, &m); // N个盘子的汉诺塔问题，第m + 1步的移动轨迹
	printf("%d个盘子的汉诺塔问题，第%d步的移动轨迹如下：", N, m + 1);

	hanoi_m_track(N, 'A', 'B', 'C', m + 1);

	return 0;
}