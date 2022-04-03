#define _CRT_SECURE_NO_WARNINGS 1
//数学领域著名的“哥德巴赫猜想”的大致意思是：任何一个大于2的偶数总能表示为两个素数之和。
//比如：24 = 5 + 19，其中5和19都是素数。设计一个程序，验证20亿以内的偶数都可以分解成两个素数之和。
//输入在一行中给出一个(2, 2 000 000 000]范围内的偶数N。
//在一行中按照格式“N = p + q”输出N的素数分解，其中p ≤ q均为素数。
//又因为这样的分解不唯一（例如24还可以分解为7 + 17），要求必须输出所有解中p最小的解。
#include<stdio.h>
#include<math.h>

int main()
{
	int ifSuShu(long);
	long n, p, q;
	scanf("%ld", &n);
	//if (n % 2 != 0) printf("Error");
	for (p = 2; p <= n / 2; p++)
	{
		q = n - p;
		if (ifSuShu(p) == 1 && ifSuShu(q) == 1)
		{
			printf("%d = %d + %d",n, p, q);
			break;
		}
	}
	return 0;
}


int ifSuShu(long a)					//判断素数
{
	int bool, k=sqrt(a);
	long i;
	for (i = 2; i <= k; i++)
	{
		if (a % i == 0) break;
	}
	if (i <= k) bool = 0;
	else bool = 1;
	return bool;
}
