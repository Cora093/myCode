#define _CRT_SECURE_NO_WARNINGS 1

//����N��ѧ���Ļ�����Ϣ������ѧ�ţ���5��������ɵ��ַ�����
//����������С��10�Ĳ������հ��ַ��ķǿ��ַ�������3�ſγ̵ĳɼ���[0, 100]�����ڵ�������
//������һ���и���������N����10�����N�У�ÿ�и���һλѧ������Ϣ����ʽΪ��ѧ�� ���� �ɼ�1 �ɼ�2 �ɼ�3��
//��һ��������ܷ����ѧ����������ѧ�ź��ܷ֣����һ���ո���Ŀ��֤������ѧ����Ψһ�ġ�

#include <stdio.h>

struct students {
	char num[6];
	char name[11];
	int score1;
	int score2;
	int score3;
}stu[10] = { 0 };

int main() {
	int n = 0;
	int i = 0;
	int max_score = 0;
	int max_num = 0;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//����
		scanf("%s", &stu[i].num);
		scanf("%s", &stu[i].name);
		scanf("%d", &stu[i].score1);
		scanf("%d", &stu[i].score2);
		scanf("%d", &stu[i].score3);
		sum = stu[i].score1 + stu[i].score2 + stu[i].score3;
		if (sum > max_score) {
			max_score = sum;
			max_num = i;
		}
	}
	printf("%s ", stu[max_num].name);
	printf("%s ", stu[max_num].num);
	printf("%d", max_score);

	return 0;
}