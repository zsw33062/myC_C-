#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getMem1(char *p)
{
	*p = 10;
	return 0;
}
void main01()
{	
	
	int a = 10;
	int *p = NULL;
	
	a = 11;

	p = &a;
	*p = 20;

	{
		*p = 30;	//*˭�ĵ�ַ  �ͼ�Ӹı�˭�ĵ�ַ
	}

	printf("a:%d\n", a);


	printf("hello...\n");
	system("pause");
}

void getMem(char **p2/*out*/)
{
	*p2 = 30;	//��Ӹ�ֵ  p2 ��p�ĵ�ַ

	*p2 = (char **)malloc(1000);
	//return 0;
}


void main02()
{
	char *p = NULL;
	char **p2 = NULL;
	//p = 1;
	//p = 2;//ֱ���޸�p ��ֵ

	p2 = &p;
	*p2 = 20;

	{
		*p2 = 30;	//��Ӹ�ֵ  p2 ��p�ĵ�ַ
	}

	printf("hello...\n");
	system("pause");
}
int getMem2(char ***p3)
{
	*p3 = 100;
}

void main03()
{

	char **p = NULL;

	char ***p3 = NULL;

	p = 1;
	p = 2;

	p3 = &p;
	*p3 = 10;	//ֱ���޸Ķ���ָ���ֵ
	{
		*p3 = 30;
	}
	getMem2(&p);
	printf("hello...\n");
	system("pause");
}
int getMem3(char ********p8)
{
	*p8 = 100;	//* ����p7�ĵ�ַ ���� ��� �޸���p7��ֵ
	return 0;
}

void main()
{
	char *******p7 = NULL;
	p7 = 1;
	p7 = 2;
	char ********p8 = NULL;

	p8 = &p7;
	
	*p8 = 10;
	{
		p8 = p7;	//* ����p7�ĵ�ַ ���� ��� �޸���p7��ֵ
	}
	getMem3(&p7);
	printf("p7:%d\n", p7);
	printf("hello...\n");
	system("pause");
}