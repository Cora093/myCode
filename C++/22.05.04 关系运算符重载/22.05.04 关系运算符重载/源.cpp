#include <iostream>
using namespace std;
#include<string>

class Person {
public:
	string m_Name;
	int m_Age;

	Person(string name,int age) {//构造函数
		this->m_Age = age;
		this->m_Name = name;
	}

	bool operator==(Person &p) {
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
			return true;
		}
		return false;
	}

	bool operator!=(Person& p) {
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
			return false;
		}
		return true;
	}
};

void test01() {
	Person p1("小王", 18);
	Person p2("小王", 18);
	Person p3("小李", 18);
	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}
	if (p1 == p3) {
		cout << "p1和p3相等" << endl;
	}
	else {
		cout << "p1和p3不相等" << endl;
	}
}

int main() {
	test01();

	system("pause");
	return 0;
}
