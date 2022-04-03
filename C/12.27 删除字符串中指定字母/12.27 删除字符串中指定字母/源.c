#define _CRT_SECURE_NO_WARNINGS 1

//请使用指针的方法编写程序
//程序的功能是从键盘输入一个字符串(字符串长度小于100)，删除其中的字母a后输出。
//例如，输入字符串abcaca，输出bcc。

#include <stdio.h>

int main() {
	int i = 0, j = 0, flag = 0;
	char* p = NULL;
	char str[100] = { 0 };
	p = str;
	gets(str);
	for (i = 0;; i++) {
		if (*(p + i) == '\0') {
			break;
		}
		if (*(p + i) == 'a') {
			flag = i;
			j = i + 1;
			while (*(p + j) != '\0') {
				*(p + i) = *(p + j);
				i++;
				j++;
			}
			i = flag;
		}
	}
	for (i = 0;; i++) {
		if (*(p + i) == 'a') {
			*(p + i) = '\0';
			break;
		}
	}
	puts(str);
	return 0;
}