#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main01_fputc()
{	
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//统一用45度 在Linux 与Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//以读写的方式打开一个存在的文件
	if (fp==NULL)
	{
		printf("func fopen() err \n" );
	}
	printf("打开成功\n");

	for (i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);				//fp句柄  内存块的首地址 或资源的首地址
}
void main02_fgetc()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//统一用45度 在Linux 与Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//以读写的方式打开一个存在的文件
	if (fp == NULL)
	{
		printf("func fopen() err \n");
	}
	printf("打开成功\n");

	while (!feof(fp))
	{
		char tmpc = fgetc(fp);
		printf("%c ", tmpc);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}

	//fclose(fp);				//fp句柄  内存块的首地址 或资源的首地址
}
void main02()
{
	//main01_fputc();
	main02_fgetc();
	printf("\nhello...\n");
	system("pause");
}
