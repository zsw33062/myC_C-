#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//ֱ�Ӱ��ڴ����� д�뵽 �ļ���
typedef struct Teacher
{
	char name[64];		//�� buf ��ָ�� �ǲ�һ����
	int age;

}Teacher;
void main_fwrite()
{
	int i = 0;
	int myN;
	FILE *fp = NULL;
	char *filename = "e:/3.txt";
	Teacher tArray[3];

	for (i = 0; i < 3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArray[i].age = i + 31;
	}
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("�����ļ���ʧ��\n");
		return;
	}
	for (i = 0; i < 3; i++)
	{	//_Check_return_opt_ _CRTIMP size_t __cdecl
		//fwrite(_In_reads_bytes_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);

		//_Str  ���ڴ�鿪ʼ
		//_Count д���ٴ�
		//_Size //�ڴ�������
		//_File д�뵽�ļ�ָ��  ��ָ����ļ���
		//���� �ķ���ֵ   ��д�ĳɹ�����
		//ͨ���� ���Կ����ǵĲ�����û�� �ɹ� ������û��д��
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);		//������������Ϊ��Ҫ
		//myN  �ж���û��д������
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
}
//void socketclient_send(void *handle,usingned char *buf,int len)
void main_fread()
{
	int i = 0;
	int myN;
	FILE *fp = NULL;
	char *filename = "e:/3.txt";
	Teacher tArray[3];

	/*for (i = 0; i < 3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArray[i].age = i + 31;
	}*/
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("��ȡʧ��\n");
		return;
	}
	for (i = 0; i < 3; i++)
	{	//_Check_return_opt_ _CRTIMP size_t __cdecl 
		//fread(_Out_writes_bytes_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

		myN=fread(&tArray[i], sizeof(Teacher), 1, fp);
		//myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);		
		//myN  �ж���û��д������
	}
	for (i = 0; i < 3; i++)
	{
		printf("name:%s, age:%d\n", tArray[i].name,tArray[i].age);
		//tArray[i].age = i + 31;
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
}


void main()
{	
	//main_fwrite();
	main_fread();
	printf("hello...\n");
	system("pause");
}
