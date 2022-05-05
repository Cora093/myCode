//编写一个学生和教师数据输入和显示程序
//学生数据有学号 姓名 成绩
//教师数据有编号 姓名 职称 部门
//要求将编号、姓名输入和显示设计成一个类Person，并作为Student和Teacher的基类
//日期类，该类中包含: 年，月，日，构造方法，析构方法，显示方法
//形参日期之间求年份差的  int disDate(const Date&)
//准确计算当前日期和形参日期之间的差距（注意，形参日期可能比当前早或晚，都要能算出二者中，晚的日期与早的日期间的年份差， 
//比如 2022年4月27日和2021年4月28号之间，相差不到一年，因此计算结果应该为0）。
//在Person 加入出生日期；在学生类中加入入学日期，在教室类中加入入职日期。
//在主函数中创建相应学生与教师对象，判断同学是多少岁上学，老师是多少岁入职的。

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
		//判断年份大小
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

		//如果月相等
		if (d1.day > d2.day) {
			return ret;
		}
		else if (d1.day < d2.day) {
			ret--;
			return ret;
		}
		//月日都相等
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
	cout << "相差时间" << a.birthDate.disDate(a.sEnterDate) << "年" << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}