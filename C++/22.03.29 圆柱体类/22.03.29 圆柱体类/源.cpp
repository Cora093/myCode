//������cylinder��cylinder�Ĺ��캯��������������doubleֵ���ֱ��ʾԲ����İ뾶�͸߶ȡ�
//����cylinder����Բ�������������洢��һ��double�����С�
//����cylinder�а���һ����Ա����vol��������ʾÿ��cylinder����������

#include<iostream>
using namespace std;

class Cylinder {
private:
	double r, h, v;
	double pi;
public:
	Cylinder(double r1, double h1) :r(r1), h(h1), pi(3.14) {}//���캯��
	void calcuV() {//�������
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