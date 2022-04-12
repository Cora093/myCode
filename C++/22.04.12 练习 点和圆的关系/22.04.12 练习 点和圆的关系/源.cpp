//���һ��Բ����(Circle)����һ�����ࣨPoint)��������Բ�Ĺ�ϵ��

#include"circle.h"
#include"point.h"

void isInCircle(Circle& c, Point& p) {
	int dist = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	int r = pow(c.getR(), 2);
	if (dist == r) {
		cout << "��Բ��" << endl;
		return;
	}
	if (dist > r) {
		cout << "��Բ��" << endl;
		return;
	}
	if (dist < r) {
		cout << "��Բ��" << endl;
		return;
	}
}

int main() {
	Circle C1;
	C1.setR(2);

	Point C1c;
	C1c.setX(0);
	C1c.setY(0);
	C1.setCenter(C1c);

	Point P1;
	P1.setX(2);
	P1.setY(0);
	isInCircle(C1, P1);
	system("pause");
	return 0;
}
