#define _CRT_SECURE_NO_WARNINGS 1
//本题要求实现一个函数，统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数。
//其中传入的参数int n是一个三位数的正整数（最高位数字非0）。
//函数search返回[101, n]区间内所有满足条件的数的个数。eg:500 6
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
/* 你的代码将被嵌在这里 */

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
