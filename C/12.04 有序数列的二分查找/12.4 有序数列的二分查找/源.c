#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {										//二分法查找有序数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0, right = sz - 1;
	int num;
	scanf("%d", &num);
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num > arr[mid]) {
			left = mid + 1;
		}
		else if (num < arr[mid]) {
			right = mid - 1;
		}
		else {
			printf("找到了，下标是：%d", mid);
			break;
		}
	}
	if (left > right) {
		printf("找不到");
	}
	return 0;
}