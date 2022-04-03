#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {                        //冒泡排序
    int a[1000];
    int i, j, t, n, k;
    scanf("%d", &n);
    const int n1 = n;
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }                                 
    for (j = 1; j < n ; j++) {     //外层执行j=n-1次，内层执行i=n-j-1次          
        for (i = 1; i <= n - j - 1; i++) {   
            if (a[i] > a[i + 1]) {
                t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
            }
        }
    }
    int end = a[n - 1] - a[0];          //最大值减最小值
    printf("MAX - MIN = %d\n", end);
    printf("顺序排列的结果是");
    for (k=n-1;k>=0;k--)                //从大到小输出n个数
    {
        printf("%d ", a[k]);            //下标从n-1到0
    }
    getchar();
    return 0;
}