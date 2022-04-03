#define _CRT_SECURE_NO_WARNINGS 1
//将一笔零钱换成5分、2分和1分的硬币，要求每种硬币至少有一枚，有几种不同的换法？
//输入在一行中给出待换的零钱数额x∈(8, 100)。
//每行输出一种换法，格式为：“fen5:5分硬币数量, fen2:2分硬币数量,fen1:1分硬币数量,total:硬币总数量”
//最后一行输出“count = 换法个数”。

#include <stdio.h>

void coin(int money) {
	int count = 0;
	int i = 0, j = 0, k = 0;
	money -= 8;												//必须的521除外
	for (i = money / 5; i >= 0; i--) {						//五分的数量
		for (j = (money - i * 5) / 2; j >= 0; j--) {		//二分的数量
			k = money - 5 * i - 2 * j;						//一分的数量
			printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i + 1, j + 1, k + 1, i + j + k + 3);
			count++;
		}
	}
	printf("count = %d", count);
}

int main() {
	void coin(int);
	int money = 0;
	scanf("%d", &money);
	coin(money);
	return 0;
}
