#define _CRT_SECURE_NO_WARNINGS 1
//�ж���ż��
//����n���û���������Ͳ�������nΪż��ʱ����������1��nΪ����ʱ����0��ע�⣺0��ż����

#include <stdio.h>

int even(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int even(int n) {                        //�ж���ż��
    int res;
    if (n < 0) {
        n = -1 * n;
    }
    if (n % 2 == 0) {
        res = 1;
    }
    else {
        res = 0;
    }
    return res;
}