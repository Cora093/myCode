#define _CRT_SECURE_NO_WARNINGS 1

//�����Ŀ��ܼ򵥣������ж�һ���������������Ƿ�������
//�����ڵ�һ�и���һ��������N���� 10�������N�У�ÿ�и���һ��С��2^31����Ҫ�жϵ���������
//��ÿ����Ҫ�жϵ��������������������������һ�������Yes���������No��

#include <stdio.h>
#include <math.h>

int main() {
	int ifSuShu(unsigned int a);
	unsigned int i, n, num;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num);
		if (ifSuShu(num) == 1) {
			printf("Yes");
		}
		else {
			printf("No");
		}
		if (i != n) {
			printf("\n");
		}
	}
	return 0;
}

int ifSuShu(unsigned int a) {							//�ж�����
	unsigned int answer, i, k = sqrt(a);
	if (a == 1) {
		answer = 0;
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