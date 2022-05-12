#include <iostream>
using namespace std;
#include <string>
//分别利用普通写法和多态技术实现计算器

//普通写法
//后期修改或增加功能需要修改源码
class Calculator {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
	}

	int m_Num1;
	int m_Num2;
};

void test01() {
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.getResult("+") << '\t' << c.getResult("-") << '\t' << c.getResult("*") << '\t' << endl;

}

//利用多态实现计算器

//实现计算器抽象类
class AbstractCalculator {
public:
	virtual int getResult(){
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法类
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};

//减法类
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};

//乘法类
class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};

void test02() {
	//父类引用或指针指向子类对象
	AbstractCalculator* a = new AddCalculator;
	a->m_Num1 = 10;
	a->m_Num2 = 20;
	cout << a->getResult() << endl;
	//用完删除指针
	delete a;

	a = new SubCalculator;
	a->m_Num1 = 10;
	a->m_Num2 = 20;
	cout << a->getResult() << endl;
	delete a;

	a = new MulCalculator;
	a->m_Num1 = 10;
	a->m_Num2 = 20; 
	cout << a->getResult() << endl;
	delete a;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}