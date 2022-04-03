#define _CRT_SECURE_NO_WARNINGS 1
//求一个二维数组周边元素的累加和。
//第一行输入一个二维数组的行数m（m < 10），列数n(n < 10)
//第二行输入二维数组的各元素值。
//输出周边元素之和。

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