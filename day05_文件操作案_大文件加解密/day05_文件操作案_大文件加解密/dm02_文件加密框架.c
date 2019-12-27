#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"
//#include "des.c"
//功能实现分析
int main()
{
	int ret = 0;
	char *plain = "121241556";
	int plainlen = strlen(plain);

	char plain2[4096] = { 0 };
	int plainlen2;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	//用户使用的函数
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	/*unsigned char *pInData,
	int		   	  nInDataLen,
	unsigned char *pOutData,
	int		   	  nOutDataLen)*/
	if (ret != 0)
	{
		printf("func DesEnc() err: %d \n", ret);
		return ret;
	}

	//用户使用函数des解密
	ret = DesDec(cryptbuf, cryptlen, plain2, &plainlen2);
	/*unsigned char *pInData,
	int		   	  nInDataLen,
	unsigned char *pOutData,
	int		   	  nOutDataLen);*/
	if (ret != 0)
	{
		printf("func DesEnc() err: %d \n", ret);
		return ret;
	}
	if (plainlen != plainlen2)
	{
		ret = -2;
		printf("明文长度和解密后的明文长度不一样 \n");
		return ret;
	}
	//memcpy指的是c和c++使用的内存拷贝函数，
	//memcpy函数的功能是从源src所指的内存
	//地址的起始位置开始拷贝n个字节到目标
	//dest所指的内存地址的起始位置中。
	if (memcmp(plain2, plain, plainlen) == 0)
		//_Check_return_ int     __cdecl 
		//memcmp(_In_reads_bytes_(_Size) const void * _Buf1, 
		//_In_reads_bytes_(_Size) const void * _Buf2, 
		//_In_ size_t _Size);

		//memcpy
		//void *  __cdecl 
		//memcpy(_Out_writes_bytes_all_(_Size) void * _Dst, 
		//		 _In_reads_bytes_(_Size) const void * _Src, 
		//		 _In_ size_t _Size);
	{
		printf("明文长度和解密后的明文长度 一样  ok  \n");
	}
	else
	{
		printf("明文长度和解密后的明文长度 不一样  err  \n");
	}



	printf("hello...\n");
	system("pause");
}
