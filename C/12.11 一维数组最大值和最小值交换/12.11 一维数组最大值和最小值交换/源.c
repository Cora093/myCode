#define _CRT_SECURE_NO_WARNINGS 1
//�ҳ�����10��Ԫ��һά�����е����ֵ����Сֵ������������������λ�á�
//��һ��������10������������֮��ֻ����1���ո�����
//��һ���а��ա�max = ���ֵ, min = ��Сֵ���ĸ�ʽ�����������ֵ����Сֵ��ԭ�������û���п���ơ� 
//����һ����������������ֵ����Сֵ��һά���飬ÿ���������ռ5�С�

#include <stdio.h>

int main() {					
	int find_max(int* a);
	int find_min(int* a);
	void change(int* a, int max, int min);
	int a[10] = { 0 };
	int* p = a;
	for (; p < (a + 10); p++) {						//��������
		scanf("%d", p);
	}
	int max = find_max(a);
	int min = find_min(a);
	printf("max=%d,min=%d\n", max, min);
	change(a, max, min);
	for (p = a; p < (a + 10); p++) {
		printf("%5d", *p);
	}
	return 0;
}

int find_max(int*a) {
	int max, * p = a;
	max = *p;
	for (; p < (a + 10); p++) {
		if (*p > max) {
			max = *p;
		}
	}
	return max;
}

int find_min(int* a) {
	int min, * p = a;
	min = *p;
	for (; p < (a + 10); p++) {
		if (*p < min) {
			min = *p;
		}
	}
	return min;

}

void change(int* a, int max, int min) {
	int* p = a;
	for (; p < (a + 10); p++) {
		if (*p == max) {
			*p = min;
			continue;
		}
		if (*p == min) {
			*p = max;
		}
	}
}
