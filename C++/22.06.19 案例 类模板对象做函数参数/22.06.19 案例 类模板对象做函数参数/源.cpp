#include <iostream>
using namespace std;

//类模板对象做函数参数

template<class T1,class T2>
class Person {
public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << this->m_Name << '\t' << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//方法1.指定传入类型(最常用)
void printPerson1(Person<string, int>& p) {
	p.showPerson();
}


void test01() {
	Person<string, int>p1("张三", 39);
	printPerson1(p1);
}

//方法2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p) {
	p.showPerson();
}

void test02() {
	Person<string, int>p2("李四", 29);
	printPerson2(p2);
}

//方法3.整个类模板化
template<class T>
void printPerson3(T &p) {
	p.showPerson();
}


void test03() {
	Person<string, int>p3("王五", 19);
	printPerson3(p3);
}


int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}