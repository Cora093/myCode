#define _CRT_SECURE_NO_WARNINGS 1
//��дһ������fun�������Ǽ����������n����������(������1������)֮�ͣ���ֵͨ��ָ�������Ӵ�����������

#include <stdio.h>
void fun(int n, int* m);
int main()
{
	int s, n;
	scanf("%d", &n);
	fun(n, &s);
	printf("%d\n", s);
	return 0;
}

/* ����������д�� */
void fun(int n, int* m) {
	*m = 0;
	int i = 0;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			*m += i;
		}
	}
}
