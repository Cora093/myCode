#define _CRT_SECURE_NO_WARNINGS 1
//本题要求编写程序，找出给定的n个数中的最大值及其对应的最小下标（下标从0开始）。
//输入在第一行中给出一个正整数n（1 < n≤10）。第二行输入n个整数，用空格分开。
//在一行中输出最大值及最大值的最小下标，中间用一个空格分开

#include <stdio.h>

int find_max(int* arr, int size) {				//找出最大值返回
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

int find_sub(int* arr, int size, int max) {		//返回最大值的下标
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
	scanf("%d\n", &size);						//输入数组大小
	for (p = a; p < (a + size); p++) {			//输入数据
		scanf("%d", p);
	}
	int max = find_max(a, size);
	int sub = find_sub(a, size, max);
	printf("%d %d\n", max, sub);

	return 0;
}