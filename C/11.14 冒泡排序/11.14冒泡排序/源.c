#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {                        //ð������
    int a[1000];
    int i, j, t, n, k;
    scanf("%d", &n);
    const int n1 = n;
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }                                 
    for (j = 1; j < n ; j++) {     //���ִ��j=n-1�Σ��ڲ�ִ��i=n-j-1��          
        for (i = 1; i <= n - j - 1; i++) {   
            if (a[i] > a[i + 1]) {
                t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
            }
        }
    }
    int end = a[n - 1] - a[0];          //���ֵ����Сֵ
    printf("MAX - MIN = %d\n", end);
    printf("˳�����еĽ����");
    for (k=n-1;k>=0;k--)                //�Ӵ�С���n����
    {
        printf("%d ", a[k]);            //�±��n-1��0
    }
    getchar();
    return 0;
}