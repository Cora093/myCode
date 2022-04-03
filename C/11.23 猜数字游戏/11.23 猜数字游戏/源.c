#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(){
	int n, time, i ,num;
	scanf("%d%d", &n, &time);
	for (i = 1; i <= time; i++) {
		scanf("%d", &num);
		if (num < 0) {
			i = time + 1;
			break;
		}
		if (num > n)			printf("Too big\n");
		if (num < n)			printf("Too small\n");
		if (num == n)			break;
	}
	if (i <= time) {
		if (i == 1)				printf("Bingo!");
		if (i == 2 || i == 3)	printf("Lucky You!");
		if (i > 3)				printf("Good Guess!");
	}
	else printf("Game Over");
	return 0;
}

