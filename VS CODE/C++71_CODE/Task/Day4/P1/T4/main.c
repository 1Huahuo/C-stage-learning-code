#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
现在有一副扑克牌，去掉大小王。请你写一个随机发牌程序，由用户指定发几张票，然后打印用户得到的手牌。
注：
扑克牌的花色（suit）有四种：梅花（Club）、方块（Diamond）、红心（Heart）、黑桃（Spade）
扑克牌的点数（point）有13种，2~10，J，Q，K，A
*/

int main(void) {
	char suit[4] = { 'C', 'D', 'H', 'S' };
	char opint[13] = { '2', '3', '4', '5' ,'6' , '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	int card_num;

	bool is_send[4][13] = { {false} };

	printf("请输入您需要的手牌数量：");
	scanf("%d", &card_num);
	printf("发牌中....\n发牌中....\n发牌中....\n");
	printf("您的手牌是：\n");
	
	srand(time(NULL));
	while(card_num--) {
	//for (int i = 0; i < card_num; i++) {
		int j = rand() % 4;
		int k = rand() % 13;
		if (is_send[j][k]) {
			card_num++;
			//printf("The card has been sent out!\n");	//防止重复发送
			continue;
		}
		printf("%c%-7c", suit[j], opint[k]);
		is_send[j][k] = true;
	}
	
	printf("\n");

	return 0;
}