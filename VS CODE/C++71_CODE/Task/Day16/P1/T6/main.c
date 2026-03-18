#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
模拟网盘服务器记录配置信息。编写一个程序，将服务器的 IP 地址（字符串）
和端口号（整数）格式化写入 `config.txt` 文件，然后再从该文件中读取并打印出来。
要求：
1. 使用 `fprintf()` 将数据格式化写入文件。
2. 使用 `fscanf()` 从文件中还原数据。
3. 输出读取到的配置信息，格式为："加载配置: IP=X, Port=Y"。
*/

int main(void) {
	char ip[] = "192.168.1.1";
	int port = 1234;
	FILE* fp = fopen("config.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return -1;
	}
	fprintf(fp, "%s %d", ip, port);
	fclose(fp);

	for (int i = 0; i < 12; i++) {
		ip[i] = 0;
	}
	port = 0;
	fp = fopen("config.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "打开文件失败\n");
		return -1;
	}
	fscanf(fp, "%s %d", ip, &port);

	printf("加载配置：IP=%s，Port=%d\n", ip, port);
	return 0;
}