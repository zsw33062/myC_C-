#ifndef _CLIENT_SOCKET_H_2
#define _CLIENT_SOCKET_H_2
#ifdef __cplusplus  
extern "C" {
#endif  

	/************************************************************************/
	/* �ڶ��� api ����                                                      */
	/************************************************************************/

	int cltSocket_init2(void **handle); //5day

	//�ͻ��˷�����
	int cltSocket_senddata2(void *handle, unsigned char *buf, int buflen);

	//�ͻ����ձ���
	int cltSocket_resvdata2(void *hanle, unsigned char **buf, int *buflen);

	int cltSocket_resvdata2_Free(unsigned char **buf);
	//4 �ͻ������ٻ���
	int cltSocket_destory2(void **handle);

#ifdef  __cplusplus  
}
#endif

#endif