#define _CRT_SECURE_NO_WARNINGS 1
//��һ����Ǯ����5�֡�2�ֺ�1�ֵ�Ӳ�ң�Ҫ��ÿ��Ӳ��������һö���м��ֲ�ͬ�Ļ�����
//������һ���и�����������Ǯ����x��(8, 100)��
//ÿ�����һ�ֻ�������ʽΪ����fen5:5��Ӳ������, fen2:2��Ӳ������,fen1:1��Ӳ������,total:Ӳ����������
//���һ�������count = ������������

#include <stdio.h>

void coin(int money) {
	int count = 0;
	int i = 0, j = 0, k = 0;
	money -= 8;												//�����521����
	for (i = money / 5; i >= 0; i--) {						//��ֵ�����
		for (j = (money - i * 5) / 2; j >= 0; j--) {		//���ֵ�����
			k = money - 5 * i - 2 * j;						//һ�ֵ�����
			printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i + 1, j + 1, k + 1, i + j + k + 3);
			count++;
		}
	}
	printf("count = %d", count);
}

int main() {
	void coin(int);
	int money = 0;
	scanf("%d", &money);
	coin(money);
	return 0;
}
