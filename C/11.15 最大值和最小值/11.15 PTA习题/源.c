#define _CRT_SECURE_NO_WARNINGS 1
//给定一个正整数 N，接下来输入 N 个正整数
//找出它们中的最大值和最小值，输出最大值减最小值。
//输入格式:一个正整数 N 接下来连续输入 N 个正整数
//输出格式:输出整数中的 最大值减去最小值 的结果
#include<stdio.h>
int main() {
    int max, min, N, a, b, i;
    printf("给定一个正整数 N，接下来输入 N 个正整数\n");
    scanf("%d", &N);
    scanf("%d", &a);
    for (i=1;i<N;i++){
        scanf("%d", &b);
        while (i == 1) {                    //判断最先的两个数
            if (a >= b) {                   
                max = a, min = b;
            }
            else max = b, min = a;
            break;
        }
        if (b >= max) max = b;              //依次比较
        if (b <= min) min = b;
    }
    printf("MAX - MIN = %d", max - min);
    return 0;
}
