#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ��ʵ��һ���õݹ����1 + 2 + 3 + �� + n�ĺ͵ļ򵥺�����
//�ú������ڴ����������n����1 + 2 + 3 + �� + n�ĺͣ���n�����������򷵻�0��
//��Ŀ��֤��������ڳ����ͷ�Χ�ڡ����鳢��д�ɵݹ麯����
#include <stdio.h>

int sum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
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
