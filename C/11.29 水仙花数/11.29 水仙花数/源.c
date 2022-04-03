#define _CRT_SECURE_NO_WARNINGS 1
//水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例如：153 
//本题要求编写程序, 计算所有N位水仙花数。
//输入在一行中给出一个正整数N（3≤N≤7）。
//按递增顺序输出所有N位水仙花数，每个数字占一行。

#include <stdio.h>

int main() {
	int quWeiShu(int num, int n);
	int power(int a, int b);
	int num, n;
	int i, j;
	int sum;
	scanf("%d", &n);
	for (num = power(10, n-1); num < power(10, n ); num++) {		//范围在n位数内
		sum = 0;
		for (j = n; j >= 1; j--) {
			sum += power(quWeiShu(num, j), n);							//累加每一位的n次方
			if (j > 1 && sum > num) {									//若已经大于本身，跳出
				break;
			}
		}
		if (sum == num) {
			printf("%d\n", num);
		}
	}

	return 0;
}

int quWeiShu(int num, int a) {											//取出数的第a位
	int k;
	k = num % power(10, a)/ power(10,a - 1);
	return k;
}

int power(int a, int b) {
	int i, di;
	di = a;
	if (b == 0) {
		a = 1;
	}
	else{
		for (i = 1, a = 1; i <= b; i++) {
			a *= di;
		}
	}
	
	return a;
}
