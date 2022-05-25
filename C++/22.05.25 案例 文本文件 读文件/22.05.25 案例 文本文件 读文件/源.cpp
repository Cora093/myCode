#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01() {
	//文本文件 读文件

	//1.包含头文件

	//2.创建流对象
	ifstream a;

	//3.打开文件 并且判断是否打开成功
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::in);

	if (!a.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读数据

	//第一种方式（字符数组）
	//char buf[1024] = { 0 };
	//while (a >> buf) {
	//	cout << buf << endl;
	//}

	//第二种方式（字符数组）
	//char buf[1024] = { 0 };
	//while (a.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//第三种方式（字符串）
	string buf;
	while (getline(a, buf)) {
		cout << buf << endl;
	}

	//第四种（不推荐）
	//char c;
	//while ((c = a.get()) != EOF) {
	//	cout << c;
	//}

	//5.关闭文件
	a.close();

}

int main() {

	test01();
	system("pause");
	return 0;
}
