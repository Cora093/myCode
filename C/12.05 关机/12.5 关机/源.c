#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
	char input[20];
	system("shutdown -s -t 20");
again:
	printf("电脑将在20秒内关机，输入“cancel”取消关机\n");
	scanf("%s", input);
	if (strcmp(input, "cancel") == 0) {
		system("shutdown -a");
	}
	else goto again;
	return 0;
}

