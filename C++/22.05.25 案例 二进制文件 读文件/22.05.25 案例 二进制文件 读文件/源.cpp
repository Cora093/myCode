#include <iostream>
#include <fstream>
using namespace std;


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//�������ļ� ���ļ�
void test01() {
	//1.����ͷ�ļ�
	//2.����������
	ifstream a;

	//3.���ļ� �ж��ļ��Ƿ�򿪳ɹ�
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::in | ios::binary);
	if (!a.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//4.���ļ�
	Person p;
	a.read((char*)&p, sizeof(Person));

	cout << p.m_Name << endl << p.m_Age << endl;

	//5.�ر��ļ�
	a.close();
}


int main() {

	test01();
	system("pause");
	return 0;
}
