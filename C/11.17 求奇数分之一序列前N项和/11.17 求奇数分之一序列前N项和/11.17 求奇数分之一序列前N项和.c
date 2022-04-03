#define _CRT_SECURE_NO_WARNINGS 1
//求奇数分之一序列前N项和
//本题要求编写程序，计算序列 1 + 1 / 3 + 1 / 5 + ... 的前N项之和。
//输入在一行中给出一个正整数N。
//在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后6位。计算结果不超过双精度范围。
//eg: 23--sum = 2.549541
#include<stdio.h>
int main()
{
	int i, n;
	double sum = 0;				//double和float的位数
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += 1.0 / (2 * i - 1);

	}
	printf("sum = %.6f", sum);
}