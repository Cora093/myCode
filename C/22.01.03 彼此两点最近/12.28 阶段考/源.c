#define _CRT_SECURE_NO_WARNINGS 1

//Description:
//����һЩƽ���ϵĵ㣬����˴˾�����������㡣
//Input :
//���������к���һЩ�����飨������100����ÿ��������һ������n��2��n��102�����Σ�
//���n��ƽ�������x��y�� - 10000������x��y��10000������n��0���ʾ���������
//Output :
//ÿ�����ݶ��б˴˾�����̵�����㣬������б˴˾�����̵�����x��y����
//����Ӧ��x�Ĵ�С��y�Ĵ�С�������, �����Ž����������������֮���һ��
//���ж����̾���㣬�������, �����С����ǰ, ����ں�ÿ�����ݵĽ��֮���һ�С�

#include <stdio.h>
#include <math.h>

int power(int a, int b) {
	int count = 0;
	for (count = 0; count < b; count++) {
		a *= a;
	}
	return a ;
}

//��������ƽ��
int dist2(int ax, int ay, int bx, int by) {
	return power((ax - bx), 2) + power((ay - by), 2);
}

void fun(int n) {
	int i = 0, j = 0;
	int dist[99] = { 0 };//�����ƽ��
	int coord[10][2] = { 0 };//����
	int max = 0;//������
	int maxcoord[2][2] = { 0 };
	for (i = 0; i < n; i++) {//��������
		scanf("%d %d", &coord[i][0], &coord[i][1]);
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
			if (max < dist2(coord[i][0],coord[i][1],coord[j][0],coord[j][1])) {
				max = dist2(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
				maxcoord[0][0] = coord[i][0];
				maxcoord[0][1] = coord[i][1];
				maxcoord[1][0] = coord[j][0];
				maxcoord[1][1] = coord[j][1];
			}
	}
	printf("(%d,%d) (%d,%d)\n", maxcoord[0][0], maxcoord[0][1], maxcoord[1][0], maxcoord[1][1]);
}

int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else {
			fun(n);
		}
	}
	return 0;
}