//��дһ��������������ѧ�������ݣ�����ѧ�š��������ɼ�
//Ҫ�������Щѧ�������ݲ������ѧ��������ƽ���ɼ���Ҫ��ѧ���������ܳɼ��þ�̬���ݳ�Ա��ʾ��

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	int id;
	int score;
	string name;
	static int num;
	static float averScore;

	Student(int a, int b, string c) :id(a), score(b), name(c){
		Student::averScore = Student::averScore * Student::num++;
		Student::averScore = (Student::averScore + b) / Student::num;
	}

	void disp() {
		cout << id << '\t' << score << '\t' << name << endl;
	}
};

int Student::num = 0;
float Student::averScore = 0;

void dispA() {
	cout << "��������" << Student::num << "ƽ��������" << Student::averScore << endl;
}


void test01() {
	Student a(111, 60, "xiaowang");
	Student b(222, 80, "xiaoli");
	Student c(333, 100, "xiaozhang");
	a.disp();
	b.disp();
	c.disp();
	dispA();

}


int main() {


	test01();
	system("pause");
	return 0;
}
