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
	//��ʼ���ṹ��
	struct stu stu = { 0 };

	//while (i<=3) {
	//	printf("������ѧ��������");
	//	scanf("%s", &stu.name);
	//	printf("������ѧ��ѧ�ţ�");
	//	scanf("%d", &stu.id);
	//	printf("������ѧ��������");
	//	scanf("%f", &stu.score);
	//	//���ļ�
	//	pfile = fopen("C:\\Users\\lenovo\\Desktop\\test.txt", "a");
	//	if (pfile == NULL) {
	//		perror("fopen");
	//		return 1;
	//	}
	//	//��������
	//	fprintf(pfile, "%s %d %f\n", stu.name, stu.id, stu.score);

	//	//�ر��ļ�
	//	fclose(pfile);
	//	pfile = NULL;
	//	i++;
	//}

	while (i <= 3) {
		//���ļ�
		pfile = fopen("C:\\Users\\lenovo\\Desktop\\test.txt", "r");
		if (pfile == NULL) {
			perror("text.txt");
			return 1;
		}
		//��ȡ����
		fscanf(pfile, "%s %d %f", &stu.name, &stu.id, &stu.score);
		fprintf(stdout, "ѧ��������%s\nѧ��ѧ�ţ�%d\nѧ��������%f\n", stu.name, stu.id, stu.score);
		//�ر��ļ�
		fclose(pfile);
		pfile = NULL;
		i++;
	}



	return 0;
}