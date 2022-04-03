#define _CRT_SECURE_NO_WARNINGS 1
//本题要求实现一个函数，该函数能交换形参p1,p2所指存储空间中值。形参p1,p2为指针。
#include <stdio.h>
void change(int* p, int* q);
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	change(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}

/* 请在这里填写答案 */
void change(int* p, int* q) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}