#define _CRT_SECURE_NO_WARNINGS 1
//�ҳ���Сֵ
//������һ�������ȸ���һ��������n��֮����n������������Կո�ָ���
//��һ���а��ա�min = ��Сֵ���ĸ�ʽ���n�������е���Сֵ��

#include<stdio.h>
int main()
{
	int n, a, b, min;
	scanf("%d", &n);
	scanf("%d", &a);
	scanf("%d", &b);
	//if (a >= b) min = b;
	//else min = a;
	a >= b ? (min = b) : (min = a);	
	for (n -= 2; n > 0; n--)
	{
		scanf("%d", &b);
		if (b < min) min = b;
	}
	printf("min = %d", min);
	return 0;
}