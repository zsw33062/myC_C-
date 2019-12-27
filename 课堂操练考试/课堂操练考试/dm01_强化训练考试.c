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
	p3 = (char **)malloc((num1 + num2)*sizeof(char *));	//里面装的是指针
	int tmplen = 0;
	if (p3==NULL)
	{
		return -1;
	}
	//根据 长度分配内存
	for (int i = 0; i < num1; i++,tmpi=i)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(tmplen /*+*/* sizeof(char));
		strcpy(p3[i], myp1[i]);
	//	tmpi = i;
	}
	//第二个内存空间 数据
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
	//排序
	for (int i = 0; i < tmplen; i++)
	{
		for (int j = i + 1; j < tmplen ; j++)
		{
/**/			if (strcmp(p3[i], p3[j])>0)
			{	//可以将内容 进行交换
				//也可以 进行指针的交换
				tmpP = p3[i];
				p3[i] = p3[j];
				p3[j] = tmpP;
			}
		}
	}
	//间接 赋值
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
{									//把二级指针指向二维内存释放掉
	int ret = 0;					//同时间接地释放掉实参的值
	char **p = NULL;				
	if (myp==NULL)
	{
		return ret;
	}
	p = *myp;//还原成二级指针

	if (p == NULL)
	{
		return ret;
	}
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	*myp = NULL;//间接赋值 是指针存在的最大意义
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
