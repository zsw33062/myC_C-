#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main01_fputc()
{	
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//ͳһ��45�� ��Linux ��Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//�Զ�д�ķ�ʽ��һ�����ڵ��ļ�
	if (fp==NULL)
	{
		printf("func fopen() err \n" );
	}
	printf("�򿪳ɹ�\n");

	for (i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);				//fp���  �ڴ����׵�ַ ����Դ���׵�ַ
}
void main02_fgetc()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//ͳһ��45�� ��Linux ��Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//�Զ�д�ķ�ʽ��һ�����ڵ��ļ�
	if (fp == NULL)
	{
		printf("func fopen() err \n");
	}
	printf("�򿪳ɹ�\n");

	while (!feof(fp))
	{
		char tmpc = fgetc(fp);
		printf("%c ", tmpc);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}

	//fclose(fp);				//fp���  �ڴ����׵�ַ ����Դ���׵�ַ
}
void main02()
{
	//main01_fputc();
	main02_fgetc();
	printf("\nhello...\n");
	system("pause");
}
