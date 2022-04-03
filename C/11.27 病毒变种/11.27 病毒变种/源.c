#define _CRT_SECURE_NO_WARNINGS 1
//病毒DNA可以表示成由一些字母组成的字符串序列，且病毒的DNA序列是环状的。(假设变种不会重复)
//例如，假设病毒的DNA序列为baa，则该病毒的DNA序列有三种变种：baa, aab, aba。
//输入第一行中给出1个整数i(1≤i≤11)，表示待检测的病毒DNA。 
//输入i行串序列，每行一个字符串，代表病毒的DNA序列，病毒的DNA序列长度不超过500。
//依次逐行输出每个病毒DNA所有变种，各变种之间用空格分隔。
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