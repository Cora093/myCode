#include <iostream>
using namespace std;

//����ģ���ṩͨ�õĽ�������
template <typename T>

void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 3, b = 4;
	double c = 1.1, d = 2.2;
	//����1���Զ������Ƶ�
	mySwap(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;

	mySwap(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

	//����2��ָ������
	mySwap<int>(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;


	mySwap<double>(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

}


int main() {
	test01();

	system("pause");
	return 0;
}