#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void init_board(char board[hang][lie]) {
	int i, j;
	for (i = 0; i < hang; i++) {
		for (j = 0; j < lie; j++) {
			board[i][j] = ' ';
		}
	}
}

void disp_board(char board[hang][lie]) {
	int i, j;
	for (i = 0; i <= hang; i++) {
		printf(" --- --- --- \n");
		if (i != hang) {
			for (j = 0; j < lie; j++) {
				printf("| %c ", board[i][j]);
			}
			printf("|\n");
		}
	}

}

void player_move(char board[hang][lie]) {
	int i = -1, j = -1;
	while (1) {
		printf("\n轮到玩家\n");
		printf("输入格式为（a,b）\n");
		printf("请输入坐标:");
		gets();
		scanf("%d,%d", &i, &j);
		//判断是否被占用
		if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
			board[i - 1][j - 1] = 'O';
			break;
		}
		else {
			printf("\n输入错误，请重新输入！\n");
			disp_board(board);
			continue;
		}
	}
}

void computer_move(char board[hang][lie]) {
	printf("\n轮到电脑\n");
	int i=2, j=2;//中间
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 2;//中上
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 2; j = 1;//中左
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 2; j = 3;//中右
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 2;//中下
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 3;//右下
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 1;//左上
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 3;//右上
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 1;//左下
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
end:;
}

char is_win(char board[hang][lie]) {
	int i, j;
	char c;
	//1.判断是否有人赢，返回'X'或'O'
	
	//1.1:若行相同
	for (i = 0; i < hang; i++) {
		if (board[i][0] != ' ') {					//若行首不为空
			c = board[i][0];						
			for (j = 1; j < lie; j++) {				
				if (board[i][j] == c) {
					if (j == (lie - 1)) {			//若一行元素相同
						return c;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	//1.2:若列相同
	for (j = 0; j < lie; j++) {
		if (board[0][j] != ' ') {					//若列首不为空
			c = board[0][j];
			for (i = 1; i < hang; i++) {
				if (board[i][j] == c) {
					if (i == (hang - 1)) {			//若一列元素相同
						return c;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	//1.3:若斜线相同
	c = board[1][1];
	if (c != ' ' && c == board[0][0] && c == board[2][2]) {
		return c;
	}
	if (c != ' ' && c == board[0][2] && c == board[2][0]) {
		return c;
	}
	
	//2.如果棋盘未填满，继续，返回'C'
	for (i = 0; i < hang; i++) {
		for (j = 0; j < lie; j++) {
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}

	//3.如果棋盘填满，平局，返回'='
	return '=';


}
