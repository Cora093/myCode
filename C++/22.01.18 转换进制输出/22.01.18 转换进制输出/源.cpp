#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

int main() {
	int x = 25;
	cout << hex << x << endl;//转换为十六进制
	cout << dec << x << endl;//转换为十进制
	cout << oct << x << endl;//转换为八进制
	system("pause");
	return 0;
}