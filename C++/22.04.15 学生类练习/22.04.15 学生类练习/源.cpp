//��дһ��������������ѧ�������ݣ�����ѧ�š��������ɼ�
//Ҫ�������Щѧ�������ݲ������ѧ��������ƽ���ɼ�
//��Ҫ��ѧ���������ܳɼ��þ�̬���ݳ�Ա��ʾ��

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
		cout << "���캯�����ѧ��" << endl;
		m_Ascore *= m_Snum;
		m_Snum++;
		m_Ascore += m_Score;
		m_Ascore /= m_Snum;
	}

	~Student() {
		cout << "��������ɾ��ѧ��" << endl;
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

int Student::m_Snum = 0;//��̬�����������ʼ��
int Student::m_Ascore = 0;

void dispS(Student& s) {//չʾ��ǰѧ������Ϣ
	cout << s.m_Id << "\t" << s.m_Name << "\t" << s.m_Score << endl;
}
void disp(){ //չʾ��������ƽ����
	cout << "��������" << Student::m_Snum << "\tƽ���֣�" << Student::m_Ascore << endl;
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


