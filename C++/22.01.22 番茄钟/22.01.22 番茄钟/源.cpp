#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <windows.h>
using namespace std;

const int min_5 = 1000 * 60 * 5;

int main() {
	int input = 0;
	system("pause");
	while (1) {
		cout << "����1��ʼ��ʱ������0�˳�" << endl;
		cin >> input;
		if(input == 0){
			break;
		}
		cout << "��ʼ��ʱ" << endl;
		for (int i = 1; i <= 5; i++) {//��ʱ��ʼ
			Sleep(min_5);
			cout << i * 5 << endl;
		}
		for (int i = 1; i <= 3; i++) {//��ʱ����������
			cout << '\a' << endl;
			Sleep(1000);
		}
		cout << "��ʱ����" << endl;
		system("pause");
		cout << "��ʼ��Ϣ" << endl;
		Sleep(min_5);
		for (int i = 1; i <= 3; i++) {//��Ϣ����������
			cout << '\a' << endl;
			Sleep(1000);
		}
		cout << "��Ϣ����" << endl;
		system("pause");
	}
	return 0;
}