#define _CRT_SECURE_NO_WARNINGS 1
//任意输入n(n < 10)个不超过100的整数放在一个数组中，然后在逆序存储后输出。
//先输入n值回车，然后再输入n个不超过100的整数。
//输出逆序存储后的n个整数，每个数据占3列。
//eg:5,1 2 3 4 5--  5  4  3  2  1
#include<stdio.h>
int main()
{
	int a[9];
	int n, i, m;
	scanf("%d", &n);
	for (i = 8; i >= 9-n; i--)
	{
		scanf("%d", &a[i]);
	}
	for (i = 9 - n; i <= 8; i++)
	{
		printf("  %d", a[i]);
	}
	return 0;
}