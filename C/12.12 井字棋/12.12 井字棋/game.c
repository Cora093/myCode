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
		printf("\n�ֵ����\n");
		printf("�����ʽΪ��a,b��\n");
		printf("����������:");
		gets();
		scanf("%d,%d", &i, &j);
		//�ж��Ƿ�ռ��
		if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
			board[i - 1][j - 1] = 'O';
			break;
		}
		else {
			printf("\n����������������룡\n");
			disp_board(board);
			continue;
		}
	}
}

void computer_move(char board[hang][lie]) {
	printf("\n�ֵ�����\n");
	int i=2, j=2;//�м�
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 2;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 2; j = 1;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 2; j = 3;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 2;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 3;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 1;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 1; j = 3;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
	i = 3; j = 1;//����
	if (1 <= i && i <= hang && 1 <= j && j <= lie && board[i - 1][j - 1] == ' ') {
		board[i - 1][j - 1] = 'X';
		goto end;
	}
end:;
}

char is_win(char board[hang][lie]) {
	int i, j;
	char c;
	//1.�ж��Ƿ�����Ӯ������'X'��'O'
	
	//1.1:������ͬ
	for (i = 0; i < hang; i++) {
		if (board[i][0] != ' ') {					//�����ײ�Ϊ��
			c = board[i][0];						
			for (j = 1; j < lie; j++) {				
				if (board[i][j] == c) {
					if (j == (lie - 1)) {			//��һ��Ԫ����ͬ
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

	//1.2:������ͬ
	for (j = 0; j < lie; j++) {
		if (board[0][j] != ' ') {					//�����ײ�Ϊ��
			c = board[0][j];
			for (i = 1; i < hang; i++) {
				if (board[i][j] == c) {
					if (i == (hang - 1)) {			//��һ��Ԫ����ͬ
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

	//1.3:��б����ͬ
	c = board[1][1];
	if (c != ' ' && c == board[0][0] && c == board[2][2]) {
		return c;
	}
	if (c != ' ' && c == board[0][2] && c == board[2][0]) {
		return c;
	}
	
	//2.�������δ����������������'C'
	for (i = 0; i < hang; i++) {
		for (j = 0; j < lie; j++) {
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}

	//3.�������������ƽ�֣�����'='
	return '=';


}
