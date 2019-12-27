#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
#include <Windows.h>
int flag = 0;			//意味着 没有找到
int *addrfind = NULL;	//地址

struct My_Struct
{
	int *pfindstart;	//要查找的首地址
	int length;			//限定长度，从地址开始
	int num;			//要查找的数据
	int bh;				//编号
	int *pflag;			//预留指针 为 null 传递flag 的地址，修改flag 访问flag
	int **addr;			//传递一个指针的地址
};


void find(void *p)
{
	struct My_Struct *pstruct=(struct My_Struct *)p;//指针类型转换
	//内存的遍历，从地址开始 累加100个元素的大小，遍历所有的元素
	for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + 100; px++)
	{
		Sleep(100);
		if (*(pstruct->pflag)!=0)
		{
			printf("属下%d无能，其他线程已经找到\n", pstruct->bh);
			return;
		}
		if (*px==pstruct->num)	//判断 是否相等
		{
			printf("第%d个线程  找到%p,%d  \n", pstruct->bh, px, *px);	//查找
			*(pstruct->pflag) = 1;		//改变标识 代表找到
			*(pstruct->addr) = px;		//间接修改addrfin 的地址
			return;
		}
	}
	printf("没有找到   %d个线程\n", pstruct->bh);
	return;
}
void main01()
{
	int a[1000]; //783
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;		//数组 初始化
	}
	struct My_Struct threaddata[10];	//创建结构体 处理不同的线程
	for (int i = 0; i < 10; i++)	//创建十个线程 进行查找
	{								//非阻塞 模式
		//a  a+100 a+200      ....		 a+900
		//int *p = a + i * 100;
		
		threaddata[i].pfindstart = a + i * 100;	//创建结构体
		threaddata[i].length = 100;				//长度
		threaddata[i].bh = i;						//编号
		threaddata[i].num = 783;					//要查找的数据
		threaddata[i].pflag = &flag;
		threaddata[i].addr = &addrfind;				//存储了变量的地址
		//printf("\n%d\n", threaddata[i].bh);
		_beginthread(find, 0, &threaddata[i]);	//
		//Sleep(20);	//留出 20 毫秒 的时间
		//我并不能 绝对节约时间
		//给数据创建 赋值
	}

	Sleep(30000);	//给点 缓冲时间

	//printf("hello...\n");
	system("pause");
	printf("\n\n%d,%p\n\n", *addrfind, addrfind);	//打印地址 和数据
	system("pause");
}
