#define _CRT_SECURE_NO_WARNINGS 1
//本题要求实现一个用递归计算1 + 2 + 3 + … + n的和的简单函数。
//该函数对于传入的正整数n返回1 + 2 + 3 + … + n的和；若n不是正整数则返回0。
//题目保证输入输出在长整型范围内。建议尝试写成递归函数。
#include <stdio.h>

int sum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
/* 你的代码将被嵌在这里 */
int sum(int n) {
    int result;
    if (n - n / 1 != 0) {
        result = 0;
    }
    else if (n <= 0) {
        result = 0;
    }
    else if (n == 1) {
        result = 1;
    }
    else {
        result = sum(n - 1) + n;
    }
    return result;
}
