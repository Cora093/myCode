#define _CRT_SECURE_NO_WARNINGS 1
//����Ҫ���д���򣬴�ӡһ���߶�Ϊn�ġ��ɡ�* ����ɵ�������ͼ����
//����һ����������n�������n���Ǻš�* ����ɵ�����ÿ���Ǻź��һ���ո�

#include <stdio.h>
#include <math.h>



int main() {
	void print(int num, int hang);
	int n = 0, i = 0;
	scanf("%d", &n);
	int hang = n;
	for (i = 1; i <= n; i++) {
		print(i,hang);
		if (i < n) {
			printf("\n");
		}
	}
	return 0;
}

void print(int num,int hang) {
	int i = 0, j = 0;
	while (i < abs(hang / 2 + 1 - num)) {
		printf("  ");
		i++;
	}
	i = 0;
	if (num <= hang / 2 + 1) {
		while (i < 2 * num - 1) {
			printf("* ");
			i++;
		}
		i = 0;
	}
	else {
		while (i < hang*2+1 - 2 * num) {
			printf("* ");
			i++;
		}
		i = 0;
	}
}