#define _CRT_SECURE_NO_WARNINGS 1

//����N��ѧ���Ļ�����Ϣ������ѧ�ţ���5��������ɵ��ַ�����������������С��10�Ĳ������հ��ַ��ķǿ��ַ�����
//�ͳɼ���[0, 100]�����ڵ���������Ҫ��������ǵ�ƽ���ɼ�����˳�����ƽ�������µ�ѧ��������
//������һ���и���������N����10�������N�У�ÿ�и���һλѧ������Ϣ����ʽΪ��ѧ�� ���� �ɼ������м��Կո�ָ���
//������һ�������ƽ���ɼ�������2λС����Ȼ��������˳��ÿ�����һλƽ�������µ�ѧ����������ѧ�ţ����һ���ո�

#include <stdio.h>

struct stu {
	char num[6];
	char name[11];
	int score;
}students[10] = { 0 };

int main() {
	int n = 0, i = 0;
	float sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", &students[i].num);
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].score);
		sum += students[i].score;
	}
	float aver = sum / n;
	printf("%.2f", aver);
	for (i = 0; i < n; i++) {
		if (students[i].score < aver) {
			printf("\n%s ", students[i].name);
			printf("%s", students[i].num);
		}
	}
	return 0;
}