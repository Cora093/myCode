#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��ʵ��һ��������ͳ�Ƹ��������ڵ���λ��������λ������ͬ����ȫƽ��������144��676���ĸ�����
//���д���Ĳ���int n��һ����λ���������������λ���ַ�0����
//����search����[101, n]�����������������������ĸ�����eg:500 6
#include <stdio.h>
#include <math.h>

int search(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */

int search(int n) {
    int count = 0;
    int num = 11, a, b, c;
    for (; pow(num, 2) <= n; num++) {
        a = (int)pow(num, 2) % 10;
        b = (int)pow(num, 2) / 10 % 10;
        c = (int)pow(num, 2) / 100;
        if (a == b || b == c || a == c) {
            count++;
        }
    }
    return count;
}
