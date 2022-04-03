#define _CRT_SECURE_NO_WARNINGS 1
//编写一个函数fun，功能是计算给定整数n的所有因子(不包括1和自身)之和，和值通过指针变量间接传回主函数。

#include <stdio.h>
void fun(int n, int* m);
int main()
{
	int s, n;
	scanf("%d", &n);
	fun(n, &s);
	printf("%d\n", s);
	return 0;
}

/* 请在这里填写答案 */
void fun(int n, int* m) {
	*m = 0;
	int i = 0;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			*m += i;
		}
	}
}
