#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

//从文件加载数据到链表中
void load() {
	int n = 0;
	struct RoomCase* p1 = NULL, * p2 = NULL;
	FILE* pf = NULL;//文件指针
	p1 = p2 = malloc(LEN);//开辟新内存空间
	p1->next = NULL;//链表尾置空
	pf = fopen("HotelInformation.dat", "rb");//若有文件，打开文件（二进制读）
	if (pf == NULL) {
		pf = fopen("HotelInformation.dat", "wb+"); //若没有文件，创建新文件
	}

	head = p1;//链表头
	p1->next = NULL;
	for (n = 1;; n++) {
		if (!fread(p1, LEN, 1, pf)) {//读取完文件，跳出
			break;
		}
		p2 = p1;//p2后移
		p1 = malloc(LEN);//p1后移，开辟新内存空间
		p1->next = NULL;//链表尾置空
		p2->next = p1;//连接链表
	}

	if (n == 1) {//若是空文件，head置空
		free(p1);
		head = NULL;
	}
	else {//若不是空文件
		p2->next = NULL;
		free(p1);//释放多余内存空间
		p1 = NULL;
	}

	fclose(pf);//关闭文件
	pf = NULL;
}

//从链表中保存数据到文件
void save() {
	FILE* pf = NULL;//文件指针
	struct RoomCase* p = NULL;
	p = head;
	pf = fopen("HotelInformation.dat", "wb");//打开文件（二进制读）
	if (pf == NULL) {//打开失败则报错
		perror("fopen");
	}
	if (p != NULL) {//若head不为空，有数据
		fwrite(p, LEN, 1, pf);//将第一个结构体的数据写入文件
		while (p->next != NULL) {//若链表还没结束
			p = p->next;//指针后移
			fwrite(p, LEN, 1, pf);//将链表数据写入文件
		}
	}
	fclose(pf);//关闭文件
	pf = NULL;
}


void InitRooms(struct RoomCase* p) {//初始化旅客信息
	p->Nums = 0;
	p->guests[0].name[0] = '\0';
	p->guests[0].id[0] = '\0';
	p->guests[0].sex[0] = '\0';
	p->guests[1].name[0] = '\0';
	p->guests[1].id[0] = '\0';
	p->guests[1].sex[0] = '\0';

}

int calctime(time_t time_checkin) {//计算入住至今的时间(天）
	return (int)((time(NULL) - time_checkin) / 86400 + 1);
}

void print_guests(struct RoomCase* p,int n) {//输出旅客信息
	printf("\n姓名：%s    身份证号：%s    性别：%s    入住时间：%d天\n"
		,p->guests[n].name, p->guests[n].id, p->guests[n].sex, calctime(p->time_checkin));
}

void print_room(struct RoomCase* p) {//输出房间信息
	printf("\n房间号：%d    房型：%s    价格：%.2f元/每晚\n"
		, p->room.roomnum, p->room.roomtype, p->room.roomprice);

}

void modify_guests_imformation(struct RoomCase* p, int n) {//修改旅客信息
	int input = 0;
flag:
	printf("输入1修改旅客姓名，输入2修改旅客身份证号码，输入3修改旅客性别\n");
	printf("请输入：");
	scanf("%d", &input);
	if (input == 1) {//修改旅客姓名
		printf("修改为：");
		scanf("%s", &p->guests[n].name);
	}
	else if (input == 2) {//修改旅客身份证号码
		printf("修改为：");
		scanf("%s", &p->guests[n].id);
	}
	else if (input == 3) {//修改旅客性别
		printf("修改为：");
		scanf("%s", &p->guests[n].sex);
	}
	else {
		printf("输入错误，请重新输入！\n");
		rewind(stdin);
		goto flag;
	}
	printf("正在修改...\n");
	printf("修改成功\n");
}


void modify_room_imformation(struct RoomCase* p) {//修改房间信息
	int input = 0;
flag:
	printf("输入1修改房间类型，输入2修改房间价格\n");
	printf("请输入：");
	scanf("%d", &input);
	if (input == 1) {//修改房间类型
		printf("修改为：");
		scanf("%s", &p->room.roomtype);
	}
	else if (input == 2) {//修改房间价格
		printf("修改为：");
		scanf("%f", &p->room.roomprice);
	}
	else {
		printf("输入错误，请重新输入！\n");
		rewind(stdin);
		goto flag;
	}
	printf("正在修改...\n");
	printf("修改成功\n");
}

void print_cost(struct RoomCase* p) {//输出房费信息
	float cost = (calctime(p->time_checkin) * p->room.roomprice);
	printf("\n房费为：%.2f\n", cost);
}