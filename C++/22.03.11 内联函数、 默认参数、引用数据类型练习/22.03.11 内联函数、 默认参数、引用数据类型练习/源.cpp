//1.����������ϰ
//��ͬһ����������Ϊ���������ͷ�����������ͳ�ƶ���֮���ʱ�����Ĳ��졣
//��ʾ����windows.h�е�GetTickCount() ������õ�ǰʱ�̵�������
//2.Ĭ�ϲ���
//�ж�����Բ֮��Ĺ�ϵ������������������У���������������Բ��֮�����ĺ���������Ϊ��Ĭ��ֵ�Ĳ�����
//3.������������
//�������βΣ�ʵ���������Ľ���
//�÷���Ϊ���ú����������ֲ�����ͬ����ȫ�ֱ���


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
	cout << "1.����������ʱ��" << end_time - start_time << '\t';
	start_time = GetTickCount();
	for (t = 0; t < 1000000; t++) {
		z = add2(x, y);
	}
	end_time = GetTickCount();
	cout << "������������ʱ��" << end_time - start_time << endl;
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
		cout << "����" << endl;
	}
	if (c1.judgeRelation(c2) == 2) {
		cout << "����" << endl;
	}
	if (c1.judgeRelation(c2) == 3) {
		cout << "�ཻ" << endl;
	}
}

void swap_nums() {
	int a = 1, b = 2;
	cout << endl << "3.";
	cout << "����ǰ��a=" << a << "��b=" << b << endl;
	swap1(a, b);
	cout << "������a=" << a << "��b=" << b << endl;
}

void swap1(int& m, int& n) {//�������βΣ�ʵ���������Ľ���
	m = m ^ n;
	n = m ^ n;
	m = m ^ n;
}