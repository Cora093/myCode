//����ѧ���࣬�������ݳ�ԱΪѧ�ź�����
//������Ա����Ϊ���췽����getter��setter����ʾ��Ϣ�Ⱥ�����

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