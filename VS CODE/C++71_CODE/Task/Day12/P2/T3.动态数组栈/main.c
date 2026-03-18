#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_stack.h"

/*
在上述已实现的一个链式栈（数组栈也行）的基础上，编写代码完成字符串括号的匹配校验。
括号都是英文字符括号，而且有三类：{}、[]、()
注：
	1.若字符串中没有括号，也算做括号匹配成功。
	2.思路可以参考文档《栈》
*/
/*
bool parenthese_match(char* s) {
	DynamicStack* stack = stack_create();
	while (*s != '\0') {
		if (*s == '{' || *s == '[' || *s == '(') {
			stack_push(stack, *s);
			s++;
		}
		else if (*s == '}') {
			if (stack_is_empty(stack) || stack_pop(stack) != '{')
				return false;
			s++;
		}
		else if (*s == ']') {
			if (stack_is_empty(stack) || stack_pop(stack) != '[')
				return false;
			s++;
		}
		else if (*s == ')') {
			if (stack_is_empty(stack) || stack_pop(stack) != '(')
				return false;
			s++;
		}
		else {
			s++;
		}
	}
	if (stack->size == 0)
		return true;
	else
		return false;
}
*/

bool parenthese_match(char* s) {
	char mp[128] = { 0 };
	mp[')'] = '(';
	mp[']'] = '[';
	mp['}'] = '{';
	mp['{'] = mp['['] = mp['('] = 1;
	// 此时，哈希表中左括号对应的值为1，右括号对应的值不为0，其余字符对应的均为0

	int top = 0; // 直接把 s 当作栈
	for (int i = 0; s[i]; i++) {
		char c = s[i];
		if (mp[c] == 1) { // c 是左括号
			s[top++] = c; // 入栈
		}
		else if(mp[c] != 0 && (top == 0 || s[--top] != mp[c])) { // c 是右括号
			return false; // 没有左括号，或者左括号类型不对
		}
	}
	return top == 0; // 所有左括号必须匹配完毕
}

int main(void) {
	//char s[] = "{[(0)]}";
	char s[] = "{[((0)]}";

	if (parenthese_match(s))
		printf("match successful.\n");
	else
		printf("match fail.\n");

	return 0;
}