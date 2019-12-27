#ifndef _CLIENT_SOCKET_H_
#define _CLIENT_SOCKET_H_

#ifdef __cplusplus  
extern "C" {
#endif  
	
	/************************************************************************/
	/* 第一套 api 函数                                                      */
	/************************************************************************/
	//客户端初始化环境
	int cltSocket_init(void **handle); //5day

	//客户端发报文
	int cltSocket_senddata(void *handle, unsigned char *buf, int buflen);

	//客户端收报文
	int cltSocket_resvdata(void *hanle, unsigned char *buf, int *buflen);

	//4 客户端销毁环境
	int cltSocket_destory(void *handle);

	
#ifdef  __cplusplus  
}
#endif

#endif