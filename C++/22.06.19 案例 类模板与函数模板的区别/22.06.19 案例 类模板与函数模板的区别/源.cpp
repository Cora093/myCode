#include <iostream>
using namespace std;
#include <string>

template<class NameType,class AgeType = int>//Ĭ��AgeTypeΪ����
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
	//1.��ģ�岻���Զ������Ƶ�
	//Person p("����"��100);����
	Person<string, int> p("����",99);


	//2.��ģ����ģ������б��п�����Ĭ�ϲ���
	Person<string> p1("����", 98);//���ڵ�5����Ĭ�ϲ���
	p1.showInfo();

}

int main() {
	test01();

	system("pause");
	return 0;
}
