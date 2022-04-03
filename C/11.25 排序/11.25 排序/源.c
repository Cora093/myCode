#define _CRT_SECURE_NO_WARNINGS 1
//�����һ�и���һ��������10��������n���ڶ��и���n������������Կո�ָ���
//��һ��������Ӵ�С��������У��������ּ���һ���ո���ĩ�����ж���ո�

#include <stdio.h>
int main() {
	void bubble_sort(int* a, int size);
	void select_sort(int* a, int size);
	int n, i, a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {					//����
		scanf("%d", &a[i]);
	}

	select_sort(a, n);							//��С��������

	for (i = n - 1; i >= 0; i--) {				//���
		printf("%d", a[i]);
		if (i > 0) {
			printf(" ");
		}
	}
	return 0;
}


void bubble_sort(int* a, int size) {				//ð�����򣺽����ֵ����
	int i, j, t;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (a[j] > a[j + 1]) {			
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void select_sort(int* a, int size) {				//ѡ������
	int i, j, tmp, max;
	for (i = 0; i < size - 1; i++) {
		max = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] > a[max]) {
				max = j;
			}
		}
		tmp = a[max]; a[max] = a[i]; a[i] = tmp;
	}

}