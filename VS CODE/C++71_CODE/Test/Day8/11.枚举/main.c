#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
枚举
*/

typedef enum {
    NEW,        // 新订单
    PAID,       // 已支付
    SHIPPED,    // 已发货
    DELIVERED,  // 已送达
    COMPLETED,   // 已完成
    CANCELLED   // 已取消  
} OrderStatus;

typedef enum {
    RED, // 默认为0
    BLACK
} Color;
// 也可能跳着赋值，没有赋值即为前面的+1
//typedef enum {
//    RED = 1,
//    BLACK = 3
//} Color;

int main(void) {
    // 枚举类型变量可以用任何整数赋值
    //OrderStatus status = 100;

    //Color c = RED;
    int c = RED; // c:0 枚举本质就是int类型数据,所以可以直接赋值给int类型变量
    printf("%d\n", c);


    // 枚举类型之间可以互相赋值
    OrderStatus status2 = c; // status2:0
    printf("%d\n", status2);

    return 0;
}