#define _CRT_SECURE_NO_WARNINGS 1


//猜数字
//生成随机数->用户猜测->判断

//最大猜测次数
#define guess_time 10

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//清空缓冲区
void clean() {
	int ch = 0;
	while ((ch = getchar()) != EOF && ch != '\n');
}

int main() {
	//初始化随机种子
	srand((unsigned)time(NULL));
	//生成随机数
	int num = rand() % 100 + 1;//生成一个1-100的随机数（伪随机）
	int input = 0;
	int count = guess_time;
	cout << "请猜一个1-100之间的数字" << endl;

	while (1) {
		clean();
		//玩家猜测
		cin >> input;
		//判断
		if (input > num) {
			cout << "大了,"  ;
		}
		else if (input < num) {
			cout << "小了," ;
		}
		else {
			cout << "恭喜!猜对了!" << endl;
			break;
		}
		count--;
		if (count > 0) {
			cout << "还有" << count << "次机会" << endl;
		}
		else {
			cout << "游戏失败" << endl;
			break;
		}
	}


	system("pause");
	return 0;
}