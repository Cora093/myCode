#define _CRT_SECURE_NO_WARNINGS 1
//���ܹ��м�������ͬ���ַ�����������ĸ�Ĵ�Сд����
//ÿ�����԰����������������
//��һ�а���һ��������T(1��T��10), ��ʾ���������������������������������¡�
//�ڶ��а���һ������N(1��N��1000), ��ʾ��N���ַ����������N�У�ÿ��һ���ַ���, ��֤�ַ�������С��100
//����ÿ�������������������ͬ���ַ�������(��β�л���)

#include <stdio.h>
#include <string.h>

int main(){
	void stringlwr(char* a);
	int i, j, p, q, m, n;
	int k = 1;						
	char s[100], s1[100], t[100];
	scanf("%d", &i);					
	for (j = 0; j < i; j++){					//��������������		
		k = 1;
		scanf("%d\n", &p);	
		//getchar();
		gets(s);
		//for (m = 0; ; m++){					//�����һ���ַ���
		//	if (s[m] == '\n') break;
		//	scanf("%c", &s[m]);
		//}
		stringlwr(s);
		for (q = 2, k = 1; q <= p; q++){		//�����2-n���ַ������αȽ�
			gets(s1);
			//for (m = 0; ; m++){
			//	scanf("%c", &s1[m]);
			//	if (s1[m] == '\n') break;
			//}
			stringlwr(s1);
			//strlwr(s1);
			if (strcmp(s, s1) != 0) {
				k++;
			}
		}
		t[j] = k;
	}
	for (j = 0; j < i; j++) {
		printf("%d", t[j]);
		if (j == i - 1) break;
		printf("\n");
	}
	return 0;
}

void stringlwr(char* a) {
	int i;
	int length = sizeof(a) / sizeof(a[0]) - 1;				//���ַ������ȡ��������
	for (i = 0; i < length; i++) {
		if ('A' <= a[i] && 'Z' >= a[i]) {
			a[i] += 32;
		}
	}
}
