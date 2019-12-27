#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void maintest()
{	
	int i = 0;
	int tmpi = 0;
	for (i = 0; i < 5; i++)
	{
		tmpi = i;
	}
	printf("i:%d\n", i);			//i=?		5
	printf("tmpi:%d\n", tmpi);		//tmpi=?	4

	printf("hello...\n");
	system("pause");
}
