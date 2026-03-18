#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char fruits1[][10] = { "apple", "banana", "cherry" };
    char* fruits2[] = { "apple", "banana", "cherry" };

    // 重新手动输入这些行
    int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
    int size2 = sizeof(fruits2) / sizeof(fruits2[0]);

    printf("Fruits1:\n");
    for (int i = 0; i < size1; ++i) {
        printf("第%d个字符串是:%s, 字符串长度是:%zu\n", (i + 1), fruits1[i], strlen(fruits1[i]));
    }

    printf("\nFruits2:\n");
    for (int i = 0; i < size2; ++i) {
        printf("第%d个字符串是:%s, 字符串长度是:%zu\n", (i + 1), fruits2[i], strlen(fruits2[i]));
    }

    return 0;
}