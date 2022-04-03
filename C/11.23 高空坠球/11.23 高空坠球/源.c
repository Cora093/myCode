#define _CRT_SECURE_NO_WARNINGS 1
//皮球从某给定高度自由落下，触地后反弹到原高度的一半，再落下，再反弹，……，如此反复。
//问皮球在第n次落地时，在空中一共经过多少距离？第n次反弹的高度是多少？
//输入在一行中给出两个非负整数，分别是皮球的初始高度和n，均在长整型范围内。
//在一行中顺序输出皮球第n次落地时在空中经过的距离、以及第n次反弹的高度，其间以一个空格分隔，保留一位小数。
//题目保证计算结果不超过双精度范围。
//eg: 33 5--94.9 1.0

#include<stdio.h>
#include<math.h>
int main(){
    double h, sum;
    unsigned long n, i;
    scanf("%lf %ld", &h, &n);
    sum = h;
    if (n == 0) printf("0.0 0.0");
    else if (n == 1) printf("%.1lf %.1lf", h, h / 2.0);
    else{
        for (i = 2; i <= n; i++){
            sum += h / pow(2, i - 2);
        }
        printf("%.1lf %.1lf", sum, h / pow(2, i - 1));
    }
    return 0;
}