#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int spitString(const char *buf1, char c, char **buf2, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	//1	p��ptmp ��ʼ��
	p = buf1;
	pTmp = buf1;
	do 
	{
		//2	���ϼ���������λ�� p ���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		//strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)��
		//���Բ����ַ���s���״γ����ַ�c��λ��
		if (p!=NULL)
		{
			if (p-pTmp>0)
			{
				strncpy(buf2[tmpcount], pTmp, p - pTmp);
				buf2[tmpcount][p - pTmp] = '\0';//�ѵ�һ������ ��� C����ַ���
				tmpcount++;
				//3	���� ��p��ptmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p!='\0');
	*count = tmpcount;
	return 0;
}

int main0801()
{	
	int ret = 0;
	int i = 0;
	char *p1 = "abcdef,acccccd,eeeeee,aaaaa,e3eeeeee,sssssss";
	char cTem = ',';
	int nCount;

	char **myArray = NULL;
	
	myArray = (char **)malloc(10 * sizeof(char *));	//char *array[10]
	if (myArray == NULL)
	{
		return;
	}
	for (i = 0; i < 10; i++)
	{
		myArray[i] = (char *)malloc(30 * sizeof(char));
	}
	ret = spitString(p1, cTem, myArray, &nCount);
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
	for (i = 0; i < 10; i++)
	{
		free(myArray[i]);
	}
	printf("hello...\n");
	system("pause");
	return;
}