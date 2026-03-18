#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	现在我们就来开发一个简单的交互式程序：
	程序将为用户提供选择菜单：
	清空账户余额
	往账户上存钱
	从账户上取钱
	显示当前余额
	退出程序。
*/

int main(void) {
	double account = 0;
	int operation = 5;
	while (operation != 4) {
		printf("\n=======记账程序菜单=======\n0.清空账户余额\n1.往账户上存钱\n2.从账户上取钱\n3.显示当前余额\n4.退出程序\n");
		printf("请选择操作（0-4）：");
		scanf("%d", &operation);
		switch (operation) {
		case 0:
			account = 0;
			printf("账户余额已清空\n");
			break;
		case 1:
			printf("请输入存款金额：");
			double money1;
			scanf("%lf", &money1);
			account += money1;
			printf("成功存款 %.2lf 元\n", money1);
			break;
		case 2:
			printf("请输入取款金额：");
			double money2;
			scanf("%lf", &money2);
			account -= money2;
			printf("成功取款 %.2lf 元\n", money2);
			break;
		case 3:
			printf("当前余额：%.2lf 元\n", account);
			break;
		case 4:
			break;
		}
	}

	return 0;
}