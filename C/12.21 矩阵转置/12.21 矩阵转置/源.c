#define _CRT_SECURE_NO_WARNINGS 1
//��һ��3��3����ת�ã����к��л�������
//��һ��������9��С��100��������������һ���ո�����
//���3��3�еĶ�ά���飬ÿ���������ռ4�С�

#include <stdio.h>

int main() {
	int arr[3][3] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%4d", arr[j][i]);
		}
		printf("\n");
	}
	return 0;
}