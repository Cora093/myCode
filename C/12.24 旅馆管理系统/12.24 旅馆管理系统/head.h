
/*
头文件引用
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/*
函数声明
*/

//主函数内功能
void HotelInformation();//功能1.查看旅店信息
void RoomsInformation();//功能2.查看某一房间信息
void AllplayersInformation();//功能3.查看旅客信息
void PlayersInformation();//功能4.查看某一旅客信息
void Checkin();//功能5.旅客入住
void Checkout();//功能6.旅客退房
void RoomExchange();//功能7.旅客换房
void AddRooms();//功能8.添加房间
void ModifyRooms();//功能9.修改房间信息

//其他函数
void load();//从文件加载数据到链表中
void save();//从链表中保存数据到文件
void InitRooms(struct RoomCase* );//初始化旅客信息
int calctime(time_t);//计算入住至今的时间(天）并返回
void print_guests(struct RoomCase* ,int);//输出旅客信息（第一位旅客n==0，第二位n==1)
void print_room(struct RoomCase* );//输出房间信息
void print_cost(struct RoomCase* );//输出房费信息
void modify_guests_imformation(struct RoomCase* , int);//修改旅客信息（第一位旅客n==0，第二位n==1)
void modify_room_imformation(struct RoomCase* );//修改房间信息

/*
结构体定义
*/

struct Rooms {
	int roomnum;//房间号
	char roomtype[50];//房间类型
	float roomprice;//房间价格 
};

struct Guests{
	char name[50];//名字
	char id[18];//身份证
	char sex[10];//旅客性别
};

struct RoomCase{	
	struct Rooms room;//房间
	int Nums;//旅客人数
	struct Guests guests[2];//旅客	
	time_t time_checkin;//入住时间
	struct RoomCase* next;
};


/*
数据定义
*/

struct RoomCase* head;

#define LEN sizeof(struct RoomCase)

