#include <Windows.h>
#include <process.h>	//����
#include <stdlib.h>

struct MyStruct
{
	int num;

};

void run(void *p)
{
	int *px = (int *)p;	//ָ�����͵�ת��
	//printf("�߳�%d����\n",*px);
	char str[100] = { 0 };
	sprintf(str," �߳�%d����",*px);
	MessageBox(0, str, "���߳�", 0);
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