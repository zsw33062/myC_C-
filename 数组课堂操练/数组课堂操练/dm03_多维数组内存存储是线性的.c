#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void printfArray(int *array, int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
	}
}
void main0301()
{	
	int a[3][5];
	int tmp = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}
	//�� ��ά ���� ����һά ���� ����ӡ ֤�� ���Դ洢
	printfArray((int *)a, 15);
	printf("\n");
	printf("hello...\n");
	system("pause");
}
