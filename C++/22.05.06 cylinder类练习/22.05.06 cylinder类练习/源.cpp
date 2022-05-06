//建立类cylinder, cylinder 的构造函数被传递了两个double值,分别表示圆柱体的半径和高度。
//用类cylinder计算圆柱体的体积,并存储在一个 double变量中。
//在类cylinder 中包含一个成员函数 vol,用来显示每个cylinder对象的体积。
#include <iostream>
using namespace std;

class Cylinder {

public:
	Cylinder(double a,double b) {
		pi = 3.14;
		r = a;
		h = b;
		v = h * pi * r * r;
	}
	void vol() {//显示体积
		cout << this->v << endl;
	}

private:
	double r;
	double h;
	double v;
	double pi;
};


void test01() {
	Cylinder c(1, 1);
	c.vol();
}

int main() {
	test01();
	system("pause");
	return 0;
}