#define _CRT_SECURE_NO_WARNINGS 1
//��������һ��������k��Ȼ����һ���ַ���s�����ܰ����ո񣬳��Ȳ�����20����
// k��s֮����һ���ո�ֿ�����k����0��С�ڵ���s�ĳ��ȣ�
//��һ��������ַ���s��ͷ��ʼ�ҳ���Ϊk���Ӵ���
//eg:10 welcome to acm world--welcome to

#include<stdio.h>
#include<string.h>
int main()
{
	int k, i;
	char s[21];
	scanf("%d", &k);
	for (i = 0; i <= k; i++)						//����ַ����
	{
		scanf("%c", &s[i]);
		if (s[i] == '\n') break;
	}
	for (i = 1; i <= k ; i++)
	{
		printf("%c", s[i]);
	}
	return 0;
}
