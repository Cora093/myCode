#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void printShape() {
	char c;
	int size;
	cout << "������Ҫ��ӡ���ַ���";
	cin >> c ;
	cout << "������Ҫ��ӡ�����δ�С����������";
	cin >> size;
	//�ж��Ƿ�Ϸ�
	if (size % 2 == 0) {
		size++;
	}
	int spacenum = size / 2, charnum = 1;
	//�ϰ�
	for (; charnum < size; charnum += 2, spacenum--) {
		for (int i = 0; i < spacenum; i++) {
			cout << " ";
		}
		for (int i = 0; i < charnum; i++) {
			cout << c;
		}
		cout << endl;
	}
	//�м�
	for (int i = 0; i < size; i++) {
		cout << c;
	}
	cout << endl;
	//�°�
	spacenum = 1;
	charnum = size - 2;
	for (; charnum > 0; charnum -= 2, spacenum++) {
		for (int i = 0; i < spacenum; i++) {
			cout << " ";
		}
		for (int i = 0; i < charnum; i++) {
			cout << c;
		}
		cout << endl;
	}
	system("pause");
}


void print99mul() {
	int i, j;
	for (i = 1; i <= 9; i++){
		for (j = 1; j <= 9; j++){
			while (j < i){
				cout << "\t";
				j++;
			}
			cout << i << "*" << j << "=" << i * j << "\t";
		}
		cout << endl;
	}
	system("pause");
}

void buyChicken() {
	int i, j, k;
	cout << "��Ԫ��ټ����������п��ܵĽ����£�" << endl;
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			for (k = 0; k <= 100; k++) {
				if (5 * i + 3 * j + k / 3 == 100 && k % 3 == 0 && i + j + k == 100) {
					cout << "����" << i << "ֻ��ĸ��" << j << "ֻ��С��" << k << "ֻ" << endl;
				}
			}
		}
	}
	system("pause");
}

void guessNumber() {
	srand((unsigned)time(NULL));
	int num = rand() % 100 + 1;//����һ��1-100�������
	int input = 0;
	int count = 10;
	cout << "���һ��1-100֮�������" << endl;
	while (1) {
		cin >> input;
		//�ж�
		if (input > num) {
			cout << "����,";
		}
		else if (input < num) {
			cout << "С��,";
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
}

int main() {
	int input = 0;
	while (1) {
		cout << "��ѡ��:" << endl;
		cout << "1.��ӡ����" << endl;
		cout << "2.��ӡ99�˷���" << endl;
		cout << "3.��Ǯ�ټ�����" << endl;
		cout << "4.������" << endl;
		cout << "0.�˳�" << endl;
		cout << "������>>";
		cin >> input;
		switch (input){
		case 1:printShape();
			break;
		case 2:print99mul();
			break;
		case 3:buyChicken();
			break;
		case 4:guessNumber();
			break;
		case 0:goto exit;
			break;
		default:cout << "�������" << endl;
			break;
		}

	}
exit:
	cout << "�˳�" << endl;
	return 0;
}

