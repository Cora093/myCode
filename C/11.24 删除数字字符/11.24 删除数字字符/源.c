#define _CRT_SECURE_NO_WARNINGS 1
//输入一字符串
//输出删掉数字字符后，剩下的字符组成的新串

#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, p = 0;
	char s[20], s1[20];
	//gets(s);
	scanf("%s", s);
	for (j = 0;; j++)
	{
		if (s[j] < 48 || s[j]>57)	//如果不是数字
		{
			s1[p] = s[j];
			p++;
		}
		if (s[j] == '\0') break;
	}
	puts(s1);
	return 0;
}