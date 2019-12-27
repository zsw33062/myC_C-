#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _SCK_HANDLE
{
	char vresion[16];
	char serverip[16];
	int servrport;
	char *buf;
	int buflen;

}SCK_HANDLE;

/*
1.初始化环境
2.被调函数分配内存供主调函数使用
3.handle 句柄给出资源的内存首地址
4.使用void 指针是为了对数据的封装，调用者不知道数据结构，但是底层开发者知道数据结构
*/

__declspec(dllexport)
int cltSocket_init(void **handle /*out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		ret = -1;
		printf("cltSocket_init err:%d malloc failure", ret);
		return ret;
	}

	*handle = sh;
	strcpy(sh->vresion, "1.0.1");
	strcpy(sh->serverip, "192.168.0.1");
	sh->servrport = 8080;
	sh->buf = NULL;

	return ret;
}

//客户端发报文
__declspec(dllexport)
int cltSocket_senddata(void *handle/*in */, unsigned char *buf/*in */, int buflen/* in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("cltSocket_senddata err:%d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	sh->buf = (char *)malloc(sizeof(char)*buflen);// 分配内存空间
	if (sh->buf == NULL)
	{
		ret = -2;
		printf("cltSocket_senddata err %d,buflen ", buflen);
		return ret;
	}
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return ret;
}

//客户端收报文
__declspec(dllexport)
int cltSocket_resvdata(void *handle/*in */, unsigned char *buf/*in */, int *buflen/*in */)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("cltSocket_resvdata err:%d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;// 调用者不知道数据类型，底层开发者知道数据类型

	memcpy(buf, sh->buf, sh->buflen);
	*buflen = sh->buflen;

	return ret;

}

/*
1.客户端销毁环境
2.根据handle 释放其内存空间
*/
__declspec(dllexport)
int cltSocket_destory(void *handle)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL)
	{
		ret = -1;
		printf("cltSocket_destory err:%d", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle;// 调用者不知道数据类型，底层开发者知道数据类型

	if (sh->buf != NULL)//释放buf的内存
	{
		free(sh->buf);
		sh->buf = NULL;
	}
	free(sh);

	return ret;
}
