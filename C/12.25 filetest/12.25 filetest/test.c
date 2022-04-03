#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct stu {
	char name[20];
	int id;
	float score;
};

int main() {
	FILE* pfile = NULL;
	int i = 1;
	//初始化结构体
	struct stu stu = { 0 };

	//while (i<=3) {
	//	printf("请输入学生姓名：");
	//	scanf("%s", &stu.name);
	//	printf("请输入学生学号：");
	//	scanf("%d", &stu.id);
	//	printf("请输入学生分数：");
	//	scanf("%f", &stu.score);
	//	//打开文件
	//	pfile = fopen("C:\\Users\\lenovo\\Desktop\\test.txt", "a");
	//	if (pfile == NULL) {
	//		perror("fopen");
	//		return 1;
	//	}
	//	//输入数据
	//	fprintf(pfile, "%s %d %f\n", stu.name, stu.id, stu.score);

	//	//关闭文件
	//	fclose(pfile);
	//	pfile = NULL;
	//	i++;
	//}

	while (i <= 3) {
		//打开文件
		pfile = fopen("C:\\Users\\lenovo\\Desktop\\test.txt", "r");
		if (pfile == NULL) {
			perror("text.txt");
			return 1;
		}
		//读取数据
		fscanf(pfile, "%s %d %f", &stu.name, &stu.id, &stu.score);
		fprintf(stdout, "学生姓名：%s\n学生学号：%d\n学生分数：%f\n", stu.name, stu.id, stu.score);
		//关闭文件
		fclose(pfile);
		pfile = NULL;
		i++;
	}



	return 0;
}