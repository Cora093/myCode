#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void findmax(int* px, int* py, int* pmax);
//其中px和py是用户传入的两个整数的指针。
//函数findmax应找出两个指针所指向的整数中的最大值，存放在pmax指向的位置。
int main()
{
    int max, x, y;

    scanf("%d %d", &x, &y);
    findmax(&x, &y, &max);
    printf("%d\n", max);

    return 0;
}

/* 你的代码将被嵌在这里 */
void findmax(int* px, int* py, int* pmax) {

    if (*px > *py) {
        *pmax = *px;
    }
    else *pmax = *py;
}
