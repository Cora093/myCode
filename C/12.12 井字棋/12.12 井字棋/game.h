#pragma once


#include <stdio.h>


#define hang 3
#define lie 3

void menu();
void game();
void init_board(char board[hang][lie]);
void disp_board(char board[hang][lie]);
void player_move(char board[hang][lie]);
void computer_move(char board[hang][lie]);
char is_win(char board[hang][lie]);


