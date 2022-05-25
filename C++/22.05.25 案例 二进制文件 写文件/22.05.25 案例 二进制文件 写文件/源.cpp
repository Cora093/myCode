#include <iostream>
#include <fstream>
using namespace std;

//二进制文件 写文件
class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	//1.包含头文件
	//2.创建流对象
	ofstream a;

	//3.打开文件（打开方式为二进制写入）
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::out | ios::binary);

	//4.写文件
	Person p = { "张三",18 };
	a.write((const char*)&p, sizeof(Person));
	//5.关闭文件
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}
