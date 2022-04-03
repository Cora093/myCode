//建立类cylinder，cylinder的构造函数被传递了两个double值，分别表示圆柱体的半径和高度。
//用类cylinder计算圆柱体的体积，并存储在一个double变量中。
//在类cylinder中包含一个成员函数vol，用来显示每个cylinder对象的体积。

#include<iostream>
using namespace std;

class Cylinder {
private:
	double r, h, v;
	double pi;
public:
	Cylinder(double r1, double h1) :r(r1), h(h1), pi(3.14) {}//构造函数
	void calcuV() {//计算体积
		this->v = pi * this->r * this->r * this->h;
	}
	void showVol() {
		cout << this->v << endl;
	}
};

int main() {
	Cylinder A(1, 1);
	A.calcuV();
	A.showVol();
	return 0;
}