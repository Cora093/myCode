#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("***********************\n");
	printf("*                     *\n");
	printf("*                     *\n");
	printf("*     ��������Ϸ      *\n");
	printf("*     1.��ʼ��Ϸ      *\n");
	printf("*     0.�˳���Ϸ      *\n");
	printf("*                     *\n");
	printf("*                     *\n");
	printf("***********************\n");
	printf("��ѡ��:");
}

void game() {
	char board[hang][lie];
	//��ʼ������
	init_board(board);
	//��ʾ����
	disp_board(board);
	while(1) {
		//�����
		player_move(board);
		disp_board(board);
		if (is_win(board) != 'C') {
			break;
		}
		//������
		computer_move(board);
		disp_board(board);
		if (is_win(board) != 'C') {
			break;
		}
	}
	switch (is_win(board))
	{
	case'=':printf("ƽ��\n");
		break;
	case'X':printf("����Ӯ��\n");
		break;
	case'O':printf("��ϲ�����Ӯ�ˣ�\n");
		break;
	default:
		break;
	}
	printf("��Ϸ����\n");
}

int main() {
	int input;
	while (1) {
		//�˵�
		menu();
		scanf("%d", &input);
		//�ж��û�����
		if (input == 1) {
			printf("\n��Ϸ��ʼ���������\n");
			game();
		}
		else if (input == 0) {
			printf("\n��Ϸ����\n");
			break;
		}
		else {
			printf("\n����������������룡\n");
		}
	}
	return 0;
}