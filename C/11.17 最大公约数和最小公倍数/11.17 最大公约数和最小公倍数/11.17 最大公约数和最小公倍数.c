#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ���������������������Լ������С��������
//������һ���и�������������M��N����1000����
//��һ����˳�����M��N�����Լ������С�������������ּ���1�ո�ָ���
// eg:511 292--73 2044
#include<stdio.h>

int MAX(int j, int k)				//���ֵ
{
	int max;
	j > k ? (max = k) : (max = j);
	return max;
}						
int MIN(int j, int k)				//��Сֵ
{
	int min;
	j < k ? (min = j) : (min = k);
	return min;
}									
int main()
{
	//int a, b, i;
	//scanf("%d%d", &a, &b);
	//for (i = MIN(a, b);; i--)		//���Լ��
	//{
	//	if (a % i == 0 && b % i == 0)
	//	{
	//		printf("%d ", i);
	//		break;
	//	}
	//}

	//for (i = MAX(a, b);; i++)		//��С������
	//{
	//	if (i % a == 0 && i % b == 0)
	//	{
	//		printf("%d", i);
	//		break;
	//	}
	//}

	//շת����������Լ��
	int m, n, t;
	scanf("%d %d", &m, &n);
	while(t = m % n) {
		m = n;
		n = t;
	}
	printf("���Լ��Ϊ%d", n);
	return 0;
}