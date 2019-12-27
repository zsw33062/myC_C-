#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MaxLine 2048


//��ȡ������
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
		if (pTmp == NULL)	//û�� = �Ⱥ�
		{
			continue;
		}
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)	//�� ��key �ǲ��� �������� �ǲ��� ��key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);	//mykey1 = myvalue111111111 ==> myvalue111111111
		pTmp = strchr(pTmp, '=');	//
		if (pTmp == NULL)	//û�� = �Ⱥ�
		{
			continue;
		}
		pTmp = pTmp + 1;	// strlen(pTmp)
		//
		//printf("pTmp:%s ", pTmp);
		//��ȡvalue ���
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
					//û������value
					printf("�����%s û������ value \n");
					goto End;
				}
				break;
			}
		}
		//��ȡvalue������
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
		//��ֵ
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
//д  ������
//ʵ������
//ѭ����ÿһ�У����key �������Ƿ���ڣ��������޸Ķ�Ӧvalue ֵ
//�������� �����ļ�ĩβ��� "key=value"
//�ѵ㣬����޸��ļ��� �е�ֵ
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

	fseek(fp, 0L, SEEK_END);//���ļ�ָ��� 0 λ�ÿ�ʼ �ƶ����ļ�ĩβ
	//��ȡ�ļ�����
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);//�����ó� ͷ��

	if (length > 1024 * 8)
	{
		rv = -3;
		printf("�ļ�����1024 * 8��nunsupport");
		goto End;
	}
	while (!feof(fp))
	{
		//��  ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}
		//key �ؼ��� �Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp==NULL)	//key�ؼ��� ���ڱ��У�copy ��filebuf ��
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else		//key�ؼ����ڱ��� �У��滻�ɵ� �У���copy ��filebuf ��
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//������ key
			iTag = 1;
		}
	}
	if (iTag == 0)//��key �ؼ��� ������ ׷��
	{
		fprintf(fp, "%s=%s\n", pKey, pValue);//���ո�ʽ�� ���ж�д �ļ�
	}
	else			//��key �ؼ��� ���ڣ������´����ļ�
	{
		if (fp!=NULL)
		{
			fclose(fp);
			fp = NULL;	//����Ұָ��
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