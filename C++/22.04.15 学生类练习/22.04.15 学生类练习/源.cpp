//��дһ��������������ѧ�������ݣ�����ѧ�š��������ɼ�
//Ҫ�������Щѧ�������ݲ������ѧ��������ƽ���ɼ�
//��Ҫ��ѧ���������ܳɼ��þ�̬���ݳ�Ա��ʾ��

#include <iostream>
using namespace std;
#include<string>

class Student {
public:

	static int m_Snum;
	static int m_Ascore;

	Student(int a, int b, string c) :m_Id(a), m_Score(b), m_Name(c) {
		cout << "���ѧ��" << endl;
		m_Ascore *= m_Snum;
		m_Snum++;
		m_Ascore += m_Score;
		m_Ascore /= m_Snum;
	}
	~Student() {
		cout << "ɾ��ѧ��" << endl;
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

	int getId() {
		return this->m_Id;
	}
	int getScore() {
		return this->m_Score;
	}
	string getName() {
		return this->m_Name;
	}


private:
	int m_Id;
	string m_Name;
	int m_Score;

};

int Student::m_Snum = 0;//��̬�����������ʼ��
int Student::m_Ascore = 0;

void dispS(Student &s) {//չʾ��ǰѧ������Ϣ
	cout << s.getId() << " " << s.getName() << " " << s.getScore() << endl;
}
void dispA(){ //չʾ��������ƽ����
	cout << "��������" << Student::m_Snum << "\tƽ���֣�" << Student::m_Ascore << endl;
}

int main() {
	Student a(2152714, 60, "cora");
	dispS(a);
	dispA();

	Student b(2152777, 80, "aaa");
	dispS(b);
	dispA();

	a.~Student();
	dispA();

	system("pause");
	return 0;
}


