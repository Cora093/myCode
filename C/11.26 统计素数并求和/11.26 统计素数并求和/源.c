#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��ͳ�Ƹ�������M��N�����������ĸ�������������͡�
//������һ���и�������������M��N��1��M��N��500����
//��һ����˳�����M��N�����������ĸ����Լ����ǵĺͣ����ּ��Կո�ָ���

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

int ifSuShu(int a)							//�ж�����
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