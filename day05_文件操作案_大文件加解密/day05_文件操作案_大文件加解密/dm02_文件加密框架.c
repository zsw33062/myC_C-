#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"
//#include "des.c"
//����ʵ�ַ���
int main()
{
	int ret = 0;
	char *plain = "121241556";
	int plainlen = strlen(plain);

	char plain2[4096] = { 0 };
	int plainlen2;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	//�û�ʹ�õĺ���
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

	//�û�ʹ�ú���des����
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
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��Ȳ�һ�� \n");
		return ret;
	}
	//memcpyָ����c��c++ʹ�õ��ڴ濽��������
	//memcpy�����Ĺ����Ǵ�Դsrc��ָ���ڴ�
	//��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��
	//dest��ָ���ڴ��ַ����ʼλ���С�
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
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� һ��  ok  \n");
	}
	else
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ��  err  \n");
	}



	printf("hello...\n");
	system("pause");
}
