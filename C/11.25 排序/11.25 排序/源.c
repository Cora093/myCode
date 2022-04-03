#define _CRT_SECURE_NO_WARNINGS 1
//输入第一行给出一个不超过10的正整数n。第二行给出n个整数，其间以空格分隔。
//在一行中输出从大到小有序的数列，相邻数字间有一个空格，行末不得有多余空格。

#include <stdio.h>
int main() {
	void bubble_sort(int* a, int size);
	void select_sort(int* a, int size);
	int n, i, a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {					//输入
		scanf("%d", &a[i]);
	}

	select_sort(a, n);							//由小到大排序

	for (i = n - 1; i >= 0; i--) {				//输出
		printf("%d", a[i]);
		if (i > 0) {
			printf(" ");
		}
	}
	return 0;
}


void bubble_sort(int* a, int size) {				//冒泡排序：将最大值后移
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

void select_sort(int* a, int size) {				//选择排序：
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