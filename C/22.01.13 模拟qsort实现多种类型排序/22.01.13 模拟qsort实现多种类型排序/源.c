#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//比较函数（根据不同类型由用户进行更改）
int compare_elmt(const void* elmt1, const void* elmt2) {
	return *(char*)elmt1 - *(char*)elmt2;
}

//交换
void swap(char* elmt1, char* elmt2, int width) {
	int i = 0;
	//交换width个字节的内存，以char类型为基准有通用性
	for (i = 0; i < width; i++) {
		char tmp = *elmt1;
		*elmt1 = *elmt2;
		*elmt2 = tmp;
		elmt1++;
		elmt2++;
	}
}

//冒泡排序
void bubble_sort(void* p, int sz, int width, int (*cmp)(const void* elmt1, const void* elmt2)) {
	int i = 0, j = 0;
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz - i - 1; j++) {//冒泡排序
			if (cmp((char*)p + j * width, (char*)p + (j + 1) * width) > 0) {//指向a[j]和a[j+1]的指针
				swap((char*)p + j * width, (char*)p + (j + 1) * width, width);
			}
		}
	}

}

//输出字符数组
void print_char(char* p, int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%c ", *(p + i));
	}
	printf("\n");
}

int main() {
	char a[8] = { 'f','b','a','c','i','z','x','y' };
	print_char(a, sizeof(a));
	bubble_sort(a, sizeof(a), sizeof(a[0]), &compare_elmt);
	print_char(a, sizeof(a));
	return 0;
}