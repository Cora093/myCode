#include <iostream>
#include <fstream>
using namespace std;

void test01() {
	//�ı��ļ� д�����
	//1.ͷ�ļ�fstream
	
	//2.����������
	ofstream a;

	//3.ָ���򿪷�ʽ
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::out);

	//4.д����
	a << "������С��" << endl;
	a << "���䣺18" << endl;
	a << "�Ա���" << endl;

	//5.�ر��ļ�
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}
