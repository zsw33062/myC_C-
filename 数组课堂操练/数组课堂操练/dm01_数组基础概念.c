#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main1101()
{
	int a[] = { 1, 2 };
	int b[100] = { 1, 3 };
	int c[200] = { 0 };		//�����ʱ�� ���Ѿ�ȷ�� ���е�ֵΪ ��
	memset(c, 0, sizeof(c));	//��ʽ ������ �ڴ���
	//c��������Ԫ�صĵ�ַ c+1 ���� ��4 ���ֽ�
	//&c ����������ĵ�ַ  //&c+1 ���� 200*4
	printf("c+1 -c  :%d\n", c + 1 - c);
	printf("&c:%d\n", &c);
	printf("&c+1:%d\n", &c + 1);
	int len = (int)((&c + 1) - &c);
	printf("(&c+1)-&c:%d\n", len);
	printf("sizeof(c):%d\n", sizeof(c));
	printf("�õ���������ĵ�ַ a:%d\n", &a);
	printf("�������Ԫ�صĵ�ַ a:%d\n", a);
	printf("hello...\n");//
	system("pause");
	return;
}
void main1102()
{
	typedef int(MyArrayType)[5];//������һ���������� ������������
	MyArrayType myArray;	//int myArray[5]
	
	for (int i = 0; i < 5; i++)
	{
		myArray[i] = i + 1;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", myArray[i]);
	}
	printf("\n");

	printf("myArray����������Ԫ�صĵ�ַ%d  myArray+1:%d \n", myArray, myArray + 1);
	printf("&myArray������������ĵ�ַ%d  &myArray+1:%d \n", &myArray, &myArray + 1);
	printf("hello...\n");//
	system("pause");
}
//��������ָ������ķ��� 1
void main1103()
{

	char *Myarray[] = { "111111", "222222", "333333" }; //ָ������
	 
	//����ָ��  ��һ��ָ�� ��ָ�� һ������
	typedef int(MyArrayType)[5];//������һ���������� ������������
//	MyArrayType myArray;	//int myArray[5]   //�����Ͷ������ 

	MyArrayType *pArray;	//����һ��ָ����� ���ָ����� ָ��һ������

	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		//int const count = 5; 
			 
		int myArray2[5];	//�൱�� һ��ָ��
		pArray = &myArray2;
		for (int i = 0; i < 5; i++)
		{
			(*pArray)[i] = i + 1;
		}
		//pArray = &myArray2;	//�൱�� ����ָ��
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", (*pArray)[i]);
		}
		printf("\n");
	}
	 
	printf("hello...\n");//
	system("pause");
}
//��������ָ������ĵ����ַ���
//ǰ ���� ���� ͨ�����Ͷ������ �Ƚ��鷳

void main1104()
{


	int(*pMyArray)[5];//ֱ�Ӷ���һ��ָ�� �����   ���� ָ�� ����
	//����һ������ָ������
	typedef int (*PArrayType)[5];
	PArrayType pArray;	//����C++������ ���ҷ���һ��ָ����� 

	int c1[5];
	int c2[5];
	pArray = &c1;
	pMyArray = &c2;
	for (int i = 0; i < 5; i++)
	{
		(*pArray)[i] = i + 1;
		(*pMyArray)[i] = i*i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", (*pArray)[i]);
	
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", (*pMyArray)[i]);
	}
	
	printf("hello ...\n");
	system("pause");
	return;
}


//�����������͵ĵ����ַ���
void main1105()
{	


	printf("hello...\n");
	system("pause");
	return;
}