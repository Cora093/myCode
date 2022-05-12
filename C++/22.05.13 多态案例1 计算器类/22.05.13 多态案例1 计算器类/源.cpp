#include <iostream>
using namespace std;
#include <string>
//�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����

//��ͨд��
//�����޸Ļ����ӹ�����Ҫ�޸�Դ��
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

//���ö�̬ʵ�ּ�����

//ʵ�ּ�����������
class AbstractCalculator {
public:
	virtual int getResult(){
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ���
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};

//������
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};

//�˷���
class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};

void test02() {
	//�������û�ָ��ָ���������
	AbstractCalculator* a = new AddCalculator;
	a->m_Num1 = 10;
	a->m_Num2 = 20;
	cout << a->getResult() << endl;
	//����ɾ��ָ��
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