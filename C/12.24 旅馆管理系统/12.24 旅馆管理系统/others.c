#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

//���ļ��������ݵ�������
void load() {
	int n = 0;
	struct RoomCase* p1 = NULL, * p2 = NULL;
	FILE* pf = NULL;//�ļ�ָ��
	p1 = p2 = malloc(LEN);//�������ڴ�ռ�
	p1->next = NULL;//����β�ÿ�
	pf = fopen("HotelInformation.dat", "rb");//�����ļ������ļ��������ƶ���
	if (pf == NULL) {
		pf = fopen("HotelInformation.dat", "wb+"); //��û���ļ����������ļ�
	}

	head = p1;//����ͷ
	p1->next = NULL;
	for (n = 1;; n++) {
		if (!fread(p1, LEN, 1, pf)) {//��ȡ���ļ�������
			break;
		}
		p2 = p1;//p2����
		p1 = malloc(LEN);//p1���ƣ��������ڴ�ռ�
		p1->next = NULL;//����β�ÿ�
		p2->next = p1;//��������
	}

	if (n == 1) {//���ǿ��ļ���head�ÿ�
		free(p1);
		head = NULL;
	}
	else {//�����ǿ��ļ�
		p2->next = NULL;
		free(p1);//�ͷŶ����ڴ�ռ�
		p1 = NULL;
	}

	fclose(pf);//�ر��ļ�
	pf = NULL;
}

//�������б������ݵ��ļ�
void save() {
	FILE* pf = NULL;//�ļ�ָ��
	struct RoomCase* p = NULL;
	p = head;
	pf = fopen("HotelInformation.dat", "wb");//���ļ��������ƶ���
	if (pf == NULL) {//��ʧ���򱨴�
		perror("fopen");
	}
	if (p != NULL) {//��head��Ϊ�գ�������
		fwrite(p, LEN, 1, pf);//����һ���ṹ�������д���ļ�
		while (p->next != NULL) {//������û����
			p = p->next;//ָ�����
			fwrite(p, LEN, 1, pf);//����������д���ļ�
		}
	}
	fclose(pf);//�ر��ļ�
	pf = NULL;
}


void InitRooms(struct RoomCase* p) {//��ʼ���ÿ���Ϣ
	p->Nums = 0;
	p->guests[0].name[0] = '\0';
	p->guests[0].id[0] = '\0';
	p->guests[0].sex[0] = '\0';
	p->guests[1].name[0] = '\0';
	p->guests[1].id[0] = '\0';
	p->guests[1].sex[0] = '\0';

}

int calctime(time_t time_checkin) {//������ס�����ʱ��(�죩
	return (int)((time(NULL) - time_checkin) / 86400 + 1);
}

void print_guests(struct RoomCase* p,int n) {//����ÿ���Ϣ
	printf("\n������%s    ���֤�ţ�%s    �Ա�%s    ��סʱ�䣺%d��\n"
		,p->guests[n].name, p->guests[n].id, p->guests[n].sex, calctime(p->time_checkin));
}

void print_room(struct RoomCase* p) {//���������Ϣ
	printf("\n����ţ�%d    ���ͣ�%s    �۸�%.2fԪ/ÿ��\n"
		, p->room.roomnum, p->room.roomtype, p->room.roomprice);

}

void modify_guests_imformation(struct RoomCase* p, int n) {//�޸��ÿ���Ϣ
	int input = 0;
flag:
	printf("����1�޸��ÿ�����������2�޸��ÿ����֤���룬����3�޸��ÿ��Ա�\n");
	printf("�����룺");
	scanf("%d", &input);
	if (input == 1) {//�޸��ÿ�����
		printf("�޸�Ϊ��");
		scanf("%s", &p->guests[n].name);
	}
	else if (input == 2) {//�޸��ÿ����֤����
		printf("�޸�Ϊ��");
		scanf("%s", &p->guests[n].id);
	}
	else if (input == 3) {//�޸��ÿ��Ա�
		printf("�޸�Ϊ��");
		scanf("%s", &p->guests[n].sex);
	}
	else {
		printf("����������������룡\n");
		rewind(stdin);
		goto flag;
	}
	printf("�����޸�...\n");
	printf("�޸ĳɹ�\n");
}


void modify_room_imformation(struct RoomCase* p) {//�޸ķ�����Ϣ
	int input = 0;
flag:
	printf("����1�޸ķ������ͣ�����2�޸ķ���۸�\n");
	printf("�����룺");
	scanf("%d", &input);
	if (input == 1) {//�޸ķ�������
		printf("�޸�Ϊ��");
		scanf("%s", &p->room.roomtype);
	}
	else if (input == 2) {//�޸ķ���۸�
		printf("�޸�Ϊ��");
		scanf("%f", &p->room.roomprice);
	}
	else {
		printf("����������������룡\n");
		rewind(stdin);
		goto flag;
	}
	printf("�����޸�...\n");
	printf("�޸ĳɹ�\n");
}

void print_cost(struct RoomCase* p) {//���������Ϣ
	float cost = (calctime(p->time_checkin) * p->room.roomprice);
	printf("\n����Ϊ��%.2f\n", cost);
}