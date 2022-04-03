#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

void Menu(){
	printf("*********************************\n");
	printf("	旅馆信息管理程序\n");
	printf("*********************************\n");
	printf("	1.查看旅店信息\n");
	printf("	2.查看某一房间信息\n");
	printf("	3.查看旅客信息\n");
	printf("	4.查找某一旅客信息\n");
	printf("	5.旅客入住\n");
	printf("	6.旅客退房\n");
	printf("	7.旅客换房\n");
	printf("	8.添加房间\n");
	printf("	9.修改房间信息\n");
	printf("	0.退出\n");
	printf("*********************************\n");
	printf("请选择：");
}

int main()
{
	int playerimport = 0;
	while (1) {
		load();
		Menu();
		scanf("%d", &playerimport);
		printf("\n");
		switch (playerimport)
		{
		case 1: 
			HotelInformation();
			break;
		case 2: 
			RoomsInformation();
			break;
		case 3: 
			AllplayersInformation();
			break;
		case 4: 
			PlayersInformation();
			break;
		case 5: 
			Checkin();
			break;
		case 6: 
			Checkout();
			break;
		case 7: 
			RoomExchange();
			break;
		case 8:
			AddRooms();
			break;
		case 9:
			ModifyRooms();
			break;
		case 0: 
			printf("退出系统\n"); 
			break;
		default: 
			printf("错误输入，请重新输入!!!\n");
			break;
		}
		if (playerimport == 0) {
			break;
		}
		printf("\n");
		save();
	}
	return 0;
}