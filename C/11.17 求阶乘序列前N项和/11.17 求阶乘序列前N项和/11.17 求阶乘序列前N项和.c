#define _CRT_SECURE_NO_WARNINGS 1
//求阶乘序列前N项和
//本题要求编写程序，计算序列 1!+ 2!+ 3!+ ⋯ 的前N项之和。
//输入在一行中给出一个不超过12的正整数N。
//在一行中输出整数结果。
//eg: 5--153

#include<stdio.h>
int main()
{
	int n, i = 1, j = 1;
	long sum = 0, k = 1;
	scanf("%d", &n);
	for (; i <= n; i++)
	{
		for (j = i; j > 0; j--)
		{
			k *= j;
		}
		sum += k;
		k = 1;
	}
	printf("%d", sum);
	return 0;
}