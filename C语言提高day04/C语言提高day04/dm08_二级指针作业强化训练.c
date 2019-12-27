#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int spitString(const char *buf1, char c, char **buf2, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	//1	p和ptmp 初始化
	p = buf1;
	pTmp = buf1;
	do 
	{
		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
		p = strchr(p, c);
		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
		//可以查找字符串s中首次出现字符c的位置
		if (p!=NULL)
		{
			if (p-pTmp>0)
			{
				strncpy(buf2[tmpcount], pTmp, p - pTmp);
				buf2[tmpcount][p - pTmp] = '\0';//把第一行数据 编程 C风格字符串
				tmpcount++;
				//3	重新 让p和ptmp达到下一次检索的条件
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
	//释放内存
	for (i = 0; i < 10; i++)
	{
		free(myArray[i]);
	}
	printf("hello...\n");
	system("pause");
	return;
}