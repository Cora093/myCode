#include <iostream>
#include <fstream>
using namespace std;

//�������ļ� д�ļ�
class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	//1.����ͷ�ļ�
	//2.����������
	ofstream a;

	//3.���ļ����򿪷�ʽΪ������д�룩
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::out | ios::binary);

	//4.д�ļ�
	Person p = { "����",18 };
	a.write((const char*)&p, sizeof(Person));
	//5.�ر��ļ�
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}
