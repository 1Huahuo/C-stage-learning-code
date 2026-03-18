#include <stdio.h>
#include <string.h>

#define MAXN 100003

int n, t, H[MAXN], F[MAXN];

int main() {
    //int i;

    //// 读取数据
    //n = 0;
    //printf("输入非整型为终止\n");
    //while (scanf_s("%d", &H[++n]) == 1);
    //n--;

    //// 最长不上升子序列
    //t = 0;
    //memset(F, 0, sizeof(F));
    //F[0] = 2147483647;  // INF

    //for (i = 1; i <= n; i++) {
    //    int l = 0, r = t + 1;
    //    while (r - l > 1) {
    //        int m = l + (r - l) / 2;
    //        if (F[m] >= H[i])
    //            l = m;
    //        else
    //            r = m;
    //    }
    //    int x = l + 1;
    //    if (x > t) t = x;
    //    F[x] = H[i];
    //}
    //printf("%d\n", t);

    //// 最长上升子序列
    //t = 0;
    //memset(F, 0, sizeof(F));
    //F[0] = 0;

    //for (i = 1; i <= n; i++) {
    //    int l = 0, r = t + 1;
    //    while (r - l > 1) {
    //        int m = l + (r - l) / 2;
    //        if (F[m] < H[i])
    //            l = m;
    //        else
    //            r = m;
    //    }
    //    int x = l + 1;
    //    if (x > t) t = x;
    //    F[x] = H[i];
    //}
    //printf("%d\n", t);

    if (0)
        printf("111.\n");
    return 0;
}