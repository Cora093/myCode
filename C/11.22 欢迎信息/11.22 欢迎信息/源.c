#define _CRT_SECURE_NO_WARNINGS 1
//������һ���и���1���ַ���s�����ܰ����ո񣬳��Ȳ�����12������ʾ�����������
//������������������ܰ����ո񣬳��Ȳ�����12���������ӭ��Ϣ����������s֮ǰ��ӡ�Hello, ��

#include<stdio.h>
#include<string.h>
int main()
{
	char name[12], hello[60] = "Hello,";
	gets(name);
	//scanf("%s", name);	scanf���ܰ����ո�
	puts(strcat(hello, name));
	return 0;
}