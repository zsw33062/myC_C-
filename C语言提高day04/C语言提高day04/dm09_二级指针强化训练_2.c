#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//int ** spitString03(const char *buf1, char c, int *count)
//{
//	//��ȷ�ط��� �ڴ� �ж����� ��������ڴ�
//	char *p = NULL;
//	char *pTmp = NULL;
//	int tmpcount = 0;
//
//	char **myp;
//	//1	p��ptmp ��ʼ��
//	p = buf1;
//	pTmp = buf1;
//
//
//	//��һ�� ��� count
//	do
//	{
//		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
//		p = strchr(p, c);
//		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
//		//���Բ����ַ���s���״γ����ַ�c��λ��
//		if (p != NULL)
//		{
//			if (p - pTmp > 0)
//			{
//				tmpcount++;
//				//3	���� ��p��ptmp�ﵽ��һ�μ���������
//				pTmp = p = p + 1;
//			}
//		}
//		else
//		{
//			break;
//		}
//	} while (*p != '\0');
//	*count = tmpcount;
//
//	//���ݶ����� ��ȷ �ķ����ڴ�
//	myp = (char **)malloc(tmpcount * sizeof(char *) );
//	//////////////////////////////////////////////////////////////////////////
//	if (myp==NULL)
//	{
//		return NULL;
//	}
//
//	//���� ��ʼ��
//	tmpcount = 0;
//	p = buf1;
//	pTmp = buf1;
//
//	do
//	{
//		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
//		p = strchr(p, c);
//		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
//		//���Բ����ַ���s���״γ����ַ�c��λ��
//		if (p != NULL)
//		{
//			if (p - pTmp > 0)
//			{
//				int len = p - pTmp + 1;
//				myp[tmpcount] = (char *)malloc(len * sizeof(char));
//				if (myp[tmpcount]==NULL)
//				{
//					return NULL;
//				}
//				strncpy(myp[tmpcount], pTmp, p - pTmp);
//				myp[tmpcount][p - pTmp] = '\0';
//
//				tmpcount++;
//				//3	���� ��p��ptmp�ﵽ��һ�μ���������
//				pTmp = p = p + 1;
//			}
//		}
//		else
//		{
//			break;
//		}
//	} while (*p != '\0');
//	//myp = (char **)malloc(tmpcount*sizeof(char *));
//	//if (myp == NULL)
//	//{
//	//	return NULL;
//	//}
//	*count = tmpcount;
//	return myp;
//}
int spitString0401(const char *buf1, char c, char ***myp3,int *count)
{
	//��ȷ�ط��� �ڴ� �ж����� ��������ڴ�
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	
	//char **myp;
	//*myp3 = myp;
	//*myp3 = myp;
	//1	p��ptmp ��ʼ��
	p = buf1;
	pTmp = buf1;


	//��һ�� ��� count
	do
	{
		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
		//���Բ����ַ���s���״γ����ַ�c��λ��
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				//3	���� ��p��ptmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpcount;

	//���ݶ����� ��ȷ �ķ����ڴ�
	*myp3 = (char **)malloc(tmpcount * sizeof(char *));
	//////////////////////////////////////////////////////////////////////////
	if (myp3 == NULL)
	{
		return -1;
	}

	//���� ��ʼ��
	tmpcount = 0;
	p = buf1;
	pTmp = buf1;

	do
	{
		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
		//���Բ����ַ���s���״γ����ַ�c��λ��
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				(*myp3)[tmpcount] = (char *)malloc(len * sizeof(char));
				if ((*myp3)[tmpcount] == NULL)
				{
					return -2;
				}
				strncpy((*myp3)[tmpcount], pTmp, p - pTmp);
				(*myp3)[tmpcount][p - pTmp] = '\0';

				tmpcount++;
				//3	���� ��p��ptmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	//myp = (char **)malloc(tmpcount*sizeof(char *));
	//if (myp == NULL)
	//{
	//	return NULL;
	//}
	*count = tmpcount;
	return 0;
}
void FreeMem(char **myp, int count)
{
		int i = 0;
	
		if (myp == NULL)
		{
			return ;
		}
		for (int i = 0; i < count; i++)
		{
			if (myp[i] != NULL)
			{
				free(myp[i]);
			}

		}
		if (myp != NULL)
		{
			free(myp);
		}
}
void FreeMem3(char ***p, int count)
{
	int i = 0;
	char **myp = NULL;
	if (myp == NULL)
	{
		return;
	}
	myp = *p;
	for (int i = 0; i < count; i++)
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
		}

	}
	if (myp != NULL)
	{
		free(myp);
	}
	*p == NULL;//�Ѷ���ָ��ʵ�� �޸ĳ�null
}


