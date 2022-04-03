#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//本题要求计算并输出不超过n的最大的k个素数以及它们的和。
//输入：在一行中给出n(10≤n≤10000)和k(1≤k≤10)的值。		
//输出:"素数1 + 素数2 + … + 素数k = 总和值"					
//其中素数按递减顺序输出。若n以内不够k个素数，则按实际个数输出。		
//12 6--11+7+5+3+2=28		1000 10--997+991+983+977+971+967+953+947+941+937=9664

int main()								//依次输出
{
	int n, k, i, j = 1, sum = 0;
	scanf("%d%d", &n, &k);
	for (; n >= 2; n--)
	{
		if (j <= k)						//判断是否已经k个素数
		{
			for (i = 2; i <= n; i++)	//判断素数
			{
				if (i == n)				//如果是素数,累加
				{
					sum += n;
					printf("%d", n);
					if (j < k && n != 2) printf("+");
					j++;
				}
				if (n % i == 0)			//如果不是素数,n-1
					break;
			}
		}
		else break;
	}
	printf("=%d", sum);
	return 0;
}