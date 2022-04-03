#define _CRT_SECURE_NO_WARNINGS 1
//首先输入一个正整数k，然后是一个字符串s（可能包含空格，长度不超过20），
// k和s之间用一个空格分开。（k大于0且小于等于s的长度）
//在一行中输出字符串s从头开始且长度为k的子串。
//eg:10 welcome to acm world--welcome to

#include<stdio.h>
#include<string.h>
int main()
{
	int k, i;
	char s[21];
	scanf("%d", &k);
	for (i = 0; i <= k; i++)						//逐个字符输出
	{
		scanf("%c", &s[i]);
		if (s[i] == '\n') break;
	}
	for (i = 1; i <= k ; i++)
	{
		printf("%c", s[i]);
	}
	return 0;
}
