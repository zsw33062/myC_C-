#ifndef _CFG_OP_H_
#define _CFG_OP_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */



//��ȡ ������
int GetCfgItem(char *pFilename/*in*/, char *pKey/*in*/, char *pValue /*in  out */, int *pValuelen/*out*/);
//д  ������
int WriteCfgItem(char *pFilename/*in*/, char *pItemName/*in*/, char *pItemValue/*in*/, int itemValuelen/*in*/);


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // _CFG_OP_H_