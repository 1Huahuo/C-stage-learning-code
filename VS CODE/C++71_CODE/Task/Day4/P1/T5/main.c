#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//题目较长，已折叠
/*
编写程序模拟掷骰子的游戏（每一次投掷，都投掷两个骰子）。每局游戏的规则如下：
第一次掷的时候：
如果点数之和为 7 或 11 则获胜；
如果点数之和为2、3或12则落败；
其他情况下的点数之和称为“目标”，继续投掷两个骰子。

在后续的投掷中：
如果玩家再次掷出“目标”点数则获胜；
如果掷出7则落败；
其他情况都忽略，继续投掷两个骰子。
在每一局游戏结束时，程序都要询问用户是否再玩一次，如果用户输入的回答不是 y 或 Y ，那么就结束游戏，程序此时要打印显示胜败的次数。
玩家游玩过程程序的输出，大体如下所示：

You rolled: 5
Your point is 5
You rolled: 7
You lose!

Play again?(y/Y means continue) y
You rolled: 5
Your point is 5
You rolled: 4
You rolled: 4
You rolled: 9
You rolled: 2
You rolled: 7
You lose!

Play again?(y/Y means continue) y
You rolled: 4
Your point is 4
You rolled: 7
You lose!

Play again?(y/Y means continue) n

Wins: 0 Losses: 3
*/

int main(void) {
	int dice1, dice2, sum, point, wins = 0, losses = 0;
	bool game_continue = true;
	int game_stage = 0;
	srand(time(NULL));	//C中位置较优，若设置在while里则游戏再无随机性，只要第一轮非赢非输则第二轮必赢

	while (game_continue) {
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		sum = dice1 + dice2;
		printf("You rolled:%d\n", sum);

		switch (game_stage) {
		case 0:
//		if(!game_stage){ 
			if (sum == 7 || sum == 11) {
				printf("You win!\n");
				wins++;
				break;
			}
			else if (sum == 2 || sum == 3 || sum == 12) {
				printf("You lose!\n");
				losses++;
				break;
			}
			else {
				point = sum;
				game_stage = 1;
				printf("Your point is %d\n", point);
				continue;
			}
//		}
		case 1:
//		else{
			if (sum == point) {
				printf("You win!\n");
				wins++;
				game_stage = 0;
				break;
			}
			else if (sum == 7) {
				printf("You lose!\n");
				losses++;
				game_stage = 0;
				break;
			}
			else {
				continue;
			}
		
//		}
		}
		
		printf("\nPlay again?(y/Y means continue)");
		char c;
		scanf("%c", &c);
		//不要忘记清空输入缓冲区！
		while (getchar() != '\n');
		if (c == 'y' || c == 'Y')
			game_continue = true;
		else
			game_continue = false;
	}
	
	printf("Wins: %d Losses: %d\n", wins, losses);
	
	return 0;
}