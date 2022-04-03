#define _CRT_SECURE_NO_WARNINGS 1
//请编写函数，求自然数的位数。
//说明：参数 number 为非负整数。函数值为 number 的位数。若 number 为零，则函数值为零。
//不得使用循环语句

#include <stdio.h>
int NumDigit(int number);
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", NumDigit(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */

int NumDigit(int number) {
    int count = 1;
    if (number == 0) {
        return 0;
    }
    else if (number / 10 < 1) {
        return count;
    }
    else {
        return 1 + NumDigit(number / 10);
    }
}
