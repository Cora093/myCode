/*
#include <iostream>
#include <windows.h>   
#include <cstdlib> 
#include <ctime>  
using namespace std;
char a[100][100] = { {0} };
int main() {
	void print(int n, char sign);
	char  sign = '>';
	int n; 
	cin >> n >> sign;
	print(n, sign);
	return 0;
}
void print(int n, char sign) {
	void position(int n, int* i, int* j);
	while (1) { 
		int i = 0, j = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				if (i == 0 || i == n - 1)
					a[i][j] = sign;
				else if (j == 0 || j == n - 1)
					a[i][j] = sign;
				else
					a[i][j] = ' '; 
		}
		position(n, &i, &j);
		a[i][j] = '*'; 
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
		Sleep(1000); 
	}
}
void position(int n, int* i, int* j) {
	srand(time(0)); 
	*i = rand() % (n - 2) + 1;
	*j = rand() % (n - 2) + 1; 
}




#include <iostream>
using namespace std;
char* p;

int main() {
	double x, y;
	cin >> x >> y;
	if (x > 0 && y > 0 && y + x / 2 - 100 < 0) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}

*/



#include <iostream>
using namespace std;
int date[3] = { 0 }, week = 2, i = 0;
int amonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	char s[10];
	int  change(char* s);
	cin >> s;
	cout << change(s);
}
int  change(char* s) {
	int nian(int n);
	for (int i = 0; i < 4; i++)
		date[0] = date[0] * 10 + s[i] - 48;
	for (int i = 5; i < 7; i++)
		date[1] = date[1] * 10 + s[i] - 48;
	for (int i = 8; i < 10; i++)
		date[2] = date[2] * 10 + s[i] - 48;
	for (int i = 1980; i < date[0]; i++)
		if (nian(i))
			week = week + 2;
		else
			week = week + 1;
	for (int i = 1; i < date[1]; i++)
		week += amonth[i];
	for (int i = 1; i < date[2]; i++)
		week++;
	week = week % 7;
	return week;
}
int nian(int n) {
	return (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) ? 1 : 0;
}



