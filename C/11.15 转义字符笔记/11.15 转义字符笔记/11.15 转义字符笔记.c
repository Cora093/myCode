#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()                         //ת���ַ�
 {
    printf("abc\nabc\tabc");
    printf("\n");
    printf("c:\test\32\test.c");
    printf("\n");
    printf("c:\\test\\32\\test.c");             //  \\ ��ʾ��\��Ϊһ����ͨ�ַ�
    printf("\n");
    printf("%c", '\'');                         //  \' ��ʾ��'��Ϊһ����ͨ�ַ�
    printf("\n");
    printf("%c", '\"');                         //  ͬ��
    printf("\n");
    printf("%s", "abc");                        //  printf("%s"��)��ӡ�ַ���
    printf("\n");
    printf("%c\n%c\n%c\n", '\132', 90, 'Z');    //  \132 ��ʾ132�İ˽�������--90
    printf("%c\n", 'Z');                        //  ת��ΪASCII����Z
    printf("%c\n%c\n%c\n", '\x61',97,'a');      //  \x61 ͬ����ʾ61��16��������--97--a
    printf("123\t321\n");                       //  \tΪtab(ˮƽ�Ʊ������\nΪ����
    return 0;
}