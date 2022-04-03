#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <windows.h>
using namespace std;

const int min_5 = 1000 * 60 * 5;

int main() {
	int input = 0;
	system("pause");
	while (1) {
		cout << "输入1开始计时，输入0退出" << endl;
		cin >> input;
		if(input == 0){
			break;
		}
		cout << "开始计时" << endl;
		for (int i = 1; i <= 5; i++) {//计时开始
			Sleep(min_5);
			cout << i * 5 << endl;
		}
		for (int i = 1; i <= 3; i++) {//计时结束，提醒
			cout << '\a' << endl;
			Sleep(1000);
		}
		cout << "计时结束" << endl;
		system("pause");
		cout << "开始休息" << endl;
		Sleep(min_5);
		for (int i = 1; i <= 3; i++) {//休息结束，提醒
			cout << '\a' << endl;
			Sleep(1000);
		}
		cout << "休息结束" << endl;
		system("pause");
	}
	return 0;
}