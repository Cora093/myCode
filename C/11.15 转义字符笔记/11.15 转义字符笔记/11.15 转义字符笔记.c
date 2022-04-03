#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()                         //转义字符
 {
    printf("abc\nabc\tabc");
    printf("\n");
    printf("c:\test\32\test.c");
    printf("\n");
    printf("c:\\test\\32\\test.c");             //  \\ 表示将\变为一个普通字符
    printf("\n");
    printf("%c", '\'');                         //  \' 表示将'变为一个普通字符
    printf("\n");
    printf("%c", '\"');                         //  同理
    printf("\n");
    printf("%s", "abc");                        //  printf("%s"，)打印字符串
    printf("\n");
    printf("%c\n%c\n%c\n", '\132', 90, 'Z');    //  \132 表示132的八进制数字--90
    printf("%c\n", 'Z');                        //  转换为ASCII码是Z
    printf("%c\n%c\n%c\n", '\x61',97,'a');      //  \x61 同理，表示61的16进制数字--97--a
    printf("123\t321\n");                       //  \t为tab(水平制表符），\n为换行
    return 0;
}