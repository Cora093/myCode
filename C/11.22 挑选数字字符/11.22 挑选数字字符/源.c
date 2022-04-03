#define _CRT_SECURE_NO_WARNINGS 1
//输入一个字符串，每个字符串由字母和数字组成，将数字选出，求和。
//输入一个有数字和字母组成的字符串，不含空格
//将数字字符选出，转换成整数求和
//eg:a1b2c3d4e5f--15
#include<stdio.h>
#include<string.h>
int main()
{
	int i, sum = 0, length;
	char s[50];
	gets(s);
	length = strlen(s);
	for (i = 0; i <= length - 1; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)		//ASCII码中0-9对应48-57
		{
			sum += s[i] - 48;				//转化时-48
		}
	}
	printf("%d", sum);
	return 0;
}