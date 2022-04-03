#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

inline int doub(int num) {
	return num * 2;
}

int main() {
	inline int doub(int);
	for (int i = 1; i <= 3; i++) {
		cout << doub(i) << endl;
	}
	system("pause");
	return 0;
}