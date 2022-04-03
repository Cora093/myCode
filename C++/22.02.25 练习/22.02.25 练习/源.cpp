#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void printShape() {
	char c;
	int size;
	cout << "请输入要打印的字符：";
	cin >> c ;
	cout << "请输入要打印的菱形大小（奇数）：";
	cin >> size;
	//判断是否合法
	if (size % 2 == 0) {
		size++;
	}
	int spacenum = size / 2, charnum = 1;
	//上半
	for (; charnum < size; charnum += 2, spacenum--) {
		for (int i = 0; i < spacenum; i++) {
			cout << " ";
		}
		for (int i = 0; i < charnum; i++) {
			cout << c;
		}
		cout << endl;
	}
	//中间
	for (int i = 0; i < size; i++) {
		cout << c;
	}
	cout << endl;
	//下半
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
	cout << "百元买百鸡的问题所有可能的解如下：" << endl;
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			for (k = 0; k <= 100; k++) {
				if (5 * i + 3 * j + k / 3 == 100 && k % 3 == 0 && i + j + k == 100) {
					cout << "公鸡" << i << "只，母鸡" << j << "只，小鸡" << k << "只" << endl;
				}
			}
		}
	}
	system("pause");
}

void guessNumber() {
	srand((unsigned)time(NULL));
	int num = rand() % 100 + 1;//生成一个1-100的随机数
	int input = 0;
	int count = 10;
	cout << "请猜一个1-100之间的数字" << endl;
	while (1) {
		cin >> input;
		//判断
		if (input > num) {
			cout << "大了,";
		}
		else if (input < num) {
			cout << "小了,";
		}
		else {
			cout << "恭喜!猜对了!" << endl;
			break;
		}
		count--;
		if (count > 0) {
			cout << "还有" << count << "次机会" << endl;
		}
		else {
			cout << "游戏失败" << endl;
			break;
		}
	}
	system("pause");
}

int main() {
	int input = 0;
	while (1) {
		cout << "请选择:" << endl;
		cout << "1.打印菱形" << endl;
		cout << "2.打印99乘法表" << endl;
		cout << "3.百钱百鸡问题" << endl;
		cout << "4.猜数字" << endl;
		cout << "0.退出" << endl;
		cout << "请输入>>";
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
		default:cout << "输入错误" << endl;
			break;
		}

	}
exit:
	cout << "退出" << endl;
	return 0;
}

