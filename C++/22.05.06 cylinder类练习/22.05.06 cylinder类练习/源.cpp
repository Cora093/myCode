//������cylinder, cylinder �Ĺ��캯��������������doubleֵ,�ֱ��ʾԲ����İ뾶�͸߶ȡ�
//����cylinder����Բ��������,���洢��һ�� double�����С�
//����cylinder �а���һ����Ա���� vol,������ʾÿ��cylinder����������
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
	void vol() {//��ʾ���
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