#include<iostream>
using namespace std;
#include<string>

struct Complex {
	float x, y;
	void init() { 
		cin >> this->x;
		cin >> this->y;
	}
	float abscomplex() {
		this->x = fabs(this->x);
		this->y = fabs(this->y);
	}
	Complex add(Complex c2) { 
		Complex sum;
		sum.x = this->x + c2.x;
		sum.y = this->y + c2.y;
		return sum;
	}
};
int main() {
	//定义结构变量1和2， 初始化这两个结构变量，输出它们的和，以及和的绝对值。
	Complex c1, c2;
	c1.init();
	c2.init();
	cout << c1.add(c2).x << "+" << c1.add(c2).y << endl;
}
