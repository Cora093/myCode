#define _CRT_SECURE_NO_WARNINGS 1
//本题要求你写个程序把给定的符号打印成沙漏的形状。
//所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2
//符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
//给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
//输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。
//首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

#include <stdio.h>
int main() {
	char c;
	int n, i, j, sum[50] = {1}, yu, hang;
	scanf("%d %c", &n, &c);
	for (i = 1; i < 50; i++) {
		sum[i] = sum[i - 1] + 4 * i + 2;
	}
	for (i = 0; i < 50; i++) {
		if (sum[i] > n) {
			i = i - 1;
			break;
		}
	}
	yu = n - sum[i];
	hang = i;
	for (; i >= 0; i--) {								//前一半沙漏+中间行
		for (j = 0; j < hang - i; j++) {				//空格
			printf(" ");
		}
		for (j = 2 * i + 1; j >= 1; j--) {				//符号
			printf("%c", c);
		}
		printf("\n");
	}
	for (i = 1; i <= hang; i++) {						//后一半沙漏
		for (j = hang - i; j > 0; j--) {				//空格
			printf(" ");
		}
		for (j = 1; j <= 2 * i + 1; j++) {				//符号
			printf("%c", c);
		}
		printf("\n");
	}
	printf("%d", yu);
	return 0;
}