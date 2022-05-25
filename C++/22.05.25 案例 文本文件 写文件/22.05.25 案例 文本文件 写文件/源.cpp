#include <iostream>
#include <fstream>
using namespace std;

void test01() {
	//文本文件 写入操作
	//1.头文件fstream
	
	//2.创建流对象
	ofstream a;

	//3.指定打开方式
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::out);

	//4.写内容
	a << "姓名：小王" << endl;
	a << "年龄：18" << endl;
	a << "性别：男" << endl;

	//5.关闭文件
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}
