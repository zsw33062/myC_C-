#ifndef _OPENDESS_H_H
#define _OPENDESS_H_H
#endif // !_OPENDESS_H_H


#ifdef _cplusplus
extern "C"{
#endif
//用户使用的函数
	int DesEnc(
		unsigned char *pInData,
		int		   	  nInDataLen,
		unsigned char *pOutData,
		int		   	  *nOutDataLen);
//用户使用函数des解密
	int DesDec(
		unsigned char *pInData,
		int		   	  nInDataLen,
		unsigned char *pOutData,
		int		   	  *nOutDataLen);


#ifdef _cplusplus
}
#endif // _cplusplus

//企业级 业务代码集成训练
