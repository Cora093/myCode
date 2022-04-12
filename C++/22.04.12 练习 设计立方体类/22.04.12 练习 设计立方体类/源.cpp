//设计立方体类(Cube)
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等

#include<iostream>
using namespace std;

class Cube {
public:
	//设置长
	void setL(int l) {
		m_L = l;
	}
	//获取长
	int getL() {
		return m_L;
	}
	//设置宽
	void setW(int w) {
		m_W = w;
	}
	//获取宽
	int getW() {
		return m_W;
	}
	//设置高
	void setH(int h) {
		m_H = h;
	}
	//获取高
	int getH() {
		return m_H;
	}
	//获取立方体面积
	int calcuS() {
		return 2 * (m_H * m_L + m_H * m_W + m_L * m_W);
	}
	//获取立方体体积
	int calcuV() {
		return m_H * m_L * m_W;
	}
	//成员函数判断两个立方体是否相等
	bool isSameByClass(Cube &c) {
		return (m_H == c.getH() && m_L == c.getL() && m_W == c.getW()) ? true : false;
	}
private:
	int m_L;//立方体的长
	int m_W;//立方体的宽
	int m_H;//立方体的高

};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1,Cube &c2) {
	return (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW()) ? true : false;
}

int main() {
	Cube C1;
	C1.setH(10);
	C1.setW(10);
	C1.setL(10);
	cout << "C1的面积为:" << C1.calcuS() << endl;
	cout << "C1的体积为:" << C1.calcuV() << endl;
	Cube C2;
	C2.setH(10);
	C2.setW(10);
	C2.setL(10);
	cout << "全局函数判断的结果：";
	isSame(C1, C2) ? (cout << "两立方体相等") : (cout << "两立方体不相等");
	cout << endl;
	cout << "成员函数判断的结果：";
	C1.isSameByClass(C2) ? (cout << "两立方体相等") : (cout << "两立方体不相等");
	cout << endl;
	system("pause");
	return 0;
}