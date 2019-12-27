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

//多维数组做函数参数 退化 过程... 事实是存在 的
//为什么 会存在退化
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
	//a  多维数组 名称 代表 什么意思
	printf("a: %d, a+1: %d\n", a, a + 1);	//a的步长 是二十个字节  5*4
	printf("&a: %d, &a+1:%d\n", &a, &a + 1);	//&a的步长 是六十个字节   5*4*3 
	{
		//定义一个 指向数组的指针变量
		int(*pArray)[5];//告诉编译器 分配 4 个字节的内存 32 bit 平台下
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
	//多维数组 名的本质 数组指针 步长 一维 的长度

	// a+i  代表是整个第 i行的首地址 二级指针
	//*(a+i)  代表是第 i行的首元素地址
	//*(a+i)+j ====> &a[i][j]  代表是第 i行的第j 个首元素地址
	//*(*(a+i)+j)==>a[i][j] 元素的值
	
	//a[i][j] = *(*(a + i) + j);

	//a[i] == == > a[0 + i] == = > *(a + i);

	//a[i][i] == == > a[0 + i][j] == == > *(a + i)[0 + j] == = > *(*(a + i) + j);
	printf("\n");
	printf("hello...\n");
	system("pause");
	return;
}