#define _CRT_SECURE_NO_WARNINGS 1

//��ʹ��ָ��ķ�����д����
//����Ĺ����ǴӼ�������һ���ַ���(�ַ�������С��100)��ɾ�����е���ĸa�������
//���磬�����ַ���abcaca�����bcc��

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