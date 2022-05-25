#include <iostream>
#include <fstream>
using namespace std;


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//二进制文件 读文件
void test01() {
	//1.包含头文件
	//2.创建流对象
	ifstream a;

	//3.打开文件 判断文件是否打开成功
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::in | ios::binary);
	if (!a.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读文件
	Person p;
	a.read((char*)&p, sizeof(Person));

	cout << p.m_Name << endl << p.m_Age << endl;

	//5.关闭文件
	a.close();
}


int main() {

	test01();
	system("pause");
	return 0;
}
