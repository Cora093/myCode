#define _CRT_SECURE_NO_WARNINGS 1

//����һ�仰 �������
//eg: good morning  jack  ->  jack good morning

#include <stdio.h>
#include <string.h>

int main() {
	char str[10000] = { 0 };
	gets(str);//����
	char* pc[1000] = { NULL };//ָ������
	pc[0] = str;//�׵��ʵı��ָ��
	int i = 1, j = 1;//i�����ַ����ļ�����j����ָ������ļ���
	char* tmp = NULL;
	while (str[i] != '\0') {
		if (str[i - 1] == ' ' && str[i] != ' ') {//�ҵ�ÿ�����ʵ�����ĸ
			pc[j] = &str[i];//��ÿ�����ʵ�����ĸ��ַ��¼��ָ������
			j++;
		}
		i++;
	}
	for (j -= 1; j >= 0; j--) {//�������
		tmp = pc[j];
		while (*tmp != '\0' && *tmp != ' ') {//��ͨ����������ַ�Ϊֹ�����һ�������'\0'Ϊֹ
			printf("%c", *tmp);//����ַ�
			tmp++;
		}
		printf(" ");//�����м���Ͽո�
	}
	return 0;
}