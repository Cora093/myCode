#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

void Menu(){
	printf("*********************************\n");
	printf("	�ù���Ϣ�������\n");
	printf("*********************************\n");
	printf("	1.�鿴�õ���Ϣ\n");
	printf("	2.�鿴ĳһ������Ϣ\n");
	printf("	3.�鿴�ÿ���Ϣ\n");
	printf("	4.����ĳһ�ÿ���Ϣ\n");
	printf("	5.�ÿ���ס\n");
	printf("	6.�ÿ��˷�\n");
	printf("	7.�ÿͻ���\n");
	printf("	8.��ӷ���\n");
	printf("	9.�޸ķ�����Ϣ\n");
	printf("	0.�˳�\n");
	printf("*********************************\n");
	printf("��ѡ��");
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
			printf("�˳�ϵͳ\n"); 
			break;
		default: 
			printf("�������룬����������!!!\n");
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