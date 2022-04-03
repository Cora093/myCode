#define _CRT_SECURE_NO_WARNINGS 1
//函数 fun 的功能是：从m个学生的成绩中统计出高于和等于平均分的学生人数，
//此人数由函数值返回。平均分通过形参传回，输入学生成绩时， 用 - 1结束输入，由程序自动统计学生人数。

#include <stdio.h>
int fun(float* s, int n, float* aver);
int main()
{
	float a, s[30], aver;
	int m = 0, i;
	scanf("%f", &a);
	while (a > 0) { s[m] = a; m++; scanf("%f", &a); }
	printf("The number of students : %d\n", fun(s, m, &aver));
	printf("ave=%.2f\n", aver);
	return 0;
}
/* 请在这里填写答案 */
int fun(float* s, int n, float* aver) {
	int i = 0, count = 0;
	float sum = 0;
	for (i = 0; i < n; i++) {
		sum += *(s + i);
	}
	*aver = sum / (float)n;
	for (i = 0; i < n; i++) {
		if (*(s + i) >= *aver) {
			count++;
		}
	}
	return count;
}
