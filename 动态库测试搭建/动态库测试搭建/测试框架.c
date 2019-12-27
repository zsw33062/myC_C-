#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mysocketclient.h"
#include "socketclientdll.h"
#pragma comment(lib,"mysocketclient.lib")
int main0101()
{
	int ret = 0;
	void *handle = NULL;
	char buf[128];		/*in*/
	int  buflen = 3;	/*in*/

	char outbuf[128];	/*out*/
	int  outbuflen = 3;	/*out*/
	strcpy(buf, "dssssssssdswdfafd");
	ret = cltSocket_init(&handle/*out*/); //5day
	if (ret != 0)
	{
		printf("func cltSocket_init() err:%d \n", ret);
		return ret;
	}

	//�ͻ��˷�����
	ret = cltSocket_senddata(handle/*in*/, buf/*in*/, buflen/*in*/);
	if (ret != 0)
	{
		printf("func cltSocket_senddata() err:%d \n", ret);
		return ret;
	}


	//�ͻ����ձ���
	ret = cltSocket_resvdata(handle/*in*/, outbuf/*in*/, &outbuflen/*in  out*/);
	if (ret != 0)
	{
		printf("func cltSocket_resvdata() err:%d \n", ret);
		return ret;
	}
	//4 �ͻ������ٻ���
	int cltSocket_destory(handle);
	if (ret != 0)
	{
		printf("func cltSocket_destory() err:%d \n", ret);
		return ret;
	}

	system("pause");
	return ret;
}

//������ĿҪ���� ��̬��
int main0102()
{
	int ret = 0;
	void *handle = NULL;
	char buf[128];		/*in*/
	int  buflen = 3;	/*in*/		

	
	//char outbuf[128];	/*out*/
	//int  outbuflen = 3;	/*out*/
	//������  ���÷����ڴ� �����ڴ� ���ͷ��ڴ� ���� ���ú�����

	char *pout = NULL;
	int poutlen = 0;
	strcpy(buf, "dssssssssdswdfafd");
	ret = cltSocket_init2(&handle);
	if (ret != 0)
	{
		printf("func cltSocket_init2() err:%d \n", ret);
		return ret;
	}

	//�ͻ��˷�����
	ret = cltSocket_senddata2(handle, buf, buflen);
	if (ret != 0)
	{
		printf("func cltSocket_senddata2() err:%d \n", ret);
		return ret;
	}

	//�ͻ����ձ���
	//int cltSocket_resvdata2(void *handle, unsigned char **buf, int *buflen);
	ret = cltSocket_resvdata2(handle, &pout, &poutlen); 
	if (ret != 0)
	{
		printf("func cltSocket_resvdata2() err:%d \n", ret);
		return ret;
	}
	
	//4 �ͻ������ٻ���
	
	ret = cltSocket_resvdata2_Free(&pout);	//���� Ұָ�� ��outbuf ��ָ����ڴ��ͷ�
	if (ret != 0)
	{
		printf("func cltSocket_destory2_Free() err:%d \n", ret);
		return ret;
	}
	ret = cltSocket_destory2(&handle);
	//int cltSocket_destory2(void **handle);
	if (ret != 0)
	{
		printf("func cltSocket_init() err:%d \n", ret);
		return ret;
	}
	system("pause");					//ͬ�°� outbuf ������ֵnull
	return 0;
}



