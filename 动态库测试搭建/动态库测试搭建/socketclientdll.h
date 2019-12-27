#ifndef _CLIENT_SOCKET_H_2
#define _CLIENT_SOCKET_H_2
#ifdef __cplusplus  
extern "C" {
#endif  

	/************************************************************************/
	/* 第二套 api 函数                                                      */
	/************************************************************************/

	int cltSocket_init2(void **handle); //5day

	//客户端发报文
	int cltSocket_senddata2(void *handle, unsigned char *buf, int buflen);

	//客户端收报文
	int cltSocket_resvdata2(void *hanle, unsigned char **buf, int *buflen);

	int cltSocket_resvdata2_Free(unsigned char **buf);
	//4 客户端销毁环境
	int cltSocket_destory2(void **handle);

#ifdef  __cplusplus  
}
#endif

#endif