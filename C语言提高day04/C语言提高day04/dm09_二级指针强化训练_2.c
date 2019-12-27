#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//int ** spitString03(const char *buf1, char c, int *count)
//{
//	//精确地分配 内存 有多少行 分配多少内存
//	char *p = NULL;
//	char *pTmp = NULL;
//	int tmpcount = 0;
//
//	char **myp;
//	//1	p和ptmp 初始化
//	p = buf1;
//	pTmp = buf1;
//
//
//	//第一遍 求出 count
//	do
//	{
//		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
//		p = strchr(p, c);
//		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
//		//可以查找字符串s中首次出现字符c的位置
//		if (p != NULL)
//		{
//			if (p - pTmp > 0)
//			{
//				tmpcount++;
//				//3	重新 让p和ptmp达到下一次检索的条件
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
//	//根据多少行 精确 的分配内存
//	myp = (char **)malloc(tmpcount * sizeof(char *) );
//	//////////////////////////////////////////////////////////////////////////
//	if (myp==NULL)
//	{
//		return NULL;
//	}
//
//	//重新 初始化
//	tmpcount = 0;
//	p = buf1;
//	pTmp = buf1;
//
//	do
//	{
//		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
//		p = strchr(p, c);
//		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
//		//可以查找字符串s中首次出现字符c的位置
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
//				//3	重新 让p和ptmp达到下一次检索的条件
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
	//精确地分配 内存 有多少行 分配多少内存
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	
	//char **myp;
	//*myp3 = myp;
	//*myp3 = myp;
	//1	p和ptmp 初始化
	p = buf1;
	pTmp = buf1;


	//第一遍 求出 count
	do
	{
		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
		p = strchr(p, c);
		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
		//可以查找字符串s中首次出现字符c的位置
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				//3	重新 让p和ptmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpcount;

	//根据多少行 精确 的分配内存
	*myp3 = (char **)malloc(tmpcount * sizeof(char *));
	//////////////////////////////////////////////////////////////////////////
	if (myp3 == NULL)
	{
		return -1;
	}

	//重新 初始化
	tmpcount = 0;
	p = buf1;
	pTmp = buf1;

	do
	{
		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
		p = strchr(p, c);
		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
		//可以查找字符串s中首次出现字符c的位置
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
				//3	重新 让p和ptmp达到下一次检索的条件
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
	*p == NULL;//把二级指针实参 修改成null
}


int spitString0402(const char *buf1, char c, char ***myp3,int *count)
{
	//精确地分配 内存 有多少行 分配多少内存
	char *p = NULL;
	char *pTmp = NULL;
	int tmpcount = 0;
	int ret = 0;
	char **myp;
	//1	p和ptmp 初始化
	p = buf1;
	pTmp = buf1;


	//第一遍 求出 count
	do
	{
		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
		p = strchr(p, c);
		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
		//可以查找字符串s中首次出现字符c的位置
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				//3	重新 让p和ptmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpcount;

	//根据多少行 精确 的分配内存
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
	//重新 初始化
	tmpcount = 0;
	p = buf1;
	pTmp = buf1;

	do
	{
		//2	符合检索条件的位置 p 后移 形成差值 挖字符串
		p = strchr(p, c);
		//strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，
		//可以查找字符串s中首次出现字符c的位置
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
				//3	重新 让p和ptmp达到下一次检索的条件
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
	if (ret!=0)//失败
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
		*myp3 = myp;	//成功
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
	//释放内存
	for (i = 0; i < nCount; i++)
	{
		free(myArray[i]);
	}
	printf("hello...\n");
	system("pause");
	return 0;
}