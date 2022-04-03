#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

extern struct RoomCase* head = NULL;

//����1.�鿴�õ���Ϣ���о�ÿ������ķ���š��������͡���ס�����ͷ���۸�
void HotelInformation() {
	printf("---------------------�鿴�õ���Ϣ----------------------\n");
	struct RoomCase* p = NULL;
	p = head;
	int count = 0;
	if (head == NULL) { //�޷�������ʱ
		printf("���޷�����Ϣ\n");
	}
	else
	{
		while (p)
		{
			//printf("���䣺%d\n", p1->room.roomnum);
			if (p->Nums == 0) {
				print_room(p);//���������Ϣ
				printf("����Ϊ��\n");
				count++;
			}
			else {
				if (p->Nums > 0) {
					print_room(p);//���������Ϣ
					print_guests(p, 0);//����ÿ�1��Ϣ
				}
				if (p->Nums > 1) {
					print_guests(p, 1);//����ÿ�2��Ϣ
				}
				print_cost(p);//���������Ϣ
			}
			printf("\n");
			printf("-------------------------------------------------------\n");
			p = p->next;
		}
		printf("���÷�����Ϊ��%d\n", count);
		printf("-------------------------------------------------------\n");
	}
	p = NULL;
	system("pause");
}

//����2.�鿴ĳһ������Ϣ��ͨ������Ų��ң���ʾָ��������ÿ͵���Ϣ���������������֤�š��Ա����סʱ��
void RoomsInformation() {
	int roomnum = 0;
	struct RoomCase* p = NULL;
	printf("------�鿴������Ϣ------\n");
	if (head == NULL) {
		printf("������ӷ���\n");
	}
	else {
		printf("�����뷿��ţ�");
		scanf("%d", &roomnum);//�û����뷿���
		for (p = head;; p = p->next) {
			if (p == NULL) {
				printf("�����˴���ķ����\n");
				rewind(stdin);
				break;
			}
			if (roomnum == p->room.roomnum) {//���β��ҷ���Ų����
				//���жϷ����Ƿ�Ϊ��
				if (p->Nums == 0) {
					printf("\n����״̬�����ÿ���ס\n���ͣ�%s\n�۸�%.2fԪ/ÿ��\n", p->room.roomtype, p->room.roomprice);
				}
					//�������һλ�ÿ���Ϣ
				if (p->Nums > 0) {
					print_room(p);//���������Ϣ
					printf("\n��סʱ�䣺%d��\nӦ�����ѣ�%.2f\n", calctime(p->time_checkin), (calctime(p->time_checkin)) * p->room.roomprice);
					print_guests(p, 0);
				}
				//�ж��Ƿ�����ڶ�λ�ÿ���Ϣ
				if (p->Nums > 1) {
					print_guests(p, 1);
				}
				break;
			}
		}
	}
	system("pause");
}

//����3.�鿴�ÿ���Ϣ����ʾ���ùݵ��ÿ��������о����ùݵ������ÿ͵���Ϣ�������������Ա����֤�š�����š���סʱ��
void AllplayersInformation() {
	printf("------�鿴�����ÿ���Ϣ------\n");
	struct RoomCase* p1;
	p1 = head;
	if (head == NULL) {
		printf("�����ÿ���Ϣ\n");
	}
	else {
		while (p1 != NULL) {
			if (p1->Nums > 0) {
				print_guests(p1, 0);
			}
				
			if (p1->Nums > 1) {
				print_guests(p1, 1);
			}
			p1 = p1->next;
		}
	}
	p1 = NULL;
	system("pause");
}

