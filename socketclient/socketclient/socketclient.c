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
1.��ʼ������
2.�������������ڴ湩��������ʹ��
3.handle ���������Դ���ڴ��׵�ַ
4.ʹ��void ָ����Ϊ�˶����ݵķ�װ�������߲�֪�����ݽṹ�����ǵײ㿪����֪�����ݽṹ
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

//�ͻ��˷�����
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
	sh->buf = (char *)malloc(sizeof(char)*buflen);// �����ڴ�ռ�
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

//�ͻ����ձ���
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
	sh = (SCK_HANDLE *)handle;// �����߲�֪���������ͣ��ײ㿪����֪����������

	memcpy(buf, sh->buf, sh->buflen);
	*buflen = sh->buflen;

	return ret;

}

/*
1.�ͻ������ٻ���
2.����handle �ͷ����ڴ�ռ�
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
	sh = (SCK_HANDLE *)handle;// �����߲�֪���������ͣ��ײ㿪����֪����������

	if (sh->buf != NULL)//�ͷ�buf���ڴ�
	{
		free(sh->buf);
		sh->buf = NULL;
	}
	free(sh);

	return ret;
}
