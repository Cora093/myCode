#define _CRT_SECURE_NO_WARNINGS 1

//本题的目标很简单，就是判断一个给定的正整数是否素数。
//输入在第一行给出一个正整数N（≤ 10），随后N行，每行给出一个小于2^31的需要判断的正整数。
//对每个需要判断的正整数，如果它是素数，则在一行中输出Yes，否则输出No。

#include <stdio.h>
#include <math.h>

int main() {
	int ifSuShu(unsigned int a);
	unsigned int i, n, num;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num);
		if (ifSuShu(num) == 1) {
			printf("Yes");
		}
		else {
			printf("No");
		}
		if (i != n) {
			printf("\n");
		}
	}
	return 0;
}

int ifSuShu(unsigned int a) {							//判断素数
	unsigned int answer, i, k = sqrt(a);
	if (a == 1) {
		answer = 0;
	}
	else {
		for (i = 2; i <= k; i++)
		{
			if (a % i == 0) break;
		}
		if (i <= k) answer = 0;
		else answer = 1;
	}
	return answer;
}