#ifndef _CLIENT_SOCKET_H_
#define _CLIENT_SOCKET_H_

#ifdef __cplusplus  
extern "C" {
#endif  
	
	/************************************************************************/
	/* ��һ�� api ����                                                      */
	/************************************************************************/
	//�ͻ��˳�ʼ������
	int cltSocket_init(void **handle); //5day

	//�ͻ��˷�����
	int cltSocket_senddata(void *handle, unsigned char *buf, int buflen);

	//�ͻ����ձ���
	int cltSocket_resvdata(void *hanle, unsigned char *buf, int *buflen);

	//4 �ͻ������ٻ���
	int cltSocket_destory(void *handle);

	
#ifdef  __cplusplus  
}
#endif

#endif