#define _CRT_SECURE_NO_WARNINGS 1

//使字符串逆序（不使用字符串操作函数）
#include <stdio.h>

int my_strlen(char* str) {					//求字符串长度
	if (*str != '\0') {
		return 1 + my_strlen(str + 1);
	}
	else {
		return 0;
	}
}
void reverse_string(char* str) {			//交换首尾字符
	int left = 0;
	int right = my_strlen(str) - 1;
	char tmp = 0;
	while (left < right) {
		tmp = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = tmp;
		left++;
		right--;
	}

}

int main() {

	void reverse_string(char* str);
	int my_strlen(char* str);

	char arr[1000] = { 0 };
	gets(arr);
	//printf("%d\n", my_strlen(arr));
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}