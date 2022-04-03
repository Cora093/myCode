#define _CRT_SECURE_NO_WARNINGS 1
//本题要求统计给定整数M和N区间内素数的个数并对它们求和。
//输入在一行中给出两个正整数M和N（1≤M≤N≤500）。
//在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

#include <stdio.h>
#include <math.h>
int main() {
	int ifSuShu(int a);
	unsigned int m, n;
	int i, sum = 0, geshu = 0;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++) {
		if (ifSuShu(i) == 1) {
			sum += i;
			geshu++;
		}
	}
	printf("%d %d", geshu, sum);
	return 0;
}

int ifSuShu(int a)							//判断素数
{
	int answer, k = sqrt(a);
	int i;
	if (a == 0) {
		answer = 1;
	}
	else {
		for (i = 2; i <= k; i++)
		{
			if (a % i == 0) break;
		}
		if (i <= k) answer = 0;
		else answer = 1;
	}
	return answer;
}