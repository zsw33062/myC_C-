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
	//��Ҫ���׵�ʹ��malloc new
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (buf == NULL)
	{
		*len = 10;		//��һ�ε��� �󳤶�
		//return -1;
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 10);
		*(tmp + 10) = '\0';//strncpy���Ḵ��\0
		*len = strlen(tmp);
	}
	//*buf = tmp;
	//��Ӹ�ֵ
	return 0;
}

void main0101()
{	
	const char *filename = "e:/1.txt";
	char *p = NULL;
	int len = 0;
	//int ret = getContentLen01(filename, &p, &len);
	//һ��ָ�� ��Ӹı��βε�ֵ
	//����ָ�� ��Ӹı�һ��ָ���ֵ
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
	//��һ�ε��� �󳤶�
	getContentLen02(filename, NULL, &len);
	p = (char *)malloc(len);
	if (p == NULL)
	{
		free(p);
		p = NULL;
	}
	//�ڶ��ε��� ������
	//2 �ε���
	//����������һ�ε��ú��� �󳤶ȣ����ݳ��ȣ������ڴ棬���ñ������� 
	getContentLen02(filename, &p, &len);
	printf("filename:%s\n", filename);
	printf("len:%d\n", len);
	printf("sizeof(len):%d\n", sizeof(len));
	printf("hello...\n");
	system("pause");
}
