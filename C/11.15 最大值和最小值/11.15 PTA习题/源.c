#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������� N������������ N ��������
//�ҳ������е����ֵ����Сֵ��������ֵ����Сֵ��
//�����ʽ:һ�������� N �������������� N ��������
//�����ʽ:��������е� ���ֵ��ȥ��Сֵ �Ľ��
#include<stdio.h>
int main() {
    int max, min, N, a, b, i;
    printf("����һ�������� N������������ N ��������\n");
    scanf("%d", &N);
    scanf("%d", &a);
    for (i=1;i<N;i++){
        scanf("%d", &b);
        while (i == 1) {                    //�ж����ȵ�������
            if (a >= b) {                   
                max = a, min = b;
            }
            else max = b, min = a;
            break;
        }
        if (b >= max) max = b;              //���αȽ�
        if (b <= min) min = b;
    }
    printf("MAX - MIN = %d", max - min);
    return 0;
}
