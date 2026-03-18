#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
(1) 汉诺塔
有三根杆子A，B，C。A杆上有 N 个 (N>1) 穿孔圆盘，盘的尺寸由下到上依次变小。
要求按下列规则将所有圆盘移至 C 杆：
每次只能移动一个圆盘;
大盘不能叠在小盘上面。
利用递归的方式，打印出移动轨迹。运行结果如下图所示:
*/

long long hanoi_count(int n) { // 由于T(n)=2^n，所以int不行，应用最大的ll
	if (n == 1)	// 边界
		return 1;
	return 2 * hanoi_count(n - 1) + 1; // 递归
}

//后三个参数分别代表 起点 中间点 终点
void hanoi_track(int n, char first, char second, char third) {
	if (n == 1) {// 边界
		printf("%c --> %c\n", first, third);
		return;
	}
	// 递归 将n-1个盘子从第一个塔移动到第二个塔
	hanoi_track(n - 1, first, third, second);
	// 操作内容 将最大的盘子从第一个塔移动到第三个塔
	printf("%c --> %c\n", first, third);
	// 递归 将n-1个盘子从第二个塔移动到第三个塔（判断是否正确，看从逻辑上到这里是否完成了操作）
	hanoi_track(n - 1, second, first, third);
}//递归核心：无论细节如何，总的第一次调用类似于要将一个完整的事件(操作)拆分成一个完备事件组(操作)

int main(void) {
	int N;
	scanf("%d", &N);
	printf("完成%d个盘子的汉诺塔问题，最少需要%lld步，全部移动轨迹如下：\n", N, hanoi_count(N));

	hanoi_track(N, 'A', 'B', 'C');

	return 0;
}