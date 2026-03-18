#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
/*
前置知识一：如何遍历一个整数
如果不把 x 转成字符串，要怎么做？

我们可以不断地取 x 的最低位（模 10），去掉 x 的最低位（除以 10），直到 x=0。

例如 x=123：

通过 xmod10 取到个位数 3，然后把 x 除以 10（下取整），得到 x=12。
再次 xmod10 取到十位数 2，然后把 x 除以 10（下取整），得到 x=1。
最后 xmod10 取到百位数 1，然后把 x 除以 10（下取整），得到 x=0。此时完成遍历，退出循环。
前置知识二：如何反转一个整数
比如我们现在有一个数 56，如何把 7 加到 56 的末尾？

把 56 乘以 10，再加上 7，就得到了 567。

一般地，如果要把数字 b 加到整数 a 的末尾，我们可以计算 a⋅10+b。

如果要把 x=123 反转，我们可以按照前置知识一中的方法，从低到高遍历 x 的每一位，即 3,2,1。

初始化 rev=0，依次把 3,2,1 加到 rev 的末尾，即：

更新 rev 为 rev⋅10+3=3。
更新 rev 为 rev⋅10+2=32。
更新 rev 为 rev⋅10+1=321。
最终得到了 x 反转后的结果 rev=321。
本题思路
暴力想法是，根据前置知识二，把 x 整体反转，得到 rev，然后判断 rev 和 x 是否相等。

但实际上，对于回文数来说，只需判断 x 的左半部分是否等于右半部分就行。

*/

//反转一半整数
bool isPalindrome(int x) {
    if (x < 0 || x > 0 && x % 10 == 0) {
        return false;
    }
    int rev = 0;
    while (rev < x / 10) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == x || rev == x / 10;
}

int main(void) {
    int x;
    printf("Please enter a number:");
    scanf("%d", &x);
    printf("%d", isPalindrome(x));
    


    //作者：灵茶山艾府
    //    链接：https ://leetcode.cn/problems/palindrome-number/solutions/3682487/bi-guan-fang-ti-jie-shao-xun-huan-yi-ci-02nkc/
    //来源：力扣（LeetCode）
    //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

	return 0;
}