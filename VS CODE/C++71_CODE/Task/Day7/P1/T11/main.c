#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
请编写函数，将字符串中的字母和数字分开，使得字符串中前一部分是数字，后一部分是字母。
void seperate(char* str);
输入: "h1ell2o3"
结果: "123hello"或者任意数字在前，字母在后的字符串
注意：要求字符串只包含字母和数字，字符串的长度不超过100，且分组要最终在原数组上完成。
提供几个参考的实现思路：
1.临时数组法。
用两个临时数组一个装数字，一个装字母，然后再将数据合并回原数组。
2.双指针夹逼交换法。
两个指针向中间逼近，一个找字母一个找数字，找到后交换，直到两个指针相遇。
3.双指针单向分区交换法。
一个指针p用于遍历字符串，另一个指针p_num从头开始向后移动，用于标记下一个数字应该插入的位置。
p指针每发现一个数字，就把它交换到p_num位置，然后p_num指针后移。
直到遍历完字符串，所有的数字都会被交换到前面，所有字母都会被交换到后面。
最后，上面提到的双指针法，既可以用真正意义上的指针，也可以直接用索引。两者没有本质上的区别，更多是代码风格上的区别。
*/

size_t my_strlen(const char* str) {
	unsigned long long  count = 0;
	while (str[count])
		count++;
	return count;
}

void seperate(char* str) {
	int left = 0, right = my_strlen(str) - 1;
	while (left < right) { // !小循环的条件要包含大循环的条件！
		while (left < right && str[left] <= '9' && str[left] >= '0')
			left++;
		// left < right优先级更高，且注意不要与逻辑或在同一层括号中
		while (left < right && (str[right] >= 'a' && str[right] <= 'z' || str[right] >= 'A' && str[right] <= 'Z'))
			right--;
		if (left < right) { // 判断条件也要在最外层判断条件之中
			char t = str[left];
			str[left] = str[right];
			str[right] = t;
			left++;
			right--;
		}
	}
}

int main(void) {
	char str[] = "h1ell2o3";

	seperate(str);
	printf("%s\n", str);
}