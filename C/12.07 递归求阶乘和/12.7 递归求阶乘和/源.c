#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��ʵ��һ������Ǹ������׳˵ļ򵥺����������øú����� 1!+ 2!+ 3!+ ... + n!��ֵ��
//����factӦ����n�Ľ׳ˣ������õݹ�ʵ�֡�
//����factsumӦ���� 1!+ 2!+ ... + n!��ֵ����Ŀ��֤���������˫���ȷ�Χ�ڡ�
//eg:fact(10) = 3628800 sum = 4037913
#include <stdio.h>

double fact(int n);
double factsum(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
double fact(int n) {
    if (n == 0||n==1) {
        return 1;
    }
    else {
        return fact(n-1)*n;
    }
}
double factsum(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return fact(n) + factsum(n - 1);
    }
}
