#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
	char input[20];
	system("shutdown -s -t 20");
again:
	printf("���Խ���20���ڹػ������롰cancel��ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "cancel") == 0) {
		system("shutdown -a");
	}
	else goto again;
	return 0;
}

