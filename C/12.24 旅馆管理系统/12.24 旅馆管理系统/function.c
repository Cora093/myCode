#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

extern struct RoomCase* head = NULL;

//功能1.查看旅店信息：列举每个房间的房间号、房间类型、入住人数和房间价格
void HotelInformation() {
	printf("---------------------查看旅店信息----------------------\n");
	struct RoomCase* p = NULL;
	p = head;
	int count = 0;
	if (head == NULL) { //无房间输入时
		printf("现无房间信息\n");
	}
	else
	{
		while (p)
		{
			//printf("房间：%d\n", p1->room.roomnum);
			if (p->Nums == 0) {
				print_room(p);//输出房间信息
				printf("房间为空\n");
				count++;
			}
			else {
				if (p->Nums > 0) {
					print_room(p);//输出房间信息
					print_guests(p, 0);//输出旅客1信息
				}
				if (p->Nums > 1) {
					print_guests(p, 1);//输出旅客2信息
				}
				print_cost(p);//输出房费信息
			}
			printf("\n");
			printf("-------------------------------------------------------\n");
			p = p->next;
		}
		printf("可用房间数为：%d\n", count);
		printf("-------------------------------------------------------\n");
	}
	p = NULL;
	system("pause");
}

//功能2.查看某一房间信息：通过房间号查找，显示指定房间的旅客的信息，包括姓名、身份证号、性别和入住时间
void RoomsInformation() {
	int roomnum = 0;
	struct RoomCase* p = NULL;
	printf("------查看房间信息------\n");
	if (head == NULL) {
		printf("请先添加房间\n");
	}
	else {
		printf("请输入房间号：");
		scanf("%d", &roomnum);//用户输入房间号
		for (p = head;; p = p->next) {
			if (p == NULL) {
				printf("输入了错误的房间号\n");
				rewind(stdin);
				break;
			}
			if (roomnum == p->room.roomnum) {//依次查找房间号并输出
				//先判断房间是否为空
				if (p->Nums == 0) {
					printf("\n房间状态：无旅客入住\n房型：%s\n价格：%.2f元/每晚\n", p->room.roomtype, p->room.roomprice);
				}
					//先输出第一位旅客信息
				if (p->Nums > 0) {
					print_room(p);//输出房间信息
					printf("\n入住时间：%d天\n应付房费：%.2f\n", calctime(p->time_checkin), (calctime(p->time_checkin)) * p->room.roomprice);
					print_guests(p, 0);
				}
				//判断是否输出第二位旅客信息
				if (p->Nums > 1) {
					print_guests(p, 1);
				}
				break;
			}
		}
	}
	system("pause");
}

