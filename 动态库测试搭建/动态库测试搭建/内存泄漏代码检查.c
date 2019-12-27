#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "memwatch.h"
//#include "memwatch.c"
#include "getMem.h"
char *getmem(char **myp)
{
	char *p = null;

	p = (char *)malloc(100);  //mwMalloc(n,__FILE__,__LINE__)

	//屏蔽掉 系统的api函数

	strcpy(p, "aaaaaabbbbb");
	*myp = p;
	return 0;

}

void main()
{	
	
	char *myp = NULL;
	
	getMem(&myp);
	if (myp!=NULL)
	{
		free(myp);
		myp = NULL;
	}
	printf("%s \n", myp);
	printf("hello...\n");
	system("pause");
}
