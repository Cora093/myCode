#define _CRT_SECURE_NO_WARNINGS 1
//����һ�ַ���
//���ɾ�������ַ���ʣ�µ��ַ���ɵ��´�

#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, p = 0;
	char s[20], s1[20];
	//gets(s);
	scanf("%s", s);
	for (j = 0;; j++)
	{
		if (s[j] < 48 || s[j]>57)	//�����������
		{
			s1[p] = s[j];
			p++;
		}
		if (s[j] == '\0') break;
	}
	puts(s1);
	return 0;
}