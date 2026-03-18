#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
依照C语言的字符串标准库函数，手动实现以下函数：
函数的实现要模拟标准库函数中对应函数的行为，不要依据自己的理解来实现这些函数。
*/

// 计算字符串长度
size_t my_strlen(const char* str) {
	unsigned long long  count = 0;
	while (str[count])
		count++;
	return count;
}

// 复制字符串，不检查越界
char* my_strcpy(char* dest, const char* src) {
	char* temp = dest;
	// 使用指针操作的话可以省去辅助变量int i = 0;
	while (*src) // 若是使用for循环，则不方便将'\0'也复制到dest中
		*dest++ = *src++;
	*dest = '\0';
	return temp;
}

// 复制n个字符到字符串，更安全，但仍可能产生越界
char* my_strncpy(char* dest, const char* src, size_t n) {
	int min = my_strlen(src) < n ? my_strlen(src) : n; // 先把有效字符复制进去，个数取二者最小值
	char* temp = dest;
	while (min--) // 使用指针操作的话可以省去辅助变量i
		*dest++ = *src++;
	if (my_strlen(src) < n) { // 只有还未复制够n个字符时才填充
		int count = n - my_strlen(src);
		while (count--)
			*dest++ = '\0';
	}
	// else // my_strlen(src) >= n，不用操作
	return temp;
}

// 拼接字符串，拼接的是常量
char* my_strcat(char* dest, const char* src) {
	char* temp = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return temp;
}

// 拼接n个字符到字符串
// 已经复制了 n 个字符。
// 或者复制到达了src字符串的结尾，即遇到了src的空字符串。所以该函数不会把src中的空字符复制到dest中。
char* my_strncat(char* dest, const char* src, size_t n) {
	char* temp = dest;
	int min = my_strlen(src) < n ? my_strlen(src) : n; // 有n则判断要拼接的字符串长度与其的关系
	while (*dest)
		dest++;
	while (min-- && *src)
		*dest++ = *src++;
	*dest = '\0'; // 无填充操作，直接结尾置空字符结束(存在越界风险)

	return dest;
}

// 字符串比大小，返回相同位置两字符ASCII码表之差值
int my_strcmp(const char* str1, const char* str2) {
	while (*str1 && *str2) { // (*str1++ && *str2++)错误，因为出口下面，比大小在可能退出前不应该移动指针
		if (*str1 != *str2) {
			break;
		}
		str1++; // 不能放在while循环内，因为退出循环时需要的是"当前字符"而不是"下一字符"
		str2++;
	}
	// 上面两层判断可以合并为一层
	//while (*str1 && *str1 == *str2) { // 前半判断只需任意判断一个字符串就行(仅需要防止二者同时越界)
	//	str1++;
	//	str2++;
	//}
	// 注意：两个自增仍然不能合并进去，因为这个函数是为了比大小返回当前两字符差值

	return *str1 - *str2; // ！二元加减小于解引用，代表正负的一元加减才大于解引用,所以不用加括号
}

int main(void) {
	/*char str1[] = "hello";
	char str2[] = "hellr";
	printf("%d\n", my_strcmp(str1, str2));*/

	//printf("%d\n", my_strlen(str));
}