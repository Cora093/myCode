#define _CRT_SECURE_NO_WARNINGS 1
//��������n(n < 10)��������100����������һ�������У�Ȼ��������洢�������
//������nֵ�س���Ȼ��������n��������100��������
//�������洢���n��������ÿ������ռ3�С�
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