#define _CRT_SECURE_NO_WARNINGS 1
//ˮ�ɻ�����ָһ��Nλ��������N��3��������ÿ��λ�ϵ����ֵ�N����֮�͵������������磺153 
//����Ҫ���д����, ��������Nλˮ�ɻ�����
//������һ���и���һ��������N��3��N��7����
//������˳���������Nλˮ�ɻ�����ÿ������ռһ�С�

#include <stdio.h>

int main() {
	int quWeiShu(int num, int n);
	int power(int a, int b);
	int num, n;
	int i, j;
	int sum;
	scanf("%d", &n);
	for (num = power(10, n-1); num < power(10, n ); num++) {		//��Χ��nλ����
		sum = 0;
		for (j = n; j >= 1; j--) {
			sum += power(quWeiShu(num, j), n);							//�ۼ�ÿһλ��n�η�
			if (j > 1 && sum > num) {									//���Ѿ����ڱ�������
				break;
			}
		}
		if (sum == num) {
			printf("%d\n", num);
		}
	}

	return 0;
}

int quWeiShu(int num, int a) {											//ȡ�����ĵ�aλ
	int k;
	k = num % power(10, a)/ power(10,a - 1);
	return k;
}

int power(int a, int b) {
	int i, di;
	di = a;
	if (b == 0) {
		a = 1;
	}
	else{
		for (i = 1, a = 1; i <= b; i++) {
			a *= di;
		}
	}
	
	return a;
}
