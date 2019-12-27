#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void change(int *p, int num)
{
	*p = num;
}

void maintest()
{	
	int a = 10;
	int b = 20;
	int *p = &a;
	change(p, b);
	printf("a:%d\n", a);
	printf("hello...\n");
	system("pause");
}
void mainfree()
{
	char *p;
	p = (char *)malloc(100);
	free(p);
	free(p);
}