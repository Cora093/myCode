//����һ����Stock,���ַ����� stockcode[]���������ݳ�Աquan��˫���������ݳ�Ա price��
//���캯����3������:�ַ����� na[]��q��p��
//������Stock�������ʱ�o������ĵ�1���ַ��������������ݳ�Ա stockeode
//��2�͵�3�������ֱ𸳸�quan , price��δ���õڢ��͵�3������ʱ,quan ��ֵΪ1000,price��ֵΪ8.98
//��Ա���� printû���βΩo��ʹ��thisָ��,��ʾ�������ݳ�Ա������
//������Stock ��1����������������ֱ�Ϊ:600001��3000��5.67
//��2������ĵ�1�����ݳ�Ա��ֵ��600001.��2�͵�3�����ݳ�Ա��ֵȡĬ��ֵ��
//Ҫ���д����ֱ���ʾ�������������ݳ�Ա��ֵ��

#include <iostream>
using namespace std;

class Stock {
public:
	Stock(string na, int q = 1000, double p = 8.98) :stockcode(na), quan(q), price(p) {}

	void print() {
		cout << this->stockcode << '\t' << this->quan << '\t' << this->price << endl;
	}

private:
	string stockcode;
	int quan;
	double price;
};

void test01() {
	Stock a("600001", 3000, 5.67);
	Stock b("600001");
	a.print();
	b.print();

}
int main() {
	test01();

	system("pause");
	return 0;
}