#include <iostream>
using namespace std;

class AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//����
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�ѿ��ȵ��뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "��ţ��" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�Ѳ赹�뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "�����" << endl;
	}
};

//1.��������ָ���������
//void doWork(AbstractDrinking& a) {
//	a.makeDrink();
//}
//
//void test01() {
//	Coffee c;
//	doWork(c);
//	Tea t;
//	doWork(t);
//}

//2.����ָ��ָ���������
void doWork(AbstractDrinking * a) {
	a->makeDrink();
	delete a;
}

void test01() {
	doWork(new Coffee);
	doWork(new Tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}
