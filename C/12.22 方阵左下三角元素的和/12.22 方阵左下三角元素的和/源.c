#define _CRT_SECURE_NO_WARNINGS 1
//����һ��4��4���飬��һ��4��4������������(�������Խ���)Ԫ�صĺ͡�
//����4��4�еķ���ÿ�е�һ����ǰû�пո�ÿ�е�ÿ����֮�����һ���ո�
//ֱ�������������(�������Խ���)Ԫ�صĺ͡�û�������κθ����ַ�

#include <stdio.h>
#define side 4

int main() {
	int arr[side][side] = { 0 };
	int i = 0, j = 0;
	int sum = 0;
	for (i = 0; i < side; i++) {
		for (j = 0; j < side; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < side; i++) {
		for (j = 0; j <= i; j++) {
			sum += arr[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}