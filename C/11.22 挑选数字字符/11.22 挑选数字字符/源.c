#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ַ�����ÿ���ַ�������ĸ��������ɣ�������ѡ������͡�
//����һ�������ֺ���ĸ��ɵ��ַ����������ո�
//�������ַ�ѡ����ת�����������
//eg:a1b2c3d4e5f--15
#include<stdio.h>
#include<string.h>
int main()
{
	int i, sum = 0, length;
	char s[50];
	gets(s);
	length = strlen(s);
	for (i = 0; i <= length - 1; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)		//ASCII����0-9��Ӧ48-57
		{
			sum += s[i] - 48;				//ת��ʱ-48
		}
	}
	printf("%d", sum);
	return 0;
}