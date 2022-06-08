#include <iostream>
#include <string>
using namespace std;

class MyArray {								//基类
public:
	MyArray(int leng);						//构造函数
	~MyArray();								//析构函数
	void Input();							//输人数据的成员函数
	void Display(string);					//输出数据的成员函数
protected:
	int* alist;								//基类中存放一组整数
	int length;								//整数的个数
};

class SortArray : public MyArray {
public:
	void Sort();							//将输人的整数从小到大排序。
	SortArray(int leng) :MyArray(leng) {
		cout << "SortArray类对象已创建。" << endl;
	}
	virtual ~SortArray();
};

SortArray:: ~SortArray(){
	cout << "SortArray类对象被撤销。" << endl;
}

void SortArray::Sort() {					//将输人的整数从小到大排序。
	int i = 0, j = 0;
	int* p = alist;
	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - i - 1; j++, p++) {
			if (*p > *(p + 1)) {
				int temp = 0;
				temp = *p;
				*p = *(p + 1);
				*(p + 1) = temp;
			}
		}
		p = alist;
	}
}


MyArray::MyArray(int leng) {
	if (leng <= 0) {
		cout << "error length";
		exit(1);							//结束程序
	}
	alist = new int[leng];
	length = leng;
	if (alist == NULL){
		cout << "assign failure";
		exit(1);							//结束程序
	}
	cout << "MyArray类对象已创建。" << endl;
}

MyArray:: ~MyArray() {
	delete[] alist;
	cout << "MyArray类对象被撤销。" << endl;
}

void MyArray::Display(string str) {			//显示数组内容
	int i;
	int* p = alist;
	cout << str << length << "个整数:";
	for (i = 0; i < length; i++, p++) {
		cout << *p << " ";
	}
	cout << endl;
}

void MyArray::Input() {						//从键盘输入若干整数
	cout << "请从键盘输入" << length << "个整数:";
	int i;
	int* p = alist;
	for (i = 0; i < length; i++, p++) {
		cin >> *p;
	}
}
int main(){
	SortArray s(5);
	s.Input();								//输人整数
	s.Display("显示排序以前的");				//显示排序以前的整数
	s.Sort();								//进行排序
	s.Display("显示排序以后的");				//显示排序以后的整数
	system("pause");

	return 0;
}

