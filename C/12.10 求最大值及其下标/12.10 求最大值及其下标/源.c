#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ���д�����ҳ�������n�����е����ֵ�����Ӧ����С�±꣨�±��0��ʼ����
//�����ڵ�һ���и���һ��������n��1 < n��10�����ڶ�������n���������ÿո�ֿ���
//��һ����������ֵ�����ֵ����С�±꣬�м���һ���ո�ֿ�

#include <stdio.h>

int find_max(int* arr, int size) {				//�ҳ����ֵ����
	int max;
	int* p = arr;
	max = *p;
	while (p < (arr + size)) {
		if (*p > max) {
			max = *p;
		}
		p++;
	}
	return max;
}

int find_sub(int* arr, int size, int max) {		//�������ֵ���±�
	int sub;
	for (sub = 0; sub < size; sub++) {
		if (*(arr + sub) == max) {
			return sub;
		}
	}
}

int main() {
	int find_max(int*, int);
	int find_sub(int*, int, int);
	int* p, size = 0;
	int a[10] = { 0 };
	scanf("%d\n", &size);						//���������С
	for (p = a; p < (a + size); p++) {			//��������
		scanf("%d", p);
	}
	int max = find_max(a, size);
	int sub = find_sub(a, size, max);
	printf("%d %d\n", max, sub);

	return 0;
}