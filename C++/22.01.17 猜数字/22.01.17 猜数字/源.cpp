#define _CRT_SECURE_NO_WARNINGS 1


//������
//���������->�û��²�->�ж�

//���²����
#define guess_time 10

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//��ջ�����
void clean() {
	int ch = 0;
	while ((ch = getchar()) != EOF && ch != '\n');
}

int main() {
	//��ʼ���������
	srand((unsigned)time(NULL));
	//���������
	int num = rand() % 100 + 1;//����һ��1-100���������α�����
	int input = 0;
	int count = guess_time;
	cout << "���һ��1-100֮�������" << endl;

	while (1) {
		clean();
		//��Ҳ²�
		cin >> input;
		//�ж�
		if (input > num) {
			cout << "����,"  ;
		}
		else if (input < num) {
			cout << "С��," ;
		}
		else {
			cout << "��ϲ!�¶���!" << endl;
			break;
		}
		count--;
		if (count > 0) {
			cout << "����" << count << "�λ���" << endl;
		}
		else {
			cout << "��Ϸʧ��" << endl;
			break;
		}
	}


	system("pause");
	return 0;
}