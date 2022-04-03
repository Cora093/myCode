#define _CRT_SECURE_NO_WARNINGS 1
//本题要求两个给定正整数的最大公约数和最小公倍数。
//输入在一行中给出两个正整数M和N（≤1000）。
//在一行中顺序输出M和N的最大公约数和最小公倍数，两数字间以1空格分隔。
// eg:511 292--73 2044
#include<stdio.h>

int MAX(int j, int k)				//最大值
{
	int max;
	j > k ? (max = k) : (max = j);
	return max;
}						
int MIN(int j, int k)				//最小值
{
	int min;
	j < k ? (min = j) : (min = k);
	return min;
}									
int main()
{
	//int a, b, i;
	//scanf("%d%d", &a, &b);
	//for (i = MIN(a, b);; i--)		//最大公约数
	//{
	//	if (a % i == 0 && b % i == 0)
	//	{
	//		printf("%d ", i);
	//		break;
	//	}
	//}

	//for (i = MAX(a, b);; i++)		//最小公倍数
	//{
	//	if (i % a == 0 && i % b == 0)
	//	{
	//		printf("%d", i);
	//		break;
	//	}
	//}

	//辗转相除法求最大公约数
	int m, n, t;
	scanf("%d %d", &m, &n);
	while(t = m % n) {
		m = n;
		n = t;
	}
	printf("最大公约数为%d", n);
	return 0;
}