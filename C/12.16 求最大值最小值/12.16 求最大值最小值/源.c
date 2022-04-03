#define _CRT_SECURE_NO_WARNINGS 1
//用指针作函数参数，编程序求一维数组中的最大和最小的元素值。

#include<stdio.h>
#define N 10
void maxmin(int arr[], int* pt1, int* pt2, int n);
int main()
{
	int array[N] = { 10,7,19,29,4,0,7,35,-16,21 }, * p1, * p2, a, b;
	p1 = &a; p2 = &b;
	maxmin(array, p1, p2, N);
	printf("max=%d,min=%d", a, b);
	return 0;
}
/* 请在这里填写答案 */
void maxmin(int arr[], int* pt1, int* pt2, int n) {
	int i = 0, j = 0;
	int t = 0;
	int* p = arr;
	//冒泡排序 由大到小
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	*pt1 = *p;
	*pt2 = *(p + 9);
}
