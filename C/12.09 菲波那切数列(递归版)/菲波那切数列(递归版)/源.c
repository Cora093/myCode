#define _CRT_SECURE_NO_WARNINGS 1
//请编写递归函数，求菲波那切(Fibonacci)数列某一项的值。
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
//说明：参数 index 为数列项的索引号，从 0 开始计数。
//函数值为 Fibonacci 数列第 index 项的值。若 index 值无效，则函数值为 0。

#include <stdio.h>

double Fib(int index);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%g\n", Fib(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */

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
