#define _CRT_SECURE_NO_WARNINGS 1

//���д����������Ȼ����λ����֮�͡�
//˵�������� number Ϊ�Ǹ�����������ֵΪ number �ĸ�λ����֮�͡��� number Ϊ�㣬����ֵΪ�㡣

#include <stdio.h>
int SumDigit(int number);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", SumDigit(n));
    return 0;
}

/* ���ύ�Ĵ��뽫��Ƕ������ */

int SumDigit(int number) {
    if (number == 0) {
        return 0;
    }
    else if (number / 10 == 0) {
        return number;
    }
    else {
        return SumDigit(number / 10) + number % 10;
    }
}
