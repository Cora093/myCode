#define _CRT_SECURE_NO_WARNINGS 1
//��������֮һ����ǰN���
//����Ҫ���д���򣬼������� 1 + 1 / 3 + 1 / 5 + ... ��ǰN��֮�͡�
//������һ���и���һ��������N��
//��һ���а��ա�sum = S���ĸ�ʽ������ֺ͵�ֵS����ȷ��С�����6λ��������������˫���ȷ�Χ��
//eg: 23--sum = 2.549541
#include<stdio.h>
int main()
{
	int i, n;
	double sum = 0;				//double��float��λ��
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += 1.0 / (2 * i - 1);

	}
	printf("sum = %.6f", sum);
}