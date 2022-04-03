#define _CRT_SECURE_NO_WARNINGS 1
//输入一个4×4数组，求一个4×4数组左下三角(包括主对角线)元素的和。
//输入4行4列的方阵，每行第一个数前没有空格，每行的每个数之间各有一个空格。
//直接输出左下三角(包括主对角线)元素的和。没有其它任何附加字符

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