#define _CRT_SECURE_NO_WARNINGS 1
//本题要求编写程序，将一个给定的整数插到原本有序的整数序列中，使结果序列仍然有序。
//输入在第一行先给出非负整数N（ < 10）；第二行给出N个从小到大排好顺序的整数；第三行给出一个整数X。
//在一行内输出将X插入后仍然从小到大有序的整数序列，每个数字后面有一个空格。
//eg:5,1 2 4 5 7,3--1 2 3 4 5 7 

#include<stdio.h>
int main()
{
	int n, i, x, j, a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	for (i = 0; i <= n; i++){
		if (i == n) a[i] = x;
		if (a[i] >= x){
			for (j = 9; j > i; j--)
				a[j] = a[j - 1];
			a[i] = x;
			break;
		}
	}
	for (i = 0; i <= n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}