#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��������N�������в��Ҹ�����X������ҵ������X��λ�ã���0��ʼ���������û���ҵ��������Not Found����
//�����ڵ�һ���и�������������N����20����X���ڶ��и���N�����������־������������ͣ�����Կո�ָ���
//��һ�������X��λ�ã����ߡ�Not Found����

#include<stdio.h>
int main()
{
	int n, x, i, shiFouZhaoDao = 0;
	int a[20];
	scanf("%d %d", &n, &x);
	for (i = 0; i <= n - 1; i++)			//��������
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i <= n - 1; i++)
	{
		if (x == a[i])
		{
			printf("%d", i);
			shiFouZhaoDao = 1;
		}
	}
	if (shiFouZhaoDao==0) printf("Not Found");
	return 0;
}