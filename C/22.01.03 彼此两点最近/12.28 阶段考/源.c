#define _CRT_SECURE_NO_WARNINGS 1

//Description:
//给定一些平面上的点，求出彼此距离最近的两点。
//Input :
//输入数据中含有一些数据组（数量≤100），每组数据由一个整数n（2≤n≤102）领衔，
//后跟n个平面坐标点x、y（ - 10000≤整数x，y≤10000）。若n＝0则表示输入结束。
//Output :
//每组数据都有彼此距离最短的坐标点，输出所有彼此距离最短的两点x和y坐标
//坐标应以x的大小和y的大小依次输出, 用括号将其括起来，坐标点之间空一格，
//若有多对最短距离点，则换行输出, 坐标点小的在前, 大的在后。每组数据的结果之间空一行。

#include <stdio.h>
#include <math.h>

int power(int a, int b) {
	int count = 0;
	for (count = 0; count < b; count++) {
		a *= a;
	}
	return a ;
}

//计算距离的平方
int dist2(int ax, int ay, int bx, int by) {
	return power((ax - bx), 2) + power((ay - by), 2);
}

void fun(int n) {
	int i = 0, j = 0;
	int dist[99] = { 0 };//距离的平方
	int coord[10][2] = { 0 };//坐标
	int max = 0;//最大距离
	int maxcoord[2][2] = { 0 };
	for (i = 0; i < n; i++) {//输入坐标
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