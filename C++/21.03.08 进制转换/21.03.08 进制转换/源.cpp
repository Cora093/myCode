//1. 编写程序，定义6个函数，分别将 十进制整数转成二进制，八进制和十六进制并返回
//以及把二进制，八进制和十六进制数值的字符序列转成十进制并返回。
//2. 将上述函数，封装成一个不带数据的类，创建该类对象，从键盘输入数据作为实参，对6个函数进行调用和输出结果显示。
//要求：要求把代码和运行结果，粘贴到 word文档中，文档命名为 1853101编程练习2_1.doc后提交到下面答案中。

#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

class Test {
public:
	void _10to2(int);
	void _10to8(int);
	void _10to16(int);
	void _2to10();
	void _8to10();
	void _16to10();
};

void Test::_10to2(int n) {
	cout << "十进制：" << n << ' ' << "二进制：";
	int a[50] = { 0 };
	int t = 0;
	while (n > 1) {
		a[t] = n % 2;
		n /= 2;
		t++;
	}
	a[t] = 1;
	for (; t >= 0; t--) {
		cout << a[t];
	}
	cout << endl;
}

void Test::_10to8(int n) {
	cout << "十进制：" << n << ' ' << "八进制：" << oct << n << endl << dec;
}

void Test::_10to16(int n) {
	cout << "十进制：" << n << ' ' << "十六进制：" << hex << n << endl << dec;
	cout << endl;
}

void Test::_2to10() {
	int n = 0;
	cout << "请输入二进制数：";
	cin >> n;
	cout << "二进制：" << n << ' ' << "十进制：";
	int t = 0, sum = 0;
	while (n > 0) {
		sum += n % 10 * (int)pow(2, t);
		n /= 10;
		t++;
	}
	cout << sum << endl;
	cout << endl;

}

void Test::_8to10() {
	int n = 0;
	cout << "请输入八进制数：";
	cin >> n;
	cout << "八进制：" << n << ' ' << "十进制：";
	int t = 0, sum = 0;
	while (n > 0) {
		sum += n % 10 * (int)pow(8, t);
		n /= 10;
		t++;
	}
	cout << sum << endl;
	cout << endl;

}

void Test::_16to10() {
	char a[20] = { 0 };
	cout << "请输入十六进制数：";
	cin >> a;
	cout << "八进制：" << a << ' ' << "十进制：";
	int n = 0, sum = 0, len = strlen(a) - 1;
	int tmp = 0;
	for (int t = 0; t < strlen(a); t++,len--) {
		if (a[t] >= 'A' && a[t] <= 'F') {
			tmp = a[t] - 'A' + 10;
		}
		if (a[t] >= 'a' && a[t] <= 'f') {
			tmp = a[t] - 'a' + 10;
		}
		sum += tmp * (int)pow(16, len);
	}
	cout << sum << endl;
	cout << endl;
}

int main() {
	Test a;
	int n = 0;
	cout << "请输入十进制数：";
	cin >> n;
	a._10to2(n);
	a._10to8(n);
	a._10to16(n);
	a._2to10();
	a._8to10();
	a._16to10();
	system("pause");
	return 0;
}