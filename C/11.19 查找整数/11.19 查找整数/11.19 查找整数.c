#define _CRT_SECURE_NO_WARNINGS 1
//本题要求从输入的N个整数中查找给定的X。如果找到，输出X的位置（从0开始数）；如果没有找到，输出“Not Found”。
//输入在第一行中给出两个正整数N（≤20）和X，第二行给出N个整数。数字均不超过长整型，其间以空格分隔。
//在一行中输出X的位置，或者“Not Found”。

#include<stdio.h>
int main()
{
	int n, x, i, shiFouZhaoDao = 0;
	int a[20];
	scanf("%d %d", &n, &x);
	for (i = 0; i <= n - 1; i++)			//输入数组
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i <= n - 1; i++)
	{
		if (x == a[i])
		{
			printf("%d", i);
			shiFouZhaoDao = 1;
		}
	}
	if (shiFouZhaoDao==0) printf("Not Found");
	return 0;
}