#define  _CRT_SECURE_NO_WARNINGS		//关闭安全检查
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
void gogogo(void *p)
{
	int *px = (int*)p;//指针类型 转化

	Sleep(2000);
	//printf("A\n");
	int i = 0;
	printf("\n");
	while (1)
	{
		if (i>5)
		{
			printf("%d    %d\n", i,*px);
			_endthread();//	结束 当前线程
		}
		
		Sleep(1000);
		i++;
	}
	//return;		//线程 执行完成以后 返回
}
void time(void *p)
{
	int i = 0;
	while (1)
	{
		char str[100] = { 0 };
		sprintf(str, "title 当前时间%d 秒", i);
		system(str);
		i++;
		Sleep(1000);
	}
}
void main()
{		//主线程 一定要存在
	//time(NULL);
	_beginthread(time, 0, NULL);
	for (int i = 0; i < 5; i++)
	{
		//gogogo();
		HANDLE hd =/*(HANDLE)*/ _beginthread(gogogo, 0,&i);//hd 是一个 编号
		//WaitForSingleObject(hd, INFINITE);		//等待，阻塞 模式  没有 wait  是并行模式
		Sleep(1000);
	}
	printf("hello...\n");
	system("pause");
	printf("\n");
}
