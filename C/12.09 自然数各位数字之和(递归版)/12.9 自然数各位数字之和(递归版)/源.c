#define _CRT_SECURE_NO_WARNINGS 1

//请编写函数，求自然数各位数字之和。
//说明：参数 number 为非负整数。函数值为 number 的各位数字之和。若 number 为零，则函数值为零。

#include <stdio.h>
int SumDigit(int number);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", SumDigit(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */

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