//����4.�鿴ĳһ�ÿ���Ϣ���鿴ָ���ÿ͵���Ϣ�������������Ա����֤�š�����š���סʱ��
void PlayersInformation() {
	printf("------�鿴�ÿ���Ϣ------\n");
	struct RoomCase* p = NULL;
	if (head == NULL) {//���޷�����Ϣ
		printf("���ȴ�������\n");
	}
	else {//���з�����Ϣ
		int input = 0;
		//����ѡ��
	input2:
		printf("����1��������������2�������֤��\n");
		printf("�����룺");
		scanf("%d", &input);
		if (input == 1) {//����1
			char name[50] = { 0 };
			printf("�������ÿ�������");
			scanf("%s", &name);//�û������ÿ�����
			for (p = head;; p = p->next) {//���β����ÿ�����
				if (p == NULL) {
					printf("�����˴�����ÿ�����\n");
					break;
				}
				if (0 == strcmp(name, p->guests[0].name)) {//�ÿ�1
					//����ÿ���Ϣ
					printf("����ţ�%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
				if (0 == strcmp(name, p->guests[1].name)) {//�ÿ�2
					//����ÿ���Ϣ
					printf("����ţ�%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
			}
		}
		else if (input == 2) {//����2
			char id[18] = { 0 };
			printf("�������ÿ����֤���룺");
			scanf("%s", &id);//�û������ÿ����֤
			for (p = head;; p = p->next) {//���β����ÿ����֤�����
				if (p == NULL) {
					printf("�����˴�����ÿ����֤����\n");
					break;
				}
				if (0 == strcmp(id, p->guests[0].id)) {//�ÿ�1
					//����ÿ���Ϣ
					printf("����ţ�%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
				if (0 == strcmp(id, p->guests[1].id)) {//�ÿ�2
					//����ÿ���Ϣ
					printf("����ţ�%d\n", p->room.roomnum);
					print_guests(p, 1);
					break;
				}
			}
		}
		else {//���������
			printf("�����������������\n");
			rewind(stdin);//��ջ�����
			goto input2;
		}
	}
	system("pause");
}
	
//����5.�ÿ���ס��¼���ÿ͵����֤�š��������Ա����Ϣ(���򽫻�ȡ��ǰʱ����Ϊ��סʱ��)
void Checkin(){
	printf("------�ÿ���ס------\n");
	int input = 0, num = 0;
	struct RoomCase* p1 = NULL;
	//���޷�����Ϣ
	if (head == NULL) {				
		printf("������ӷ���\n");
	}
	//���з�����Ϣ
	else {							
		printf("��������ס����ţ�");
		scanf("%d", &num);
		rewind(stdin);
		for (p1 = head; p1 != NULL; p1 = p1->next) {//���������
			if (num == p1->room.roomnum) {
				break;
			}
		}
		//���������������
		if (p1 == NULL) {
			printf("δ��Ӹ÷��䣬������ӷ���\n");
		}
		//�������������
		else {
			if (p1->Nums != 0) {//����Ѿ�����
				printf("�����Ѿ�����\n");
			}
			else {
			input1:
				printf("��������ס����(1-2)��");//�жϼ�����ס
				scanf("%d", &input);
				//��������� 
				if (input != 1 && input != 2) {
					printf("�������,����������\n");
					goto input1;
				}
				//��������ȷ
				else {//¼����Ϣ
					p1->time_checkin = time(NULL);
					p1->Nums = input;//��������
					printf("�������ÿ�1����:");
					scanf("%s", &p1->guests[0].name);
					printf("�������ÿ�1���֤����:");
					scanf("%s", &p1->guests[0].id);
					printf("�������ÿ�1�Ա�(��/Ů):");
					scanf("%s", &p1->guests[0].sex);
					if (input == 2) {
						printf("�������ÿ�2����:");
						scanf("%s", &p1->guests[1].name);
						printf("�������ÿ�2���֤����:");
						scanf("%s", &p1->guests[1].id);
						printf("�������ÿ�2�Ա�(��/Ů):");
						scanf("%s", &p1->guests[1].sex);
						printf("����¼��...\n");
						printf("¼��ɹ�\n");
					}
				}
			}
		}
	}	
}

//����6.�ÿ��˷����������ȡ��ǰʱ����Ϊ�˷�ʱ�䣬�������סʱ����㷿�ѡ���
//���ÿ���Ϣ�ӳ����������ɾ����������ط������Ϣ�����ÿ���Ϣ��ӵ��ÿ���ʷ��Ϣ���ĵ��У�

void Checkout() {
	printf("------�ÿ��˷�------\n");
	struct RoomCase* p = NULL;
	int num = 0;
	//���޷�����Ϣ
	if (head == NULL) {
		printf("������ӷ���\n");
	}
	//���з�����Ϣ
	else {
		printf("�������˷�����ţ�");
		scanf("%d", &num);
		for (p = head; p != NULL; p = p->next) {//���������
			if (num == p->room.roomnum) {
				break;
			}
		}
		//���������������
		if (p == NULL) {
			printf("δ��Ӹ÷��䣬������ӷ���\n");
		}
		else {//�������������
			if (p->Nums == 0) {//�����ÿ���ס
				printf("û���ÿ���ס\n");
			}
			else {
				printf("\n����ţ�%d\n",num);
				print_cost(p);//���������Ϣ
				InitRooms(p);//��ʼ���ÿ���Ϣ
				printf("�����˷�...\n");
				printf("�˷��ɹ�\n");
			}
		}
	}
	system("pause");
}

//����7.�ÿͻ�����ͨ�����֤��ʶ���ÿͣ������ÿ��Ѳ����ķ��ѣ����޸��йص��ÿͺͷ�����Ϣ
void RoomExchange() {
	printf("------�ÿͻ���------\n");
	int a, d, c = 0;
	if (head == NULL)
	{
		printf("����");
		rewind(stdin);
	}
	else {
	input:
		printf("�����뻻���ÿͷ����: \n");
		scanf("%d", &a);
		printf("������Ŀ�귿���: \n");
		scanf("%d", &d);
		if (a == d) { printf("�������\n"); rewind(stdin); goto input; }//������ͬ�����ʱ ��������
		struct RoomCase* p1 = NULL, * p2 = NULL, change;
		p1 = head;
		p2 = head;
		while (p1->room.roomnum != a)
		{
			if (p1->next == NULL) { printf("ԭ���䲻����\n"); rewind(stdin); goto input; }//���������� Ҳδ�ҵ�ԭ����ʱ��goto����
			p1 = p1->next;
		}
		while (p2->room.roomnum != d)
		{
			if (p2->next == NULL) { printf("Ŀ�귿�䲻����\n"); rewind(stdin); goto input; }//���������� Ҳδ�ҵ�Ŀ�귿��ʱ��goto����
			p2 = p2->next;
		}
		if (p2 != NULL) c = 1;
		if (c == 0) printf("���ȴ�������");
		else
		{
			change.room.roomnum = p1->room.roomnum;
			strcpy(change.room.roomtype, p1->room.roomtype);
			change.room.roomprice = p1->room.roomprice;
			p1->room.roomnum = p2->room.roomnum;
			strcpy(p1->room.roomtype, p2->room.roomtype);
			p1->room.roomprice = p2->room.roomprice;
			p2->room.roomnum = change.room.roomnum;
			strcpy(p2->room.roomtype, change.room.roomtype);
			p2->room.roomprice = change.room.roomprice;
		}
		print_cost(p1);
	}
	printf("�����ɹ�\n");
	system("pause");
}

//����8.��ӷ��䣺�½�һ�����䣬��ӷ������ͣ�����۸����Ϣ
void AddRooms() {
	printf("------��ӷ���------\n");
	struct RoomCase* p = NULL, * p1 = NULL;
	p1 = head;
	if (p1 == NULL) {//������Ϣ
		p = malloc(LEN);//�����ڴ�ռ�
		p->next = NULL;//����β�ÿ�
		head = p;//p��Ϊ����ͷ
	}
	else {//������Ϣ
		while (p1->next != NULL) {//�ҵ�����β
			p1 = p1->next;
		}
		p = malloc(LEN);//�����ڴ�ռ�
		p1->next = p;//��������
		p->next = NULL;//����β�ÿ�
	}
	InitRooms(p);//��ʼ���ÿ���Ϣ
	printf("������Ҫ��ӵķ����:");
	scanf("%d", &p->room.roomnum);
	printf("�����뷿������:");
	scanf("%s", p->room.roomtype);
flag:
	printf("�����뷿��۸�ÿ��:");
	scanf("%f", &p->room.roomprice);
	if (p->room.roomprice < 0 || p->room.roomprice>99999) {//�������������
		printf("�����������������\n");
		rewind(stdin);
		goto flag;
	}
	printf("�������...\n");
	printf("��ӳɹ�\n");
}


//����9���޸ķ�����Ϣ��ͨ������Ų��ҷ��䣬���޸ķ�����Ϣ��ɾ������
void ModifyRooms() {
	printf("------�޸ķ�����Ϣ------\n");
	struct RoomCase* p = NULL;
	int num = 0;
	//���޷�����Ϣ
	if (head == NULL) {
		printf("������ӷ���\n");
	}
	//���з�����Ϣ
	else {
		printf("������Ҫ�޸ĵķ���ţ�");
		scanf("%d", &num);
		for (p = head; p != NULL; p = p->next) {//���������
			if (num == p->room.roomnum) {
				break;
			}
		}
		//���������������
		if (p == NULL) {
			printf("\nδ��Ӹ÷��䣬������ӷ���\n");
		}
		//�������������
		else {
		flag:
			printf("\n����1�޸��ÿ���Ϣ������2�޸ķ�����Ϣ\n");
			printf("�����룺");
			int input = 0;
			scanf("%d", &input);
			if (input == 1) {//�޸��ÿ���Ϣ
				if (p->Nums == 0) {//��������ס
					printf("\n�˷������ÿ���ס\n");
				}
				else {//��������ס
					print_guests(p, 0);
					if (p->Nums == 2) {//����������ס
						print_guests(p, 1);
					flag1:
						printf("\n����1�޸ĵ�һλ�ÿ���Ϣ������2�޸ĵڶ�λ�ÿ���Ϣ\n");
						printf("�����룺");
						scanf("%d", &input);//ѡ���޸���һλ�ÿ͵���Ϣ
						if (input != 1 && input != 2) {//���������
							printf("����������������룡");
							rewind(stdin);
							goto flag1;
						}
					}
					modify_guests_imformation(p, input-1);
					print_guests(p, 0);
					if (p->Nums == 2) {//����������ס
						print_guests(p, 1);
					}
				}
			}
			else if (input == 2) {//�޸ķ�����Ϣ
				print_room(p);
				modify_room_imformation(p);
				print_room(p);
			}
			else {
				printf("�����������������\n");
				rewind(stdin);
				goto flag;
			}
		}
	}
}