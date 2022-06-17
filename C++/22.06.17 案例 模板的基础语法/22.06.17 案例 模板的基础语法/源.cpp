#include <iostream>
using namespace std;

//利用模板提供通用的交换函数
template <typename T>

void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 3, b = 4;
	double c = 1.1, d = 2.2;
	//方法1：自动类型推导
	mySwap(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;

	mySwap(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

	//方法2：指定类型
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