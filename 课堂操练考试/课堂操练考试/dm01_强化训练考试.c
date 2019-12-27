#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sort(char **myp1/*in*/, int num1, char(*myp2)[30], int num2, char ***myp3, int *num3)
{
	int ret = 0;
	//int i, j;
	char **p3=NULL;
	int tmpi = 0;
	char *tmpP=NULL;
	p3 = (char **)malloc((num1 + num2)*sizeof(char *));	//����װ����ָ��
	int tmplen = 0;
	if (p3==NULL)
	{
		return -1;
	}
	//���� ���ȷ����ڴ�
	for (int i = 0; i < num1; i++,tmpi=i)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(tmplen /*+*/* sizeof(char));
		strcpy(p3[i], myp1[i]);
	//	tmpi = i;
	}
	//�ڶ����ڴ�ռ� ����
	for (int j = 0, i = tmpi; j < num2; j++, i++)
	{
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char *)malloc(tmplen /*+*/ *sizeof(char));
		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i], myp2[j]);
		//tmpi = i;
	}
	tmplen = num1 + num2;
	//����
	for (int i = 0; i < tmplen; i++)
	{
		for (int j = i + 1; j < tmplen ; j++)
		{
/**/			if (strcmp(p3[i], p3[j])>0)
			{	//���Խ����� ���н���
				//Ҳ���� ����ָ��Ľ���
				tmpP = p3[i];
				p3[i] = p3[j];
				p3[j] = tmpP;
			}
		}
	}
	//��� ��ֵ
	*num3 = tmplen;
	*myp3 = p3;
	return ret;
}
int sortFree01(char **p, int len)
{
	int ret = 0;
	if (p == NULL)
	{
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	return ret;
}
int sortFree02(char ***myp, int len)///???????????????
{									//�Ѷ���ָ��ָ���ά�ڴ��ͷŵ�
	int ret = 0;					//ͬʱ��ӵ��ͷŵ�ʵ�ε�ֵ
	char **p = NULL;				
	if (myp==NULL)
	{
		return ret;
	}
	p = *myp;//��ԭ�ɶ���ָ��

	if (p == NULL)
	{
		return ret;
	}
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	*myp = NULL;//��Ӹ�ֵ ��ָ����ڵ��������
	return ret;
}
int main01()
{	
	int ret = 0;
	char *p1[] = { "aaaaaaa", "33333333", "bbbbbbbb" };
	char buf2[10][30] = { "111111111", "ccccccc", "222222222" };
	char **p3 = NULL;
	int len1, len2, len3;
	int i = 0;
	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;
	//int sort(char **myp1/*in*/, int num1, char(*myp2)[30], int num2, char ***p3, int *num3)
	ret=sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("func sort() err:%d\n",ret);
		return ret;
	}
	for (i = 0; i < len3; i++)
	{
		printf("%s\n", p3[i]);
	}
	printf("hello...\n");
	system("pause");
	return 0;
}
