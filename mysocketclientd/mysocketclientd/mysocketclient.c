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

}_SCK_HANDLE;	//��̬��  �ڲ������࣬�����ò��Գ����ϲ�Ӧ��֪����
//�������͵ķ�װ



_declspec(dllexport)
int cltSocket_init(void **handle/*out*/) //5day
{

	_SCK_HANDLE *hdl = NULL;
	int ret = 0;
	printf("func cltSocket_init() begin\n");
	hdl = (_SCK_HANDLE *)malloc(sizeof(_SCK_HANDLE));	//��ָ��ָ����ڴ�ռ� ��ֵ ��0
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

//�ͻ��˷�����
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

//�ͻ����ձ���
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


//4 �ͻ������ٻ���
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
/*                        �ڶ���api����                                 */
/************************************************************************/
//���� �ĸ��� ���� һ�� Ҫ��� �� ����	0.0
_declspec(dllexport)
int cltSocket_init2(void **handle)
{
	return cltSocket_init(handle);
}

//�ͻ��˷�����
_declspec(dllexport)
int cltSocket_senddata2(void *handle, unsigned char *buf, int buflen)
{
	return cltSocket_senddata(handle, buf, buflen);
}

//�ͻ����ձ���
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
	if (tmp ==NULL) //����ô ���� һ�� �Ⱥ�
	{
		ret = -1;
		printf("func cltSocket_resvdata2() err %d \n(unsigned char *)malloc(buflen* sizeof(_SCK_HANDLE));", ret);
		return -1;
	}
	memcpy(tmp, hdl->p, hdl->plen);
	*buflen = hdl->plen;

	*buf = tmp;		//��Ӹ�ֵ
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
	*buf = NULL;	//* ʵ�εĵ�ַ  ȥ��ӵ��޸�ʵ�ε� ֵ ���³�ʼ��
	return 0;
}
//4 �ͻ������ٻ���
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
			tmp->p = NULL;		//�Ͻ�
		}
		free(tmp);	//* ʵ�εĵ�ַ  ȥ��ӵ��޸�ʵ�ε� ֵ ���³�ʼ��
	}
	*handle = NULL;
	return 0;
}


