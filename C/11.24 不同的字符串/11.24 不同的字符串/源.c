#define _CRT_SECURE_NO_WARNINGS 1
//求总共有几个不相同的字符串，忽略字母的大小写区别
//每个测试包含多个测试用例。
//第一行包含一个正整数T(1≤T≤10), 表示测试用例的数量，测试用例的描述如下。
//第二行包含一个整数N(1≤N≤1000), 表示有N行字符串输入后面N行，每行一个字符串, 保证字符串长度小于100
//对于每个测试用例，输出不相同的字符串数量(结尾有换行)

#include <stdio.h>
#include <string.h>

int main(){
	void stringlwr(char* a);
	int i, j, p, q, m, n;
	int k = 1;						
	char s[100], s1[100], t[100];
	scanf("%d", &i);					
	for (j = 0; j < i; j++){					//测试用例的数量		
		k = 1;
		scanf("%d\n", &p);	
		//getchar();
		gets(s);
		//for (m = 0; ; m++){					//输入第一个字符串
		//	if (s[m] == '\n') break;
		//	scanf("%c", &s[m]);
		//}
		stringlwr(s);
		for (q = 2, k = 1; q <= p; q++){		//输入第2-n个字符串依次比较
			gets(s1);
			//for (m = 0; ; m++){
			//	scanf("%c", &s1[m]);
			//	if (s1[m] == '\n') break;
			//}
			stringlwr(s1);
			//strlwr(s1);
			if (strcmp(s, s1) != 0) {
				k++;
			}
		}
		t[j] = k;
	}
	for (j = 0; j < i; j++) {
		printf("%d", t[j]);
		if (j == i - 1) break;
		printf("\n");
	}
	return 0;
}

void stringlwr(char* a) {
	int i;
	int length = sizeof(a) / sizeof(a[0]) - 1;				//求字符串长度、数组个数
	for (i = 0; i < length; i++) {
		if ('A' <= a[i] && 'Z' >= a[i]) {
			a[i] += 32;
		}
	}
}
