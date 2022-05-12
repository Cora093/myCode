//构建一个类Stock,含字符数组 stockcode[]及整型数据成员quan、双精度型数据成员 price。
//构造函数含3个参数:字符数组 na[]及q、p。
//当定义Stock的类对象时﹐将对象的第1个字符串参数赋给数据成员 stockeode
//第2和第3个参数分别赋给quan , price。未设置第⒉和第3个参数时,quan 的值为1000,price的值为8.98
//成员函数 print没有形参﹐需使用this指针,显示对象数据成员的内容
//假设类Stock 第1个对象的三个参数分别为:600001，3000和5.67
//第2个对象的第1个数据成员的值是600001.第2和第3个数据成员的值取默认值。
//要求编写程序分别显示这两个对象数据成员的值。

#include <iostream>
using namespace std;

class Stock {
public:
	Stock(string na, int q = 1000, double p = 8.98) :stockcode(na), quan(q), price(p) {}

	void print() {
		cout << this->stockcode << '\t' << this->quan << '\t' << this->price << endl;
	}

private:
	string stockcode;
	int quan;
	double price;
};

void test01() {
	Stock a("600001", 3000, 5.67);
	Stock b("600001");
	a.print();
	b.print();

}
int main() {
	test01();

	system("pause");
	return 0;
}