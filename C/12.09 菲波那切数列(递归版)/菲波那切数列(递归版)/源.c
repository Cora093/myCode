#define _CRT_SECURE_NO_WARNINGS 1
//���д�ݹ麯������Ʋ�����(Fibonacci)����ĳһ���ֵ��
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
//˵�������� index Ϊ������������ţ��� 0 ��ʼ������
//����ֵΪ Fibonacci ���е� index ���ֵ���� index ֵ��Ч������ֵΪ 0��

#include <stdio.h>

double Fib(int index);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%g\n", Fib(n));
    return 0;
}

/* ���ύ�Ĵ��뽫��Ƕ������ */

double Fib(int index){
    if (index <= 0) {
        return 0;
    }
    else if (index == 2 || index == 1) {
        return 1;
    }
    else {
        return Fib(index - 1) + Fib(index - 2);
    }
}