//功能3.查看旅客信息：显示在旅馆的旅客总数；列举在旅馆的所有旅客的信息，包括姓名、性别、身份证号、房间号、入住时间
void AllplayersInformation() {
	printf("------查看所有旅客信息------\n");
	struct RoomCase* p1;
	p1 = head;
	if (head == NULL) {
		printf("现无旅客信息\n");
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

//功能4.查看某一旅客信息：查看指定旅客的信息，包括姓名、性别、身份证号、房间号、入住时间
void PlayersInformation() {
	printf("------查看旅客信息------\n");
	struct RoomCase* p = NULL;
	if (head == NULL) {//若无房间信息
		printf("请先创建房间\n");
	}
	else {//若有房间信息
		int input = 0;
		//功能选择
	input2:
		printf("输入1搜索姓名，输入2搜索身份证号\n");
		printf("请输入：");
		scanf("%d", &input);
		if (input == 1) {//功能1
			char name[50] = { 0 };
			printf("请输入旅客姓名：");
			scanf("%s", &name);//用户输入旅客姓名
			for (p = head;; p = p->next) {//依次查找旅客姓名
				if (p == NULL) {
					printf("输入了错误的旅客姓名\n");
					break;
				}
				if (0 == strcmp(name, p->guests[0].name)) {//旅客1
					//输出旅客信息
					printf("房间号：%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
				if (0 == strcmp(name, p->guests[1].name)) {//旅客2
					//输出旅客信息
					printf("房间号：%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
			}
		}
		else if (input == 2) {//功能2
			char id[18] = { 0 };
			printf("请输入旅客身份证号码：");
			scanf("%s", &id);//用户输入旅客身份证
			for (p = head;; p = p->next) {//依次查找旅客身份证并输出
				if (p == NULL) {
					printf("输入了错误的旅客身份证号码\n");
					break;
				}
				if (0 == strcmp(id, p->guests[0].id)) {//旅客1
					//输出旅客信息
					printf("房间号：%d\n", p->room.roomnum);
					print_guests(p, 0);
					break;
				}
				if (0 == strcmp(id, p->guests[1].id)) {//旅客2
					//输出旅客信息
					printf("房间号：%d\n", p->room.roomnum);
					print_guests(p, 1);
					break;
				}
			}
		}
		else {//若输入错误
			printf("输入错误，请重新输入\n");
			rewind(stdin);//清空缓冲区
			goto input2;
		}
	}
	system("pause");
}
	
//功能5.旅客入住：录入旅客的身份证号、姓名、性别等信息(程序将获取当前时间作为入住时间)
void Checkin(){
	printf("------旅客入住------\n");
	int input = 0, num = 0;
	struct RoomCase* p1 = NULL;
	//若无房间信息
	if (head == NULL) {				
		printf("请先添加房间\n");
	}
	//若有房间信息
	else {							
		printf("请输入入住房间号：");
		scanf("%d", &num);
		rewind(stdin);
		for (p1 = head; p1 != NULL; p1 = p1->next) {//搜索房间号
			if (num == p1->room.roomnum) {
				break;
			}
		}
		//若搜索不到房间号
		if (p1 == NULL) {
			printf("未添加该房间，请先添加房间\n");
		}
		//若搜索到房间号
		else {
			if (p1->Nums != 0) {//如果已经有人
				printf("房间已经有人\n");
			}
			else {
			input1:
				printf("请输入入住人数(1-2)：");//判断几人入住
				scanf("%d", &input);
				//若输入错误 
				if (input != 1 && input != 2) {
					printf("输入错误,请重新输入\n");
					goto input1;
				}
				//若输入正确
				else {//录入信息
					p1->time_checkin = time(NULL);
					p1->Nums = input;//房间人数
					printf("请输入旅客1名字:");
					scanf("%s", &p1->guests[0].name);
					printf("请输入旅客1身份证号码:");
					scanf("%s", &p1->guests[0].id);
					printf("请输入旅客1性别(男/女):");
					scanf("%s", &p1->guests[0].sex);
					if (input == 2) {
						printf("请输入旅客2名字:");
						scanf("%s", &p1->guests[1].name);
						printf("请输入旅客2身份证号码:");
						scanf("%s", &p1->guests[1].id);
						printf("请输入旅客2性别(男/女):");
						scanf("%s", &p1->guests[1].sex);
						printf("正在录入...\n");
						printf("录入成功\n");
					}
				}
			}
		}
	}	
}

//功能6.旅客退房：（程序获取当前时间作为退房时间，并结合入住时间结算房费。）
//将旅客信息从程序的链表中删除，更改相关房间的信息（将旅客信息添加到旅客历史信息的文档中）

void Checkout() {
	printf("------旅客退房------\n");
	struct RoomCase* p = NULL;
	int num = 0;
	//若无房间信息
	if (head == NULL) {
		printf("请先添加房间\n");
	}
	//若有房间信息
	else {
		printf("请输入退房房间号：");
		scanf("%d", &num);
		for (p = head; p != NULL; p = p->next) {//搜索房间号
			if (num == p->room.roomnum) {
				break;
			}
		}
		//若搜索不到房间号
		if (p == NULL) {
			printf("未添加该房间，请先添加房间\n");
		}
		else {//若搜索到房间号
			if (p->Nums == 0) {//若无旅客入住
				printf("没有旅客入住\n");
			}
			else {
				printf("\n房间号：%d\n",num);
				print_cost(p);//输出费用信息
				InitRooms(p);//初始化旅客信息
				printf("正在退房...\n");
				printf("退房成功\n");
			}
		}
	}
	system("pause");
}

//功能7.旅客换房：通过身份证号识别旅客（结算旅客已产生的房费），修改有关的旅客和房间信息
void RoomExchange() {
	printf("------旅客换房------\n");
	int a, d, c = 0;
	if (head == NULL)
	{
		printf("错误");
		rewind(stdin);
	}
	else {
	input:
		printf("请输入换房旅客房间号: \n");
		scanf("%d", &a);
		printf("请输入目标房间号: \n");
		scanf("%d", &d);
		if (a == d) { printf("输入错误\n"); rewind(stdin); goto input; }//输入相同房间号时 返回输入
		struct RoomCase* p1 = NULL, * p2 = NULL, change;
		p1 = head;
		p2 = head;
		while (p1->room.roomnum != a)
		{
			if (p1->next == NULL) { printf("原房间不存在\n"); rewind(stdin); goto input; }//当遍历房间 也未找到原房间时用goto返回
			p1 = p1->next;
		}
		while (p2->room.roomnum != d)
		{
			if (p2->next == NULL) { printf("目标房间不存在\n"); rewind(stdin); goto input; }//当遍历房间 也未找到目标房间时用goto返回
			p2 = p2->next;
		}
		if (p2 != NULL) c = 1;
		if (c == 0) printf("请先创建房间");
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
	printf("换房成功\n");
	system("pause");
}

//功能8.添加房间：新建一个房间，添加房间类型，房间价格等信息
void AddRooms() {
	printf("------添加房间------\n");
	struct RoomCase* p = NULL, * p1 = NULL;
	p1 = head;
	if (p1 == NULL) {//若无信息
		p = malloc(LEN);//开辟内存空间
		p->next = NULL;//链表尾置空
		head = p;//p作为链表头
	}
	else {//若有信息
		while (p1->next != NULL) {//找到链表尾
			p1 = p1->next;
		}
		p = malloc(LEN);//开辟内存空间
		p1->next = p;//连接链表
		p->next = NULL;//链表尾置空
	}
	InitRooms(p);//初始化旅客信息
	printf("请输入要添加的房间号:");
	scanf("%d", &p->room.roomnum);
	printf("请输入房间类型:");
	scanf("%s", p->room.roomtype);
flag:
	printf("请输入房间价格（每晚）:");
	scanf("%f", &p->room.roomprice);
	if (p->room.roomprice < 0 || p->room.roomprice>99999) {//输错则重新输入
		printf("输入错误，请重新输入\n");
		rewind(stdin);
		goto flag;
	}
	printf("正在添加...\n");
	printf("添加成功\n");
}


//功能9：修改房间信息：通过房间号查找房间，并修改房间信息或删除房间
void ModifyRooms() {
	printf("------修改房间信息------\n");
	struct RoomCase* p = NULL;
	int num = 0;
	//若无房间信息
	if (head == NULL) {
		printf("请先添加房间\n");
	}
	//若有房间信息
	else {
		printf("请输入要修改的房间号：");
		scanf("%d", &num);
		for (p = head; p != NULL; p = p->next) {//搜索房间号
			if (num == p->room.roomnum) {
				break;
			}
		}
		//若搜索不到房间号
		if (p == NULL) {
			printf("\n未添加该房间，请先添加房间\n");
		}
		//若搜索到房间号
		else {
		flag:
			printf("\n输入1修改旅客信息，输入2修改房间信息\n");
			printf("请输入：");
			int input = 0;
			scanf("%d", &input);
			if (input == 1) {//修改旅客信息
				if (p->Nums == 0) {//若无人入住
					printf("\n此房间无旅客入住\n");
				}
				else {//若有人入住
					print_guests(p, 0);
					if (p->Nums == 2) {//若有两人入住
						print_guests(p, 1);
					flag1:
						printf("\n输入1修改第一位旅客信息，输入2修改第二位旅客信息\n");
						printf("请输入：");
						scanf("%d", &input);//选择修改哪一位旅客的信息
						if (input != 1 && input != 2) {//若输入错误
							printf("输入错误，请重新输入！");
							rewind(stdin);
							goto flag1;
						}
					}
					modify_guests_imformation(p, input-1);
					print_guests(p, 0);
					if (p->Nums == 2) {//若有两人入住
						print_guests(p, 1);
					}
				}
			}
			else if (input == 2) {//修改房间信息
				print_room(p);
				modify_room_imformation(p);
				print_room(p);
			}
			else {
				printf("输入错误，请重新输入\n");
				rewind(stdin);
				goto flag;
			}
		}
	}
}