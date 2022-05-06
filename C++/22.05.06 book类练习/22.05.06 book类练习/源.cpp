//构建一个类book,其中含有两个私有数据成员qu和 price,将 qu初始化为1～5，将price初始化为qu的10倍,
//建立一个有5个元素的数组对象。显示每个对象数组元素的qu * price值。
//#include <iostream>
//using namespace std;
//
//class Book {
//public:
//	Book(int a) {
//		qu = a;
//		price = 10 * qu;
//	}
//	void showData() {
//		cout << qu * price << endl;
//	}
//private:
//	int qu;
//	int price;
//
//};
//
//void test01() {
//	Book b[5]{1, 2, 3, 4, 5};
//	for (int i = 0; i < 5; i++) {
//		b[i].showData();
//	}
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}


//修改习题3.33,通过对象指针访问对象数组,使程序以相反的顺序显示每个对象数组元素的qu * price值。
#include <iostream>
using namespace std;

class Book {
public:
	Book(int a) {
		qu = a;
		price = 10 * qu;
	}
	void showData() {
		cout << qu * price << endl;
	}
private:
	int qu;
	int price;

};

void test01() {
	Book b[5]{ 1, 2, 3, 4, 5 };
	Book* p = &b[4];//对象指针访问对象数组
	for (int i = 0; i < 5; i++) {
		p->showData();
		p--;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}
