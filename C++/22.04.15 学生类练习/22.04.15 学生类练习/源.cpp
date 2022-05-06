//编写一个程序，已有若干学生的数据，包括学号、姓名、成绩
//要求输出这些学生的数据并计算出学生人数和平均成绩
//（要求将学生人数和总成绩用静态数据成员表示）

#include <iostream>
using namespace std;
#include<string>

class Student {
	friend void dispS(Student& s);
	friend ostream& operator<<(ostream& cout, Student& s);

public:
	static int m_Snum;
	static int m_Ascore;

	Student(int a, int b, string c) :m_Id(a), m_Score(b), m_Name(c) {
		cout << "构造函数添加学生" << endl;
		m_Ascore *= m_Snum;
		m_Snum++;
		m_Ascore += m_Score;
		m_Ascore /= m_Snum;
	}

	~Student() {
		cout << "析构函数删除学生" << endl;
		m_Ascore *= m_Snum;
		m_Snum--;
		if (m_Snum == 0) {
			m_Ascore = 0;
		}
		else {
			m_Ascore -= m_Score;
			m_Ascore /= m_Snum;
		}
	}
private:
	int m_Id;
	string m_Name;
	int m_Score;

};

int Student::m_Snum = 0;//静态变量在类外初始化
int Student::m_Ascore = 0;

void dispS(Student& s) {//展示当前学生的信息
	cout << s.m_Id << "\t" << s.m_Name << "\t" << s.m_Score << endl;
}
void disp(){ //展示总人数和平均分
	cout << "总人数：" << Student::m_Snum << "\t平均分：" << Student::m_Ascore << endl;
}
ostream& operator<<(ostream& cout, Student& s) {
	cout << s.m_Id << "\t" << s.m_Name << "\t" << s.m_Score ;
	return cout;
}


int main() {
	Student a(2152714, 60, "xiaowang");
	cout << a << endl;
	//dispS(a);
	disp();

	Student b(2152777, 80, "aaa");
	//dispS(a);
	//dispS(b);
	cout << a << endl;
	cout << b << endl;

	disp();

	a.~Student();
	disp();

	b.~Student();
	disp();

	system("pause");
	return 0;
}


