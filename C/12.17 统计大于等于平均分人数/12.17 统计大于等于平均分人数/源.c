#define _CRT_SECURE_NO_WARNINGS 1
//���� fun �Ĺ����ǣ���m��ѧ���ĳɼ���ͳ�Ƴ����ں͵���ƽ���ֵ�ѧ��������
//�������ɺ���ֵ���ء�ƽ����ͨ���βδ��أ�����ѧ���ɼ�ʱ�� �� - 1�������룬�ɳ����Զ�ͳ��ѧ��������

#include <stdio.h>
int fun(float* s, int n, float* aver);
int main()
{
	float a, s[30], aver;
	int m = 0, i;
	scanf("%f", &a);
	while (a > 0) { s[m] = a; m++; scanf("%f", &a); }
	printf("The number of students : %d\n", fun(s, m, &aver));
	printf("ave=%.2f\n", aver);
	return 0;
}
/* ����������д�� */
int fun(float* s, int n, float* aver) {
	int i = 0, count = 0;
	float sum = 0;
	for (i = 0; i < n; i++) {
		sum += *(s + i);
	}
	*aver = sum / (float)n;
	for (i = 0; i < n; i++) {
		if (*(s + i) >= *aver) {
			count++;
		}
	}
	return count;
}
