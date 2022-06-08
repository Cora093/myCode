//编写一个程序，已有若干学生的数据，包括学号、姓名、成绩
//要求输出这些学生的数据并计算出学生人数和平均成绩（要求将学生人数和总成绩用静态数据成员表示）

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
	cout << "总人数：" << Student::num << "平均分数：" << Student::averScore << endl;
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
