#define _CRT_SECURE_NO_WARNINGS 1
//����DNA���Ա�ʾ����һЩ��ĸ��ɵ��ַ������У��Ҳ�����DNA�����ǻ�״�ġ�(������ֲ����ظ�)
//���磬���財����DNA����Ϊbaa����ò�����DNA���������ֱ��֣�baa, aab, aba��
//�����һ���и���1������i(1��i��11)����ʾ�����Ĳ���DNA�� 
//����i�д����У�ÿ��һ���ַ�������������DNA���У�������DNA���г��Ȳ�����500��
//�����������ÿ������DNA���б��֣�������֮���ÿո�ָ���
#include <stdio.h>
#include <string.h>

int main() {
	void strfwd(char* str);
	int n, i, j;
	char str[500], str1[500];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", str);
		printf("%s ",str);
		for (j = 1; j <= strlen(str) - 1; j++) {
			strfwd(str);
			printf("%s ", str);
		}
		if (i != n) {
			printf("\n");
		}
	}
	return 0;
}

void strfwd(char* str)
{
	int j, tem, length;
	length = strlen(str);
	tem = str[0];
	for (j = 0; j < length - 1; j++) {
		str[j] = str[j + 1];
	}
	str[length - 1] = tem;
}