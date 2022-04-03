#define _CRT_SECURE_NO_WARNINGS 1
//将一个3×3矩阵转置（即行和列互换）。
//在一行中输入9个小于100的整数，其间各以一个空格间隔。
//输出3行3列的二维数组，每个数据输出占4列。

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