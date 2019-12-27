#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void printArray01(int a[3][5])
{
	int i;
	int j;
	int tmp = 0;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray02(int a[][5])
{
	int i;
	int j;
	int tmp = 0;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray03(int (*a)[5])
{
	int i;
	int j;
	int tmp = 0;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray04_err(int *a[5])
{
	int i;
	int j;
	int tmp = 0;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}

//��ά�������������� �˻� ����... ��ʵ�Ǵ��� ��
//Ϊʲô ������˻�
void main0201()
{

	int a[3][5];
	int i = 0;
	int j = 0;
	int tmp = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	printArray03(a);
	printf("\n");
	//a  ��ά���� ���� ���� ʲô��˼
	printf("a: %d, a+1: %d\n", a, a + 1);	//a�Ĳ��� �Ƕ�ʮ���ֽ�  5*4
	printf("&a: %d, &a+1:%d\n", &a, &a + 1);	//&a�Ĳ��� ����ʮ���ֽ�   5*4*3 
	{
		//����һ�� ָ�������ָ�����
		int(*pArray)[5];//���߱����� ���� 4 ���ֽڵ��ڴ� 32 bit ƽ̨��
		pArray = a;
		printf("\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("%d ", pArray[i][j]);
			}
		}
	}
	//��ά���� ���ı��� ����ָ�� ���� һά �ĳ���

	// a+i  ������������ i�е��׵�ַ ����ָ��
	//*(a+i)  �����ǵ� i�е���Ԫ�ص�ַ
	//*(a+i)+j ====> &a[i][j]  �����ǵ� i�еĵ�j ����Ԫ�ص�ַ
	//*(*(a+i)+j)==>a[i][j] Ԫ�ص�ֵ
	
	//a[i][j] = *(*(a + i) + j);

	//a[i] == == > a[0 + i] == = > *(a + i);

	//a[i][i] == == > a[0 + i][j] == == > *(a + i)[0 + j] == = > *(*(a + i) + j);
	printf("\n");
	printf("hello...\n");
	system("pause");
	return;
}