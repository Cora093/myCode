#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��ʵ��һ���������ú����ܽ����β�p1,p2��ָ�洢�ռ���ֵ���β�p1,p2Ϊָ�롣
#include <stdio.h>
void change(int* p, int* q);
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	change(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}

/* ����������д�� */
void change(int* p, int* q) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}