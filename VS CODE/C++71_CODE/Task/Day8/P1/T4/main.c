#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
给定一个字符串，要求它可能包含数字和字母。
请编写函数，统计该字符串中每个字符出现的次数，
统计过程中忽略大小写的差异，并打印最终每个字符出现的次数。
提示：
用一个int数组存储字符出现的次数，可以用一个128长度的数组，
这样数组下标位置的元素就是该编码值字符出现的次数，缺点是浪费空间，但你可以先写一个这样的实现。
（扩展）做完后，你可以思考一下：
实际上只会有36个字符(10个数字和26个不区分大小写的字母)，所以int数组的长度实际上只需要36就可以了。
那么怎么把数组的长度缩短到36呢？
*/

void str_count(char* str) {
	int i = 0, digit_num = 0, letter_num = 0;
	int cnt[128] = { 0 };
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			cnt[str[i] - 'A' + 'a']++;
		else
			cnt[str[i]]++;
		i++;
	}
	for (i = 0; i < 128; i++)
		if (cnt[i] > 0)
			printf("字符%c的数量是：%d\n", i, cnt[i]);
}

void str_count_optimize(char* str) {
	int i = 0, digit_num = 0, letter_num = 0;
	int cnt[36] = { 0 };
	while (str[i]) { // ！！！除非while只要一条语句，否则不要将i++放到while中
		if (str[i] >= '0' && str[i] <= '9')
			cnt[str[i] - '0']++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			cnt[str[i] - 'A' + 10]++;
		if (str[i] >= 'a' && str[i] <= 'z')
			cnt[str[i] - 'a' + 10]++;
		i++;
	}
	for (i = 0; i <= 9; i++)
		if (cnt[i] > 0)
			printf("字符%c的数量是：%d\n", i + '0', cnt[i]);
	for (i = 9; i < 36; i++)
		if (cnt[i] > 0)
			printf("字符%c的数量是：%d\n", i - 10 + 'a', cnt[i]);
}
int main(void) {
	char str[] = "hello 1234";

	//str_count(str);
	str_count_optimize(str);

	//printf("1\n");
}