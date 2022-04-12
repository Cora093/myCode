//�����������(Cube)
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����

#include<iostream>
using namespace std;

class Cube {
public:
	//���ó�
	void setL(int l) {
		m_L = l;
	}
	//��ȡ��
	int getL() {
		return m_L;
	}
	//���ÿ�
	void setW(int w) {
		m_W = w;
	}
	//��ȡ��
	int getW() {
		return m_W;
	}
	//���ø�
	void setH(int h) {
		m_H = h;
	}
	//��ȡ��
	int getH() {
		return m_H;
	}
	//��ȡ���������
	int calcuS() {
		return 2 * (m_H * m_L + m_H * m_W + m_L * m_W);
	}
	//��ȡ���������
	int calcuV() {
		return m_H * m_L * m_W;
	}
	//��Ա�����ж������������Ƿ����
	bool isSameByClass(Cube &c) {
		return (m_H == c.getH() && m_L == c.getL() && m_W == c.getW()) ? true : false;
	}
private:
	int m_L;//������ĳ�
	int m_W;//������Ŀ�
	int m_H;//������ĸ�

};

//����ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube &c1,Cube &c2) {
	return (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW()) ? true : false;
}

int main() {
	Cube C1;
	C1.setH(10);
	C1.setW(10);
	C1.setL(10);
	cout << "C1�����Ϊ:" << C1.calcuS() << endl;
	cout << "C1�����Ϊ:" << C1.calcuV() << endl;
	Cube C2;
	C2.setH(10);
	C2.setW(10);
	C2.setL(10);
	cout << "ȫ�ֺ����жϵĽ����";
	isSame(C1, C2) ? (cout << "�����������") : (cout << "�������岻���");
	cout << endl;
	cout << "��Ա�����жϵĽ����";
	C1.isSameByClass(C2) ? (cout << "�����������") : (cout << "�������岻���");
	cout << endl;
	system("pause");
	return 0;
}