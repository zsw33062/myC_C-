#ifndef _OPENDESS_H_H
#define _OPENDESS_H_H
#endif // !_OPENDESS_H_H


#ifdef _cplusplus
extern "C"{
#endif
//�û�ʹ�õĺ���
	int DesEnc(
		unsigned char *pInData,
		int		   	  nInDataLen,
		unsigned char *pOutData,
		int		   	  *nOutDataLen);
//�û�ʹ�ú���des����
	int DesDec(
		unsigned char *pInData,
		int		   	  nInDataLen,
		unsigned char *pOutData,
		int		   	  *nOutDataLen);


#ifdef _cplusplus
}
#endif // _cplusplus

//��ҵ�� ҵ����뼯��ѵ��
