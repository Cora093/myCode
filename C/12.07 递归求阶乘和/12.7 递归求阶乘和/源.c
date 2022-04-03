#define _CRT_SECURE_NO_WARNINGS 1
//本题要求实现一个计算非负整数阶乘的简单函数，并利用该函数求 1!+ 2!+ 3!+ ... + n!的值。
//函数fact应返回n的阶乘，建议用递归实现。
//函数factsum应返回 1!+ 2!+ ... + n!的值。题目保证输入输出在双精度范围内。
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
/* 你的代码将被嵌在这里 */
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