int spitString0402(const char *buf1, char c, char ***myp3,int *count)
{
	//��ȷ�ط��� �ڴ� �ж����� ��������ڴ�
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	int ret = 0;
	char **myp;
	//1	p��ptmp ��ʼ��
	p = buf1;
	pTmp = buf1;


	//��һ�� ��� count
	do
	{
		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
		//���Բ����ַ���s���״γ����ַ�c��λ��
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				//3	���� ��p��ptmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpcount;

	//���ݶ����� ��ȷ �ķ����ڴ�
	myp = (char **)malloc(tmpcount * sizeof(char *) );
	//////////////////////////////////////////////////////////////////////////
	if (myp==NULL)
	{
		ret = -1;
		printf("func spitString0402() err:%d  (tmpcount * sizeof(char *) )",ret);
		goto END;
		return ret;
	}
	memset(myp, 0, sizeof(tmpcount*sizeof(char *)));
	//���� ��ʼ��
	tmpcount = 0;
	p = buf1;
	pTmp = buf1;

	do
	{
		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
		//���Բ����ַ���s���״γ����ַ�c��λ��
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				myp[tmpcount] = (char *)malloc(len * sizeof(char));
				if (myp[tmpcount]==NULL)
				{
					ret = -1;
					printf("func spitString0402() err:%d  (len * sizeof(char)", ret);
					goto END;
					return NULL;
					//return NULL;
				}
				strncpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p - pTmp] = '\0';

				tmpcount++;
				//3	���� ��p��ptmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	//myp = (char **)malloc(tmpcount*sizeof(char *));
	//if (myp == NULL)
	//{
	//	return NULL;
	//}
END:	
	if (ret!=0)//ʧ��
	{
		/*if (myp==NULL)
		{
		return ret;
		}
		for (int i = 0; i < tmpcount; i++)
		{
		if (myp[i]!=NULL)
		{
		free(myp[i]);
		}

		}
		if (myp!=NULL)
		{
		free(myp);
		}*/
		FreeMem3(&myp,*count);
	}
	else
	{
		*myp3 = myp;	//�ɹ�
	}
	*count = tmpcount;
	return ret;
}

int main0901()
{
	int ret = 0;
	int i = 0;
	char *p1 = "abcdef,acccccd,eeeeee,aaaaa,e3eeeeee,sssssss";
	char cTem = ',';
	int nCount;

	char **myArray = NULL;

	//myArray = (char **)malloc(10 * sizeof(char *));	//char *array[10]
	//if (myArray == NULL)
	//{
	//	return;
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	myArray[i] = (char *)malloc(30 * sizeof(char));
	//}
	ret = spitString0402(p1, cTem, &myArray,&nCount);
	if (ret != 0)
	{
		printf("func spitString()err:%d\n", ret);
		return ret;
	}

	for (i = 0; i < nCount; i++)
	{
		printf("%s\n", myArray[i]);
	}
	//�ͷ��ڴ�
	for (i = 0; i < nCount; i++)
	{
		free(myArray[i]);
	}
	printf("hello...\n");
	system("pause");
	return 0;
}