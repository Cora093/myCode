#define _CRT_SECURE_NO_WARNINGS 1
//��һ����ά�����ܱ�Ԫ�ص��ۼӺ͡�
//��һ������һ����ά���������m��m < 10��������n(n < 10)
//�ڶ��������ά����ĸ�Ԫ��ֵ��
//����ܱ�Ԫ��֮�͡�

#include <stdio.h>

int main() {
	int m = 0, n = 0;
	int i, j;
	int arr[10][10];
	int sum = 0;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", *(arr + i) + j);
			sum += *(*(arr + i) + j);
		}
	}
	for (i = 1; i < m - 1; i++) {
		for (j = 1; j < n - 1; j++) {
			sum -= *(*(arr + i) + j);
		}
	}
	printf("%d", sum);
	return 0;
}