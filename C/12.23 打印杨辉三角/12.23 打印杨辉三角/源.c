#define _CRT_SECURE_NO_WARNINGS 1

//打印杨辉三角
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
//1 6 15 20 15 6 1

#include <stdio.h>

typedef unsigned long long ull;

void yanghui(int n) {
	if (n == 1) {
		printf(" 1 \n");
	}
	else if (n == 2) {
		printf(" 1  1 \n");
	}
	else {
		yanghui(1);
		yanghui(2);
		int i = 0, j = 0;				//计数
		int row = 0, lastrow = 1;
		ull arr[2][1000] = { {1},{1,1} };//二维数组每行替换
		for (i = 3; i <= n; i++) {
			int left = 0, right = n - 1;
			arr[row][left] = 1;
			arr[row][right] = 1;
			while (left < right) {
				arr[row][left + 1] = arr[lastrow][left] + arr[lastrow][left + 1];
				left++;
			}
			for (j = 0; j < i; j++) {
				printf("%2lld ", arr[row][j]);
			}
			printf("\n");
			//行标对换	
			if (row == 1) {
				row = 0; 
				lastrow = 1;
			}
			else if (row == 0) {
				row = 1;
				lastrow = 0;
			}
		}
	}
	
}

int main() {
	int n = 0;
	printf("请输入正整数：");
	scanf("%d", &n);		//行数
	yanghui(n);
	return 0;
}