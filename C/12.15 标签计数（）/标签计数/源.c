#define _CRT_SECURE_NO_WARNINGS 1
//写一个模块来处理文本并计算其中不同标签的数量。
//文本由小写英文字母，数字，符号 # 以及空格四种字符组成。
//我们把若干个连续的非空格字符定义成一个词，词的左右两边要么是空格要么就是文本的开头或者结尾。
//若一个词的长度大于 1 ，第一个字符是 # 而其它的字符都不是 #，那我们称这个词是一个标签。
//现在喵喵想计算文本中出现的不同标签的数量，并将其打印出来。
//在一行中输入一个长度不超过10的5次方的字符串 str 表示要处理的文本
//先在一行中输出一个整数 n，代表文本中出现的不同标签的个数
//接下来 n 行，每行打印一个标签和这个标签出现的次数
//标签可以按任何顺序打印

#include <stdio.h>
#include <string.h>

void getwords(char* words, char* str) {
	int n = 0;		//单词数
	int i = 0;		//字符数
	if (*str != ' ') {
		for (i = 0;; i++) {
			*(words + (20 * n + i)) = *(str + i);
			if (*(str + i) == ' ') {
				break;
			}
		}
		n++;
	}
	

}


int main() {
	int i = 0, j = 0;
	int n = 0;
	int count = 0;				//计数
	char str[10000] = { 0 };	//输入
	gets(str);
	char words[100][20] = { 0 };//存放单词
	getwords(words[0], str);
	
	return 0;
}