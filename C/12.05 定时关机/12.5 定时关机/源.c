#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char input[20];
	system("shutdown -s -t 60");
again:
	printf("电脑将在1分钟内关机，输入“我是猪”取消关机\n");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0) {
		system("shutdown -a");
	}
	else goto again;
	return 0;
}

