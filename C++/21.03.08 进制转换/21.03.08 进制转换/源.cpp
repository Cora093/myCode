//1. ��д���򣬶���6���������ֱ� ʮ��������ת�ɶ����ƣ��˽��ƺ�ʮ�����Ʋ�����
//�Լ��Ѷ����ƣ��˽��ƺ�ʮ��������ֵ���ַ�����ת��ʮ���Ʋ����ء�
//2. ��������������װ��һ���������ݵ��࣬����������󣬴Ӽ�������������Ϊʵ�Σ���6���������е��ú���������ʾ��
//Ҫ��Ҫ��Ѵ�������н����ճ���� word�ĵ��У��ĵ�����Ϊ 1853101�����ϰ2_1.doc���ύ��������С�

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
	cout << "ʮ���ƣ�" << n << ' ' << "�����ƣ�";
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
	cout << "ʮ���ƣ�" << n << ' ' << "�˽��ƣ�" << oct << n << endl << dec;
}

void Test::_10to16(int n) {
	cout << "ʮ���ƣ�" << n << ' ' << "ʮ�����ƣ�" << hex << n << endl << dec;
	cout << endl;
}

void Test::_2to10() {
	int n = 0;
	cout << "���������������";
	cin >> n;
	cout << "�����ƣ�" << n << ' ' << "ʮ���ƣ�";
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
	cout << "������˽�������";
	cin >> n;
	cout << "�˽��ƣ�" << n << ' ' << "ʮ���ƣ�";
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
	cout << "������ʮ����������";
	cin >> a;
	cout << "�˽��ƣ�" << a << ' ' << "ʮ���ƣ�";
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
	cout << "������ʮ��������";
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