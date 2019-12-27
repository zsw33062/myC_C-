#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main01_fputs()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//统一用45度 在Linux 与Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//以读写的方式打开一个存在的文件
	if (fp == NULL)
	{
		printf("func fopen() err \n");
	}
	printf("打开成功\n");

	/*for (i = 0; i < strlen(a); i++)
	{
	fputc(a[i], fp);
	}*/
	fputs(a, fp);

	fclose(fp);				//fp句柄  内存块的首地址 或资源的首地址
}
char * myfgets(char *myp, int max, FILE * fp)
{
	strcpy(myp, "aaaaa");
	return myp;
}

void main01_fgets()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/22.txt";	//统一用45度 在Linux 与Windows 
	//char a[30] = "abcdefghijklmnopqrstuvwxyz";
	char buf[1024];
	//fp = fopen(filename2, "r+");		//以读写的方式打开一个存在的文件 如果文件不存在 报错
	fp = fopen(filename2, "r+");		//以读写的方式打开一个存在的文件 如果文件不存在 新建
	if (fp == NULL)						//
	{
		printf("func fopen() err \n");
	}
	printf("打开成功\n");
	//1 //C 函数库 会一行一行的copy数据到buf 指针 所指的内存空间中 并变成C 风格的字符串
	//2 把 \n也拷贝到我们的buff中
	//3 内存打包技术（把内存地址  +   内存的长度）
	while (!feof(fp))
	{	//_Check_return_opt_ _CRTIMP char * __cdecl fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		char *p = fgets(buf, 1024, fp);		//最多 1023个 还一个\0
		//C 函数库 会一行一行的copy数据到buf 指针 所指的内存空间中 并变成C 风格的字符串
		if (p == NULL)
		{
			goto End;
		}
		printf("%s", buf);	//按照一行一行的读取数据 把\n也读到数据离了
		/*char tmpc = fgetc(fp);
		printf("%c ", tmpc);*/
	}
End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	//fclose(fp);				//fp句柄  内存块的首地址 或资源的首地址
}
void main0201()
{
	//main01_fputs();
	main01_fgets();
	
	printf("\nhello...\n");
	system("pause");
}
