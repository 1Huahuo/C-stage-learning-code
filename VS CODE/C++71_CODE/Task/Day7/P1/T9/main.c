#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个函数，计算一个字符串中单词的数量。这里，单词被定义为由空格分隔的字符序列。
例如，对于字符串"hello world! word Excel space blank"
就应该输出有6个单词
注意：空格可能连续出现。
*/

int word_num(char* str) {
	int i = 0;
	int count = 0;
	while (str[i] == ' ') // 若是以空格开头或者全是空格
		i++;
	// 把判空放在这里可以省去在开头的判空
	if (!str[i]) // ①若为空②若全是空格（注意：此为判断空字符，而非跳过空字符）
		return 0;

	while (str[i]) {
		if (str[i] == ' ' && str[i - 1] != ' ')
			count++;
		i++;
	}
	return count + 1;
}

int main(void) {
	char str[] = "hello world! word Excel space blank";

	printf("%d\n", word_num(str));

	return 0;
}