//����һ����book,���к�������˽�����ݳ�Աqu�� price,�� qu��ʼ��Ϊ1��5����price��ʼ��Ϊqu��10��,
//����һ����5��Ԫ�ص����������ʾÿ����������Ԫ�ص�qu * priceֵ��
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


//�޸�ϰ��3.33,ͨ������ָ����ʶ�������,ʹ�������෴��˳����ʾÿ����������Ԫ�ص�qu * priceֵ��
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
	Book* p = &b[4];//����ָ����ʶ�������
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
