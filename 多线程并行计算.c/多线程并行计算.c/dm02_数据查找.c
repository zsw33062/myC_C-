#define  _CRT_SECURE_NO_WARNINGS		//�رհ�ȫ���
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
void gogogo(void *p)
{
	int *px = (int*)p;//ָ������ ת��

	Sleep(2000);
	//printf("A\n");
	int i = 0;
	printf("\n");
	while (1)
	{
		if (i>5)
		{
			printf("%d    %d\n", i,*px);
			_endthread();//	���� ��ǰ�߳�
		}
		
		Sleep(1000);
		i++;
	}
	//return;		//�߳� ִ������Ժ� ����
}
void time(void *p)
{
	int i = 0;
	while (1)
	{
		char str[100] = { 0 };
		sprintf(str, "title ��ǰʱ��%d ��", i);
		system(str);
		i++;
		Sleep(1000);
	}
}
void main()
{		//���߳� һ��Ҫ����
	//time(NULL);
	_beginthread(time, 0, NULL);
	for (int i = 0; i < 5; i++)
	{
		//gogogo();
		HANDLE hd =/*(HANDLE)*/ _beginthread(gogogo, 0,&i);//hd ��һ�� ���
		//WaitForSingleObject(hd, INFINITE);		//�ȴ������� ģʽ  û�� wait  �ǲ���ģʽ
		Sleep(1000);
	}
	printf("hello...\n");
	system("pause");
	printf("\n");
}
