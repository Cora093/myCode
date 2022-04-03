#define _CRT_SECURE_NO_WARNINGS 1

//给定N个学生的基本信息，包括学号（由5个数字组成的字符串）
//姓名（长度小于10的不包含空白字符的非空字符串）和3门课程的成绩（[0, 100]区间内的整数）
//输入在一行中给出正整数N（≤10）随后N行，每行给出一位学生的信息，格式为“学号 姓名 成绩1 成绩2 成绩3”
//在一行中输出总分最高学生的姓名、学号和总分，间隔一个空格。题目保证这样的学生是唯一的。

#include <stdio.h>

struct students {
	char num[6];
	char name[11];
	int score1;
	int score2;
	int score3;
}stu[10] = { 0 };

int main() {
	int n = 0;
	int i = 0;
	int max_score = 0;
	int max_num = 0;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//输入
		scanf("%s", &stu[i].num);
		scanf("%s", &stu[i].name);
		scanf("%d", &stu[i].score1);
		scanf("%d", &stu[i].score2);
		scanf("%d", &stu[i].score3);
		sum = stu[i].score1 + stu[i].score2 + stu[i].score3;
		if (sum > max_score) {
			max_score = sum;
			max_num = i;
		}
	}
	printf("%s ", stu[max_num].name);
	printf("%s ", stu[max_num].num);
	printf("%d", max_score);

	return 0;
}