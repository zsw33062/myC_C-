#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MaxLine 2048


//获取配置项
int GetCfgItem(char *pFilename/*in*/, char *pKey/*in*/, char *pValue /*in  out */, int *pValuelen/*out*/)
{
	int ret = 0;
	FILE *fp = NULL ;
	char *pTmp = NULL,*pBegin = NULL, *pEnd = NULL;
	char lineBuf[MaxLine];

	fp = fopen(pFilename, "r");
	if (fp == NULL)
	{
		ret = -1;
		return ret;
	}
	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(MaxLine));
		//fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		fgets(lineBuf,MaxLine,fp);
		//printf("lineBuf:%s ", lineBuf);

		pTmp = strchr(lineBuf, '=');	//
		if (pTmp == NULL)	//没有 = 等号
		{
			continue;
		}
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)	//判 断key 是不是 在所在行 是不是 有key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);	//mykey1 = myvalue111111111 ==> myvalue111111111
		pTmp = strchr(pTmp, '=');	//
		if (pTmp == NULL)	//没有 = 等号
		{
			continue;
		}
		pTmp = pTmp + 1;	// strlen(pTmp)
		//
		//printf("pTmp:%s ", pTmp);
		//获取value 起点
		while (1)
		{
			if (*pTmp == ' ')
			{
				pTmp++;
			}
			else
			{
				pBegin = pTmp;
				if(*pBegin == '\n')
				{
					//没有配置value
					printf("配置项：%s 没有配置 value \n");
					goto End;
				}
				break;
			}
		}
		//获取value结束点
		while (1)
		{
			if (*pTmp == ' ' || *pTmp == '\n')
			{
				break;
			}
			else
			{
				pTmp++;
			}
		}
		pEnd = pTmp;
		//赋值
		*pValuelen = pEnd - pBegin;
		memcpy(pValue, pBegin, (pEnd - pBegin));
	}

End:
	if (fp == NULL)
	{
		fclose(fp);
	}

	return 0;
}
//写  配置项
//实现流程
//循环读每一行，检查key 配置项是否存在，若存在修改对应value 值
//若不存在 ，在文件末尾添加 "key=value"
//难点，如何修改文件流 中的值
int WriteCfgItem(char *pFilename/*in*/, char *pKey/*in*/, char *pValue/*in*/, int Valuelen/*in*/)
{
	int rv = 0, iTag = 0, length = 0;
	FILE *fp = NULL;
	char lineBuf[MaxLine];
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char filebuf[1024 * 8];
	if (pFilename == NULL || pKey == NULL || pValue==NULL)
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}
	fp = fopen(pFilename, "r+");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
	}
	if (fp == NULL)
	{
		fp = fopen(pFilename, "w+t");
		if (fp==NULL)
		{
			rv = -3;
			printf("fopen() err. \n");
			goto End;
		}
		printf("fopen() err. \n");
	}

	fseek(fp, 0L, SEEK_END);//把文件指针从 0 位置开始 移动到文件末尾
	//获取文件长度
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);//重新置成 头部

	if (length > 1024 * 8)
	{
		rv = -3;
		printf("文件超过1024 * 8，nunsupport");
		goto End;
	}
	while (!feof(fp))
	{
		//读  每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}
		//key 关键字 是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp==NULL)	//key关键字 不在本行，copy 到filebuf 中
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else		//key关键字在本行 中，替换旧的 行，在copy 到filebuf 中
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在 key
			iTag = 1;
		}
	}
	if (iTag == 0)//若key 关键字 不存在 追加
	{
		fprintf(fp, "%s=%s\n", pKey, pValue);//按照格式化 进行读写 文件
	}
	else			//若key 关键字 存在，则重新创建文件
	{
		if (fp!=NULL)
		{
			fclose(fp);
			fp = NULL;	//避免野指针
		}
		fp = fopen(pFilename, "w+t");
		if (fp == NULL)
		{
			rv = -4;
			printf("fopen() err.  \n");
			goto End;
		}
		fputs(filebuf, fp);
	}
End:
	if (fp==NULL)
	{
		fclose(fp);
	}
	return rv;
}