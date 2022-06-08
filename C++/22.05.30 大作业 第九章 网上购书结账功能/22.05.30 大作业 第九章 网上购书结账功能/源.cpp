#include <iostream>
#include <string>
using namespace std;


class buyer {										//����
protected:
	string name;									//����
	int buyerID;									//�����˱��
	string address;									//��ַ
	double pay;										//�������
public:
	buyer();
	buyer(string n, int b, string a, double p);
	string getbuyname();
	int getid();
	string getaddress();
	double getpay();
	virtual void display() = 0;						//��ʾ����
	virtual void setpay(double = 0) = 0;			//���㹺�����
};
	
class member :public buyer {						//��Ա��
private:
	int leaguer_grade;
public:
	member(string n, int b, int l, string a, double p) :buyer(n, b, a, p) {
		leaguer_grade = l;
	}
	void display();
	void setpay(double p);
};

class honoured_guest :public buyer {				//�����
	double discount_rate;
public:
	honoured_guest(string n, int b, double r, string a, double p) :buyer(n, b, a, p) {
		discount_rate = r;
	}
	void display();
	void setpay(double p);
};

class layfolk :public buyer {						//��ͨ����
public:
	layfolk(string n, int b, string a, double p) :buyer(n, b, a, p) {}
	void display();
	void setpay(double p);
};



buyer::buyer() {
	name = "";
	buyerID = 0;
	address = "";
	pay = 0;
}

buyer::buyer(string n, int b, string a, double p) {
	name = n;
	buyerID = b;
	address = a;
	pay = p;
}

string buyer::getbuyname() {
	return name;
}

int buyer::getid() {
	return buyerID;
}

string buyer::getaddress() {
	return address;
}

double buyer::getpay() {
	return pay;
}

void member::display() {
	cout << "����������:" << name << "\t";
	cout << "�����˱��:" << buyerID << "\t";
	cout << "������Ϊ��Ա������" << leaguer_grade << "\n";
	cout << "��ַ��" << address << "\n";
}

void member::setpay(double p) {
	if (leaguer_grade == 1) {
		pay = .95 * p + pay;
	}
	else if (leaguer_grade == 2) {
		pay = .90 * p + pay;
	}
	else if (leaguer_grade == 3) {
		pay = .85 * p + pay;
	}
	else if (leaguer_grade == 4) {
		pay = .8 * p + pay;
	}
	else if (leaguer_grade == 5) {
		pay = .7 * p + pay;
	}
	else {
		cout << "�������";
	}
}

void honoured_guest::display() {
	cout << "����������:" << name << "\t";
	cout << "�����˱��:" << buyerID << "\t";
	cout << "������Ϊ������ۿ���Ϊ��" << discount_rate * 100 << "% \n";
	cout << "��ַ��" << address << "\n\n";
}

void honoured_guest::setpay(double p) {
	pay = pay + (1 - discount_rate) * p;
}

void layfolk::display() {
	cout << "����������:" << name << "\t";
	cout << "�����˱��:" << buyerID << "\t";
	cout << "������Ϊ��ͨ��" << "\n";
	cout << "��ַ��" << address << "\n\n";
}

void layfolk::setpay(double p) {
	pay = pay + p;
}

class book {
protected:
	string book_ID;
	string book_name;
	string author;
	string publishing;
	double price;

public:
	book();
	book(string b_id,string b_n,string au,string pu,double pr);
	void display();
	string getbook_Id();
	string getbook_name();
	string getauthor();
	string getpublishing();
	double getprice();

};

book::book() {
	book_ID = "";
	book_name = "";
	author = "";
	publishing = "";
	price = 0;
}

book::book(string b_id, string b_n, string au, string pu, double pr) {
	book_ID = b_id;
	book_name = b_n;
	author = au;
	publishing = pu;
	price = pr;
}

void book::display() {
	cout << "��ţ�" << book_ID << "\t";
	cout << "������" << book_name << "\t";
	cout << "���ߣ�" << author << "\t";
	cout << "�����磺" << publishing << "\t";
	cout << "���ۣ�" << price << "\n";
}

string book::getbook_Id() {
	return book_ID;
}

string book::getbook_name() {
	return book_name;
}
string book::getauthor() {
	return author;
}
string book::getpublishing() {
	return publishing;
}
double book::getprice() {
	return price;
}

int main() {
	int i = 0, buyerid, flag;

	layfolk b1("��С��", 1, "����", 0);
	honoured_guest b2("����ң", 2, .6, "�Ϻ�", 0);
	member b3("�Ժ���", 3, 5, "����", 0);
	buyer* b[3] = { &b1,&b2,&b3 };

	book* c[2];
	book c1("7-302-04504-6", "C++�������", "̷��ǿ", "�廪", 25);
	book c2("1-742-03388-9", "���ݽṹ", "��׿Ⱥ", "����", 20);
	c[0] = &c1;
	c[1] = &c2;
	cout << "��������Ϣ:\n\n";
	for (i = 0; i < 3; i++) {
		b[i]->display();
	}
	cout << "\nͼ����Ϣ:\n\n";
	for (i = 0; i < 2; i++) {
		c[i]->display();
	}
	cout << "\n\n�����빺���˱��:";
	cin >> buyerid;
	flag = 0;
	for (i = 0; i < 3; i++) {
		if (b[i]->getid() == buyerid) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		cout << "��Ų�����" << endl;
	}
	else {
		b[i]->setpay(c[0]->getprice());
		b[i]->setpay(c[1]->getprice());
		cout << endl << "��������Ҫ����:" << b[i]->getpay() << "\n\n";
	}
	system("pause");
	return 0;
}
