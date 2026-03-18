#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
 因为哈希表中，采取的是数组+链表的存储方式
	 链表，理论上可以存储下任意长度的数据。 但是和哈希表的
	 设计初衷出现了矛盾。 需要平衡考虑 时间和空间的关系。
	 加载因子，就是用于判断哈希表的稀疏程度的
	 键值对数目 / 数组长度。
	 2 / 10  0.2
	 10 / 10  1
	 200 / 10  20
	 加载因子变大，存的数据多了。但是性能差了。
	 所以，科学家提出，可以在加载因子超过某个值，就扩容。
	 经过工业的验证。 大概在 3/4 扩容。会得以平衡时间和空间。
*/

int main(void) {
	

	printf("1\n");

	return 0;
}