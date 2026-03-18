#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度。
*/

int lengthOfLongestSubstring(char* s) {
    int ans = 0, left = 0;
    int cnt[128] = { 0 }; // 也可以用哈希表，这里为了效率用的数组
    for (int right = 0; s[right]; right++) {
        // char c = s[right];
        // cnt[c]++;
        cnt[s[right]] ++;
        // 窗口内有重复字母—cnt[c]<=1退出，即某字符在一个数量基础上每多一个就在最左边去掉一个
        //！！并且若是移去的不是窗口右端的字母则会一直移出直到保证当前窗口内的所有种字母都只有1个
        //！！此举有效解决了相同字符紧邻的情况如"xwwbw"：如下折叠注释
        /*right = 2，字符 s[2] = 'w'
            cnt['w']++→ cnt['w'] = 2 ✅ 出现重复

            进入 while 循环（因为 cnt['w'] > 1）

            移除 s[left] = s[0] = 'x'
            cnt['x']--→ cnt['x'] = 0
            left++ → left = 1
            cnt['w'] 还是 2（没变，因为移除的是 'x'）
            继续 while：cnt['w'] = 2 > 1
            移除 s[left] = s[1] = 'w'
            cnt['w']--→ cnt['w'] = 1
            left++ → left = 2
            现在 cnt['w'] = 1，退出 while
            窗口长度 = right - left + 1 = 2 - 2 + 1 = 1

            ans = max(2, 1) = 2 （不变）

            窗口内容：[w]（s[2] 一个）*/
        while (cnt[s[right]] > 1) { 
            cnt[s[left]]--; // 移除窗口左端点字母
            left++; // 缩小窗口
        }
        ans = ans > (right - left + 1) ? ans : (right - left + 1); // 更新窗口长度最大值
    }
    return ans;
}

int main(void) {
	char s[128];	//字符串
	int i = 0;
	while ((s[i] = getchar()) != '\n')
       i++; 
	s[i] = '\0';

	printf("%d\n", lengthOfLongestSubstring(s));

	return 0;
}