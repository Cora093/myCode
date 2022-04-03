#define _CRT_SECURE_NO_WARNINGS 1
//找出含有10个元素一维数组中的最大值和最小值，并互换这两个数的位置。
//在一行中输入10个整数，数据之间只能用1个空格间隔。
//在一行中按照“max = 最大值, min = 最小值”的格式输出结果，最大值和最小值均原样输出，没有列宽控制。 
//在下一行中输出交换完最大值和最小值的一维数组，每个数据输出占5列。

#include <stdio.h>

int main() {					
	int find_max(int* a);
	int find_min(int* a);
	void change(int* a, int max, int min);
	int a[10] = { 0 };
	int* p = a;
	for (; p < (a + 10); p++) {						//输入数组
		scanf("%d", p);
	}
	int max = find_max(a);
	int min = find_min(a);
	printf("max=%d,min=%d\n", max, min);
	change(a, max, min);
	for (p = a; p < (a + 10); p++) {
		printf("%5d", *p);
	}
	return 0;
}

int find_max(int*a) {
	int max, * p = a;
	max = *p;
	for (; p < (a + 10); p++) {
		if (*p > max) {
			max = *p;
		}
	}
	return max;
}

int find_min(int* a) {
	int min, * p = a;
	min = *p;
	for (; p < (a + 10); p++) {
		if (*p < min) {
			min = *p;
		}
	}
	return min;

}

void change(int* a, int max, int min) {
	int* p = a;
	for (; p < (a + 10); p++) {
		if (*p == max) {
			*p = min;
			continue;
		}
		if (*p == min) {
			*p = max;
		}
	}
}
