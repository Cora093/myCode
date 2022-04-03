#define _CRT_SECURE_NO_WARNINGS 1
//找出最小值
//输入在一行中首先给出一个正整数n，之后是n个整数，其间以空格分隔。
//在一行中按照“min = 最小值”的格式输出n个整数中的最小值。

#include<stdio.h>
int main()
{
	int n, a, b, min;
	scanf("%d", &n);
	scanf("%d", &a);
	scanf("%d", &b);
	//if (a >= b) min = b;
	//else min = a;
	a >= b ? (min = b) : (min = a);	
	for (n -= 2; n > 0; n--)
	{
		scanf("%d", &b);
		if (b < min) min = b;
	}
	printf("min = %d", min);
	return 0;
}