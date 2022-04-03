#define _CRT_SECURE_NO_WARNINGS 1
//一对兔子，从出生后第3个月起每个月都生一对兔子。小兔子长到第3个月后每个月又生一对兔子。
//假如兔子都不死，请问第1个月出生的一对兔子，至少需要繁衍到第几个月时兔子总数才可以达到N对？
//输入在一行中给出一个不超过10000的正整数N。
//在一行中输出兔子总数达到N最少需要的月数。
//eg:30--9
#include<stdio.h>
int main()
{
	int n, m;
	int a1 = 1, a2 = 1, a3;
	scanf("%d", &n);
	if(n==1) printf("1");
	else
	{
		for (m = 3;; m++)
		{
			a3 = a1 + a2;
			if (a3 >= n) break;
			a1 = a2; a2 = a3;
		}
		printf("%d", m);
	}
	return 0;
}