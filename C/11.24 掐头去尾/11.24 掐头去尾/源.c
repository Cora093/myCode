#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

//×Ö·û´®ÆþÍ·È¥Î²
int main()
{
	int length, i;
	char s[80], s1[81];
	gets(s);
	for (i = 1;; i++)
	{
		if (s[i] == '\0')break;
		s1[i - 1] = s[i];
	}
	s1[i - 2] = '\0';
	puts(s1);
	return 0;
}