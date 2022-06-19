#include <iostream>
using namespace std;
#include <string>

template<class NameType,class AgeType = int>//默认AgeType为整形
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showInfo() {
		cout << this->m_Name << '\t' << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test01() {
	//1.类模板不能自动类型推导
	//Person p("张三"，100);错误
	Person<string, int> p("张三",99);


	//2.类模板在模板参数列表中可以有默认参数
	Person<string> p1("李四", 98);//由于第5行有默认参数
	p1.showInfo();

}

int main() {
	test01();

	system("pause");
	return 0;
}
