#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getContentLen01(const char *filename, char **buf, int *len)
{
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (tmp==NULL)
	{
		return -1;
	}
	strcpy("tmp", "aaaaaaaaaaaaaaa");
	*len = strlen(filename);
	*buf = tmp;
	return 0;
}
int getContentLen02(const char *filename, char *buf, int *len)
{
	//不要轻易的使用malloc new
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (buf == NULL)
	{
		*len = 10;		//第一次调用 求长度
		//return -1;
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 10);
		*(tmp + 10) = '\0';//strncpy不会复制\0
		*len = strlen(tmp);
	}
	//*buf = tmp;
	//间接赋值
	return 0;
}

void main0101()
{	
	const char *filename = "e:/1.txt";
	char *p = NULL;
	int len = 0;
	//int ret = getContentLen01(filename, &p, &len);
	//一级指针 间接改变形参的值
	//二级指针 间接改变一级指针的值
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
	//第一次调用 求长度
	getContentLen02(filename, NULL, &len);
	p = (char *)malloc(len);
	if (p == NULL)
	{
		free(p);
		p = NULL;
	}
	//第二次调用 求内容
	//2 次调用
	//主调函数第一次调用函数 求长度，根据长度，分配内存，调用被调函数 
	getContentLen02(filename, &p, &len);
	printf("filename:%s\n", filename);
	printf("len:%d\n", len);
	printf("sizeof(len):%d\n", sizeof(len));
	printf("hello...\n");
	system("pause");
}
