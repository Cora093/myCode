#define _CRT_SECURE_NO_WARNINGS 1

//给定N个学生的基本信息，包括学号（由5个数字组成的字符串）、姓名（长度小于10的不包含空白字符的非空字符串）
//和成绩（[0, 100]区间内的整数），要求计算他们的平均成绩，并顺序输出平均线以下的学生名单。
//输入在一行中给出正整数N（≤10）。随后N行，每行给出一位学生的信息，格式为“学号 姓名 成绩”，中间以空格分隔。
//首先在一行中输出平均成绩，保留2位小数。然后按照输入顺序，每行输出一位平均线以下的学生的姓名和学号，间隔一个空格。

#include <stdio.h>

struct stu {
	char num[6];
	char name[11];
	int score;
}students[10] = { 0 };

int main() {
	int n = 0, i = 0;
	float sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", &students[i].num);
		scanf("%s", &students[i].name);
		scanf("%d", &students[i].score);
		sum += students[i].score;
	}
	float aver = sum / n;
	printf("%.2f", aver);
	for (i = 0; i < n; i++) {
		if (students[i].score < aver) {
			printf("\n%s ", students[i].name);
			printf("%s", students[i].num);
		}
	}
	return 0;
}