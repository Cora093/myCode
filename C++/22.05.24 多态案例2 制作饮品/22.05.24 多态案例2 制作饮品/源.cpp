#include <iostream>
using namespace std;

class AbstractDrinking {
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//流程
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "烧水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "把咖啡倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加牛奶" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "烧水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "把茶倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加枸杞" << endl;
	}
};

//1.父类引用指向子类对象
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

//2.父类指针指向子类对象
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
