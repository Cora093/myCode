#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char input[20];
	system("shutdown -s -t 60");
again:
	printf("���Խ���1�����ڹػ������롰������ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "������") == 0) {
		system("shutdown -a");
	}
	else goto again;
	return 0;
}

