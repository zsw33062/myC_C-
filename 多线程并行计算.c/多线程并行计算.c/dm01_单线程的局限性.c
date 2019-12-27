#include <Windows.h>
#include <process.h>	//进程
#include <stdlib.h>

struct MyStruct
{
	int num;

};

void run(void *p)
{
	int *px = (int *)p;	//指针类型的转换
	//printf("线程%d启动\n",*px);
	char str[100] = { 0 };
	sprintf(str," 线程%d启动",*px);
	MessageBox(0, str, "多线程", 0);
}

void main01()
{
	/*for (int i = 0; i < 5; i++)
		//run(NULL);*/
	for (int i = 0; i < 5; i++)
	{
		_beginthread(run, 0, &i);
		Sleep(1000);
	}


	system("pause");

}