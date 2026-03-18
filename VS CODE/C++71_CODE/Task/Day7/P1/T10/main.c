#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
编写一个函数，检查给定的字符串中的圆括号()是否正确匹配。注意只考虑小括号，字符串中没有其它括号。
如字符串：((Hello) (World))
函数会返回一个布尔值，表示匹配成功或失败
注意：只考虑英文小括号()，不需要考虑其它括号，更不需要考虑中文符号。
*/

bool brack_match(char* str) {
	int judge = 0;
	int i = 0;
	while (str[i]) {
		if (str[i] == '(')
			judge++;
		if (str[i] == ')')
			judge--;
		if (judge < 0)
			return false;
		i++;
	}
	if (!judge)
		return true;
	else
		return false;
	// 上面if-else可合并为 return judge == 0;
}

int main(void) {
	char str[] = "((Hello) (World))";
	//char str[] = ")(Hello) (World))";
	//char str[] = "((Hello) )World))";

	if (brack_match(str))
		printf("success\n");
	else
		printf("failure\n");

	return 0;
}