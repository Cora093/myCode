#include <iostream>
using namespace std;

//��������Ϊ�βν�������
void swap(char& c1, char& c2) {
	c1 = c1 ^ c2;
	c2 = c1 ^ c2;
	c1 = c1 ^ c2;
}

int main() {
	char a, b;
	cin >> a >> b;
	if (a < b) {
		swap(a, b);
	}
	cout << a << " " << b << endl;
	return 0;
}
