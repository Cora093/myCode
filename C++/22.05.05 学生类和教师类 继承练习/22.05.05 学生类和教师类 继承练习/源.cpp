//��дһ��ѧ���ͽ�ʦ�����������ʾ����
//ѧ��������ѧ�� ���� �ɼ�
//��ʦ�����б�� ���� ְ�� ����
//Ҫ�󽫱�š������������ʾ��Ƴ�һ����Person������ΪStudent��Teacher�Ļ���
//�����࣬�����а���: �꣬�£��գ����췽����������������ʾ����
//�β�����֮������ݲ��  int disDate(const Date&)
//׼ȷ���㵱ǰ���ں��β�����֮��Ĳ�ࣨע�⣬�β����ڿ��ܱȵ�ǰ�������Ҫ����������У����������������ڼ����ݲ 
//���� 2022��4��27�պ�2021��4��28��֮�䣬����һ�꣬��˼�����Ӧ��Ϊ0����
//��Person ����������ڣ���ѧ�����м�����ѧ���ڣ��ڽ������м�����ְ���ڡ�
//���������д�����Ӧѧ�����ʦ�����ж�ͬѧ�Ƕ�������ѧ����ʦ�Ƕ�������ְ�ġ�

#include <iostream>
using namespace std;
#include <string>

class Date {
public:
	int year;
	int month;
	int day;

	Date() {
		year = 0;
		month = 0;
		day = 0;
	}

	Date(int a,int b,int c) :year(a),month(b),day(c){}

	void showDate() {
		cout << year;
		if (month < 10) {
			cout << '0';
		}
		cout << month;
		if (day < 10) {
			cout << '0';
		}
		cout << day << endl;
	}

	int disDate(const Date& d) {
		Date d1, d2;
		int ret = 0;
		//�ж���ݴ�С
		if (this->year == d.year) {
			return 0;
		}
		else if (this->year > d.year) {
			d1 = *this;
			d2 = d;
		}
		else {
			d1 = d;
			d2 = *this;
		}

		ret = d1.year - d2.year;
		if (d1.month > d2.month) {
			return ret;
		}
		else if (d1.month < d2.month) {
			ret--;
			return ret;
		}

		//��������
		if (d1.day > d2.day) {
			return ret;
		}
		else if (d1.day < d2.day) {
			ret--;
			return ret;
		}
		//���ն����
		else {
			return ret;
		}
	}
};

class Person {
public:
	int id;
	Date birthDate;
	string name;
};

class Student:public Person {
public:
	Date sEnterDate;
	int score;
};

class Teacher :public Person {
public:
	Date tEnterDate;
	string department;
	string title;
};

void test01() {
	Student a;
	a.id = 2152111;
	a.name = "xiaowang";
	a.score = 60;
	a.birthDate.year = 2002;
	a.birthDate.month = 9;
	a.birthDate.day = 3;
	a.sEnterDate.year = 2010;
	a.sEnterDate.month = 9;
	a.sEnterDate.day = 1;
	a.birthDate.showDate();
	a.sEnterDate.showDate();
	cout << "���ʱ��" << a.birthDate.disDate(a.sEnterDate) << "��" << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}