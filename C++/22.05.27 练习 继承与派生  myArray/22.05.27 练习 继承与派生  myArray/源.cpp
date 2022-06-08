#include <iostream>
#include <string>
using namespace std;

class MyArray {								//����
public:
	MyArray(int leng);						//���캯��
	~MyArray();								//��������
	void Input();							//�������ݵĳ�Ա����
	void Display(string);					//������ݵĳ�Ա����
protected:
	int* alist;								//�����д��һ������
	int length;								//�����ĸ���
};

class SortArray : public MyArray {
public:
	void Sort();							//�����˵�������С��������
	SortArray(int leng) :MyArray(leng) {
		cout << "SortArray������Ѵ�����" << endl;
	}
	virtual ~SortArray();
};

SortArray:: ~SortArray(){
	cout << "SortArray����󱻳�����" << endl;
}

void SortArray::Sort() {					//�����˵�������С��������
	int i = 0, j = 0;
	int* p = alist;
	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - i - 1; j++, p++) {
			if (*p > *(p + 1)) {
				int temp = 0;
				temp = *p;
				*p = *(p + 1);
				*(p + 1) = temp;
			}
		}
		p = alist;
	}
}


MyArray::MyArray(int leng) {
	if (leng <= 0) {
		cout << "error length";
		exit(1);							//��������
	}
	alist = new int[leng];
	length = leng;
	if (alist == NULL){
		cout << "assign failure";
		exit(1);							//��������
	}
	cout << "MyArray������Ѵ�����" << endl;
}

MyArray:: ~MyArray() {
	delete[] alist;
	cout << "MyArray����󱻳�����" << endl;
}

void MyArray::Display(string str) {			//��ʾ��������
	int i;
	int* p = alist;
	cout << str << length << "������:";
	for (i = 0; i < length; i++, p++) {
		cout << *p << " ";
	}
	cout << endl;
}

void MyArray::Input() {						//�Ӽ���������������
	cout << "��Ӽ�������" << length << "������:";
	int i;
	int* p = alist;
	for (i = 0; i < length; i++, p++) {
		cin >> *p;
	}
}
int main(){
	SortArray s(5);
	s.Input();								//��������
	s.Display("��ʾ������ǰ��");				//��ʾ������ǰ������
	s.Sort();								//��������
	s.Display("��ʾ�����Ժ��");				//��ʾ�����Ժ������
	system("pause");

	return 0;
}

