//1.内联函数练习
//将同一个函数定义为内联函数和非内联函数，统计二者之间的时间消耗差异。
//提示：用windows.h中的GetTickCount() 函数获得当前时刻的秒数。
//2.默认参数
//判断两个圆之间的关系，（包含，相离和相切），将其中求两个圆心之间距离的函数，定义为带默认值的参数。
//3.引用数据类型
//用引用形参，实现两个数的交换
//用返回为引用函数，获得与局部变量同名的全局变量


#include<iostream>
#include<Windows.h>
#include<cmath>

using namespace std;

class Circle {
private:
	float r;
	float x, y;
public:
	void init_circle(float r, float x, float y) {
		this->r = r;
		this->x = x;
		this->y = y;
	}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}	
	float getR() {
		return r;
	}
	float dis(Circle c) {
		float xdis = fabs(this->x - c.x);
		float ydis = fabs(this->y - c.y);
		return sqrt(pow(xdis, 2) + pow(ydis, 2));
	}
	int judgeRelation(Circle c) {
		if (dis(c) > (this->getR() + c.getR())) {
			return 1;
		}
		if (dis(c) == (this->getR() + c.getR())) {
			return 2;
		}
		if (dis(c) < (this->getR() + c.getR())) {
			return 3;
		}
	}
};

void inline_time();
inline int add1(int, int);
int add2(int, int);
void judge_circle();
void swap_nums();
void swap1(int&, int&);


int main() {
	inline_time();
	judge_circle();
	swap_nums();

	
	system("pause");
	return 0;
}

void inline_time() {
	int x = 1, y = 2, t = 0, z = 0;
	unsigned long start_time = GetTickCount();
	for (t = 0; t < 1000000; t++) {
		z = add1(x, y);
	}
	unsigned long end_time = GetTickCount();
	cout << "1.内联函数用时：" << end_time - start_time << '\t';
	start_time = GetTickCount();
	for (t = 0; t < 1000000; t++) {
		z = add2(x, y);
	}
	end_time = GetTickCount();
	cout << "非内联函数用时：" << end_time - start_time << endl;
}

inline int add1(int x, int y) {
	return x + y;
}

int add2(int x, int y) {
	return x + y;
}
void judge_circle() {
	Circle c1, c2;
	c1.init_circle(2.5, 0, 0);
	c2.init_circle(2.5, 3, 4);
	cout << endl << "2.";
	if (c1.judgeRelation(c2) == 1) {
		cout << "相离" << endl;
	}
	if (c1.judgeRelation(c2) == 2) {
		cout << "相切" << endl;
	}
	if (c1.judgeRelation(c2) == 3) {
		cout << "相交" << endl;
	}
}

void swap_nums() {
	int a = 1, b = 2;
	cout << endl << "3.";
	cout << "交换前：a=" << a << "，b=" << b << endl;
	swap1(a, b);
	cout << "交换后：a=" << a << "，b=" << b << endl;
}

void swap1(int& m, int& n) {//用引用形参，实现两个数的交换
	m = m ^ n;
	n = m ^ n;
	m = m ^ n;
}