#define _CRT_SECURE_NO_WARNINGS 1

//ʹ�ַ������򣨲�ʹ���ַ�������������
#include <stdio.h>

int my_strlen(char* str) {					//���ַ�������
	if (*str != '\0') {
		return 1 + my_strlen(str + 1);
	}
	else {
		return 0;
	}
}
void reverse_string(char* str) {			//������β�ַ�
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