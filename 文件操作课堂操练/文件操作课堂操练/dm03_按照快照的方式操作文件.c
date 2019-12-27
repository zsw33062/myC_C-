#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//直接把内存数据 写入到 文件中
typedef struct Teacher
{
	char name[64];		//用 buf 和指针 是不一样的
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
		printf("建立文件夹失败\n");
		return;
	}
	for (i = 0; i < 3; i++)
	{	//_Check_return_opt_ _CRTIMP size_t __cdecl
		//fwrite(_In_reads_bytes_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);

		//_Str  从内存块开始
		//_Count 写多少次
		//_Size //内存打包技术
		//_File 写入到文件指针  所指向的文件中
		//函数 的返回值   是写的成功次数
		//通过它 可以看我们的操作有没有 成功 磁盘有没有写满
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);		//第三个参数尤为重要
		//myN  判断有没有写满磁盘
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
		printf("读取失败\n");
		return;
	}
	for (i = 0; i < 3; i++)
	{	//_Check_return_opt_ _CRTIMP size_t __cdecl 
		//fread(_Out_writes_bytes_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

		myN=fread(&tArray[i], sizeof(Teacher), 1, fp);
		//myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);		
		//myN  判断有没有写满磁盘
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
