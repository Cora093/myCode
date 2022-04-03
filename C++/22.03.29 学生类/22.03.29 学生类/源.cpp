//定义学生类，包含数据成员为学号和名字
//包含成员函数为构造方法、getter和setter、显示信息等函数。

#include<iostream>
using namespace std;

class Student {
private:
	int id;
	string name;
public:
	Student();
	int getId() {
		return this->id;
	}
	void setId(int a) {
		this->id = a;
	}
};

int main() {
	return 0;
}