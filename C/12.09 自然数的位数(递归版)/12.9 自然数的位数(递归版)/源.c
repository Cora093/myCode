#define _CRT_SECURE_NO_WARNINGS 1
//���д����������Ȼ����λ����
//˵�������� number Ϊ�Ǹ�����������ֵΪ number ��λ������ number Ϊ�㣬����ֵΪ�㡣
//����ʹ��ѭ�����

#include <stdio.h>
int NumDigit(int number);
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", NumDigit(n));
    return 0;
}

/* ���ύ�Ĵ��뽫��Ƕ������ */

int NumDigit(int number) {
    int count = 1;
    if (number == 0) {
        return 0;
    }
    else if (number / 10 < 1) {
        return count;
    }
    else {
        return 1 + NumDigit(number / 10);
    }
}
