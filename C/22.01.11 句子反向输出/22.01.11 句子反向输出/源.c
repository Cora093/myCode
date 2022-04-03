#define _CRT_SECURE_NO_WARNINGS 1

//输入一句话 反向输出
//eg: good morning  jack  ->  jack good morning

#include <stdio.h>
#include <string.h>

int main() {
	char str[10000] = { 0 };
	gets(str);//输入
	char* pc[1000] = { NULL };//指针数组
	pc[0] = str;//首单词的标记指针
	int i = 1, j = 1;//i用作字符串的计数，j用作指针数组的计数
	char* tmp = NULL;
	while (str[i] != '\0') {
		if (str[i - 1] == ' ' && str[i] != ' ') {//找到每个单词的首字母
			pc[j] = &str[i];//将每个单词的首字母地址记录在指针数组
			j++;
		}
		i++;
	}
	for (j -= 1; j >= 0; j--) {//逆向输出
		tmp = pc[j];
		while (*tmp != '\0' && *tmp != ' ') {//普通单词输出到字符为止，最后一词输出到'\0'为止
			printf("%c", *tmp);//输出字符
			tmp++;
		}
		printf(" ");//单词中间加上空格
	}
	return 0;
}