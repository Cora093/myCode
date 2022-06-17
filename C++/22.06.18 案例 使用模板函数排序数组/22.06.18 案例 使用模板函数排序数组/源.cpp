#include <iostream>
using namespace std;

//ʹ��ģ�庯���������������
//������� ��С����
//�����㷨 ѡ������
//�������� int char double ����

//��ʾ����ģ��
template<typename T>
void showArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//��������ģ��
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//������ģ��
template<typename T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int min = i;//�趨Ĭ����Сֵ
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			//����min��i
			mySwap(arr[min], arr[i]);
		}
	}
}


void test01() {
	char charArr[] = "bdacef";
	cout << "����ǰ���ַ����飺";
	showArray(charArr, sizeof(charArr)-1);

	mySort(charArr, sizeof(charArr)-1);
	
	cout << "�������ַ����飺";
	showArray(charArr, sizeof(charArr)-1);
}

void test02() {
	int intArr[6] = { 3,2,4,6,5,1 };
	cout << "����ǰ���������飺";
	showArray(intArr, sizeof(intArr)/4);

	mySort(intArr, sizeof(intArr)/4);

	cout << "�������������飺";
	showArray(intArr, sizeof(intArr)/4);
}

int main() {
	
	test01();
	test02();

	system("pause");
 	return 0;
}
