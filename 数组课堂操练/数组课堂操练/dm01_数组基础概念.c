#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main1101()
{
	int a[] = { 1, 2 };
	int b[100] = { 1, 3 };
	int c[200] = { 0 };		//编译的时候 就已经确定 所有的值为 零
	memset(c, 0, sizeof(c));	//显式 的重置 内存块儿
	//c是数组首元素的地址 c+1 步长 是4 个字节
	//&c 是整个数组的地址  //&c+1 步长 200*4
	printf("c+1 -c  :%d\n", c + 1 - c);
	printf("&c:%d\n", &c);
	printf("&c+1:%d\n", &c + 1);
	int len = (int)((&c + 1) - &c);
	printf("(&c+1)-&c:%d\n", len);
	printf("sizeof(c):%d\n", sizeof(c));
	printf("得到整个数组的地址 a:%d\n", &a);
	printf("数组的首元素的地址 a:%d\n", a);
	printf("hello...\n");//
	system("pause");
	return;
}
void main1102()
{
	typedef int(MyArrayType)[5];//定义了一个数据类型 数组数据类型
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

	printf("myArray代表数组首元素的地址%d  myArray+1:%d \n", myArray, myArray + 1);
	printf("&myArray代表整个数组的地址%d  &myArray+1:%d \n", &myArray, &myArray + 1);
	printf("hello...\n");//
	system("pause");
}
//定义数组指针变量的方法 1
void main1103()
{

	char *Myarray[] = { "111111", "222222", "333333" }; //指针数组
	 
	//数组指针  用一个指针 来指向 一个数组
	typedef int(MyArrayType)[5];//定义了一个数据类型 数组数据类型
//	MyArrayType myArray;	//int myArray[5]   //用类型定义变量 

	MyArrayType *pArray;	//定义一个指针变量 这个指针变量 指向一个数组

	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		//int const count = 5; 
			 
		int myArray2[5];	//相当于 一级指针
		pArray = &myArray2;
		for (int i = 0; i < 5; i++)
		{
			(*pArray)[i] = i + 1;
		}
		//pArray = &myArray2;	//相当于 二级指针
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", (*pArray)[i]);
		}
		printf("\n");
	}
	 
	printf("hello...\n");//
	system("pause");
}
//定义数组指针变量的第三种方法
//前 两种 方法 通过类型定义变量 比较麻烦

void main1104()
{


	int(*pMyArray)[5];//直接定义一个指向 数组的   数组 指针 变量
	//定义一个数组指针类型
	typedef int (*PArrayType)[5];
	PArrayType pArray;	//告诉C++编译器 给我分配一个指针变量 

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


//定义数组类型的第四种方法
void main1105()
{	


	printf("hello...\n");
	system("pause");
	return;
}