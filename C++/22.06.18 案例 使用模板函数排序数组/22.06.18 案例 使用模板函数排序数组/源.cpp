#include <iostream>
using namespace std;

//使用模板函数对数组进行排序
//排序规则 从小到大
//排序算法 选择排序
//测试用例 int char double 数组

//显示函数模板
template<typename T>
void showArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//交换函数模板
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//排序函数模板
template<typename T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int min = i;//设定默认最小值
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			//交换min与i
			mySwap(arr[min], arr[i]);
		}
	}
}


void test01() {
	char charArr[] = "bdacef";
	cout << "排序前的字符数组：";
	showArray(charArr, sizeof(charArr)-1);

	mySort(charArr, sizeof(charArr)-1);
	
	cout << "排序后的字符数组：";
	showArray(charArr, sizeof(charArr)-1);
}

void test02() {
	int intArr[6] = { 3,2,4,6,5,1 };
	cout << "排序前的整形数组：";
	showArray(intArr, sizeof(intArr)/4);

	mySort(intArr, sizeof(intArr)/4);

	cout << "排序后的整形数组：";
	showArray(intArr, sizeof(intArr)/4);
}

int main() {
	
	test01();
	test02();

	system("pause");
 	return 0;
}
