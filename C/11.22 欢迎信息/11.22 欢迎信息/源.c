#define _CRT_SECURE_NO_WARNINGS 1
//输入在一行中给出1个字符串s（可能包含空格，长度不超过12），表示输入的姓名。
//根据输入的姓名（可能包含空格，长度不超过12），输出欢迎信息，即在姓名s之前添加“Hello, ”

#include<stdio.h>
#include<string.h>
int main()
{
	char name[12], hello[60] = "Hello,";
	gets(name);
	//scanf("%s", name);	scanf不能包含空格
	puts(strcat(hello, name));
	return 0;
}