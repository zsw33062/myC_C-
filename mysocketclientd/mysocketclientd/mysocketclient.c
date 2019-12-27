#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _SCK_HANDLE
{
	char version[64];
	char ip[128];
	int port;
	char *p;
	int plen;

}_SCK_HANDLE;	//动态库  内部数据类，不想让测试程序（上层应用知道）
//数据类型的封装



_declspec(dllexport)
int cltSocket_init(void **handle/*out*/) //5day
{

	_SCK_HANDLE *hdl = NULL;
	int ret = 0;
	printf("func cltSocket_init() begin\n");
	hdl = (_SCK_HANDLE *)malloc(sizeof(_SCK_HANDLE));	//把指针指向的内存空间 赋值 成0
	if (hdl == NULL)
	{
		ret = -1;
		printf("func cltSocket_init() err:%d \n", ret);
		return ret;
	}
	memset(hdl, 0, sizeof(_SCK_HANDLE));
	strcpy(hdl->ip, "192.168.8.254");
	hdl->port = 8081;
	*handle = hdl;
	printf("func cltSocket_init() end\n");
	return 0;
}

//客户端发报文
_declspec(dllexport)
int cltSocket_senddata(void *handle/*in*/, unsigned char *buf/*in*/, int buflen/*in*/)
{
	_SCK_HANDLE *hdl = NULL;
	int ret = 0;

	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func cltSocket_senddata() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}


	hdl = (_SCK_HANDLE *)handle;
	hdl->p = (unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));
	if (hdl->p == NULL)
	{
		ret = -1;
		printf("func cltSocket_senddata() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}
	memcpy(hdl->p, buf, buflen);
	hdl->plen = buflen;

	return ret;
}

//客户端收报文
_declspec(dllexport)
int cltSocket_resvdata(void *handle/*in*/, unsigned char *buf/*in*/, int *buflen/*in  out*/)
{
	_SCK_HANDLE *hdl = NULL;
	int ret = 0;

	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		printf("func cltSocket_senddata() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}


	hdl = (_SCK_HANDLE *)handle;
	memcpy(buf, hdl->p, hdl->plen);
	*buflen = hdl->plen;
	//hdl->p = (unsigned char *)malloc(*buflen * sizeof(_SCK_HANDLE));
	return ret;
}


//4 客户端销毁环境
_declspec(dllexport)
int cltSocket_destory(void *handle)
{
	_SCK_HANDLE *hdl = NULL;
	int ret = 0;

	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocket_senddata() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}


	hdl = (_SCK_HANDLE *)handle;
	if (hdl->p)
	{
		free(hdl->p);
	}
	free(hdl);
	return 0;
}
/************************************************************************/
/*                        第二套api函数                                 */
/************************************************************************/
//代码 的复用 能力 一定 要提高 对 上来	0.0
_declspec(dllexport)
int cltSocket_init2(void **handle)
{
	return cltSocket_init(handle);
}

//客户端发报文
_declspec(dllexport)
int cltSocket_senddata2(void *handle, unsigned char *buf, int buflen)
{
	return cltSocket_senddata(handle, buf, buflen);
}

//客户端收报文
_declspec(dllexport)
int cltSocket_resvdata2(void *handle, unsigned char **buf, int *buflen)
{
	_SCK_HANDLE *hdl = NULL;
	unsigned char *tmp = NULL;
	int ret = 0;

	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -2;
		printf("func cltSocket_resvdata2() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return ret;
	}

	//handle = (_SCK_HANDLE *)malloc(sizeof(_SCK_HANDLE));
	hdl = (_SCK_HANDLE *)handle;
	tmp  = (unsigned char *)malloc(hdl->plen);
	if (tmp ==NULL) //就特么 少了 一个 等号
	{
		ret = -1;
		printf("func cltSocket_resvdata2() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}
	memcpy(tmp, hdl->p, hdl->plen);
	*buflen = hdl->plen;

	*buf = tmp;		//间接赋值
	return ret;
}
_declspec(dllexport)
int cltSocket_resvdata2_Free(unsigned char **buf)
{
	if (buf == NULL)
	{
		return -1;
	}
	if (*buf != NULL)
	{
		free(*buf);
	}
	*buf = NULL;	//* 实参的地址  去间接的修改实参的 值 重新初始化
	return 0;
}
//4 客户端销毁环境
_declspec(dllexport)
int cltSocket_destory2(void **handle)
{
	_SCK_HANDLE *tmp = NULL;
	if (handle == NULL)
	{
		return -1;
	}
	tmp = *handle;
	if (tmp != NULL)
	{
		if (tmp->p!=NULL)
		{
			free(tmp->p);
			tmp->p = NULL;		//严谨
		}
		free(tmp);	//* 实参的地址  去间接的修改实参的 值 重新初始化
	}
	*handle = NULL;
	return 0;
}


