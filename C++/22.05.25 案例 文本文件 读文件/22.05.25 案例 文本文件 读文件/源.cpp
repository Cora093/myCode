#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01() {
	//�ı��ļ� ���ļ�

	//1.����ͷ�ļ�

	//2.����������
	ifstream a;

	//3.���ļ� �����ж��Ƿ�򿪳ɹ�
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::in);

	if (!a.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//4.������

	//��һ�ַ�ʽ���ַ����飩
	//char buf[1024] = { 0 };
	//while (a >> buf) {
	//	cout << buf << endl;
	//}

	//�ڶ��ַ�ʽ���ַ����飩
	//char buf[1024] = { 0 };
	//while (a.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//�����ַ�ʽ���ַ�����
	string buf;
	while (getline(a, buf)) {
		cout << buf << endl;
	}

	//�����֣����Ƽ���
	//char c;
	//while ((c = a.get()) != EOF) {
	//	cout << c;
	//}

	//5.�ر��ļ�
	a.close();

}

int main() {

	test01();
	system("pause");
	return 0;
}
