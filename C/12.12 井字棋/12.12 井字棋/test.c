#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("***********************\n");
	printf("*                     *\n");
	printf("*                     *\n");
	printf("*     井字棋游戏      *\n");
	printf("*     1.开始游戏      *\n");
	printf("*     0.退出游戏      *\n");
	printf("*                     *\n");
	printf("*                     *\n");
	printf("***********************\n");
	printf("请选择:");
}

void game() {
	char board[hang][lie];
	//初始化棋盘
	init_board(board);
	//显示棋盘
	disp_board(board);
	while(1) {
		//玩家下
		player_move(board);
		disp_board(board);
		if (is_win(board) != 'C') {
			break;
		}
		//电脑下
		computer_move(board);
		disp_board(board);
		if (is_win(board) != 'C') {
			break;
		}
	}
	switch (is_win(board))
	{
	case'=':printf("平局\n");
		break;
	case'X':printf("电脑赢了\n");
		break;
	case'O':printf("恭喜！玩家赢了！\n");
		break;
	default:
		break;
	}
	printf("游戏结束\n");
}

int main() {
	int input;
	while (1) {
		//菜单
		menu();
		scanf("%d", &input);
		//判断用户输入
		if (input == 1) {
			printf("\n游戏开始，玩家先下\n");
			game();
		}
		else if (input == 0) {
			printf("\n游戏结束\n");
			break;
		}
		else {
			printf("\n输入错误，请重新输入！\n");
		}
	}
	return 0;
}