#define _CRT_SECURE_NO_WARNINGS 1

//输入第一行给出正整数n（ < 10），随后给出n本书的信息。
//每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。
//在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。

#include <stdio.h>


struct book {
	char name[31];
	float price;
}books[10] = { 0 };

int main() {
	int n = 0;//个数
	int i = 0;//计数
	int j = 0;
	float a[10] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//输入
		getchar();
		gets(books[i].name);
		scanf("%f", &books[i].price);
		a[i] = books[i].price;
	}
	int max = 0, min = 0;
	for (i = 0; i < n; i++) {//遍历找最大值最小值
		if (a[max] < a[i]) {
			max = i;
		}
		if (a[min] > a[i]) {
			min = i;
		}
	}
	//输出
	printf("%.2f, %s", books[max].price, books[max].name);
	if (n > 1) {
		printf("\n%.2f, %s", books[min].price, books[min].name);
	}
	return 0;
}