#define _CRT_SECURE_NO_WARNINGS 1
//判断奇偶性
//其中n是用户传入的整型参数。当n为偶数时，函数返回1；n为奇数时返回0。注意：0是偶数。

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

/* 你的代码将被嵌在这里 */
int even(int n) {                        //判断奇偶性
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