#define _CRT_SECURE_NO_WARNINGS 1

//�����һ�и���������n�� < 10����������n�������Ϣ��
//ÿ������һ���и��������������Ȳ�����30���ַ��������һ���и�����ʵ���۸���Ŀ��֤û��ͬ���۸���顣
//��һ���а��ա��۸�, �������ĸ�ʽ�Ⱥ�����۸���ߺ���͵��顣�۸���2λС����

#include <stdio.h>


struct book {
	char name[31];
	float price;
}books[10] = { 0 };

int main() {
	int n = 0;//����
	int i = 0;//����
	int j = 0;
	float a[10] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//����
		getchar();
		gets(books[i].name);
		scanf("%f", &books[i].price);
		a[i] = books[i].price;
	}
	int max = 0, min = 0;
	for (i = 0; i < n; i++) {//���������ֵ��Сֵ
		if (a[max] < a[i]) {
			max = i;
		}
		if (a[min] > a[i]) {
			min = i;
		}
	}
	//���
	printf("%.2f, %s", books[max].price, books[max].name);
	if (n > 1) {
		printf("\n%.2f, %s", books[min].price, books[min].name);
	}
	return 0;
}