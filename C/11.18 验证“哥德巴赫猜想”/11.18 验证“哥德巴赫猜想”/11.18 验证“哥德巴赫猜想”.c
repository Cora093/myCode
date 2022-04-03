#define _CRT_SECURE_NO_WARNINGS 1
//��ѧ���������ġ���°ͺղ��롱�Ĵ�����˼�ǣ��κ�һ������2��ż�����ܱ�ʾΪ��������֮�͡�
//���磺24 = 5 + 19������5��19�������������һ��������֤20�����ڵ�ż�������Էֽ����������֮�͡�
//������һ���и���һ��(2, 2 000 000 000]��Χ�ڵ�ż��N��
//��һ���а��ո�ʽ��N = p + q�����N�������ֽ⣬����p �� q��Ϊ������
//����Ϊ�����ķֽⲻΨһ������24�����Էֽ�Ϊ7 + 17����Ҫ�����������н���p��С�Ľ⡣
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


int ifSuShu(long a)					//�ж�����
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
