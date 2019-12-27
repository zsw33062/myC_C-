#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//char *p="abcd1122abcd333333abcd3323qqqq"  
//求字符串中 abcd的 出现的次数
//1	请 自定义函数接口，完成上述需求
//2	自定义的业务函数 和 main函数必须分开

void main0801()
{
	int ncount = 0;
	//strstr(str, str2);
	//初始化 让p 指针达到 查找的条件
	//strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
	//如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
	//char *p = "111abcd1122abcd333333abcd3323qqqqabcd";
	//do 
	//{
	//	p=strstr(p, "abcd");
	//	if (p != NULL)
	//	{
	//		ncount++;
	//		p = p + strlen("abcd");
	//	}
	//	else
	//	{
	//		break;
	//	}
	//} while (*p!='\0');
	char *p = "111abcd1122abcd333333abcd3323qqqqabcd";
	while (p = strstr(p, "abcd"))
	{
		ncount++;
		p = p + strlen("abcd");	//让p 指针 达到查找的条件
		if (*p == '\0')
		{
			break;
		}
	}
	printf("ncount:%d\n", ncount);
	printf("hello...\n");
	system("pause");
	return;
}
int getcount(char *mystr, char *sub, int *ncount)
{
	int ret = 0;
	int tempCount = 0;//
	//初始化  让p指针达到要查找的值
	char *p = mystr;
	//不要轻易改变形参 的 值
	if (mystr == NULL || sub == NULL || ncount == NULL)
	{
		ret = -1;
		printf("func getCount() err:%d  (mystr == NULL || sub == NULL || ncount == NULL)\n", ret);
		return -1;
	}
	while (p = strstr(p, sub))
	{
		tempCount++;
		p = p + strlen(sub);	//让p 指针 达到查找的条件
		if (*p == '\0')
		{
			break;
		}
	}
	*ncount = tempCount;	//间接复制 是指针存在的最大意义
	return 0;
}
void main()
{
	int ret = 0;
	char *p = "abcd1122abcd333333abcd3323qqqq";
	char *buf = NULL;
	int ncount = 0;
	ret = getcount(p, buf, &ncount);
	if (ret != 0)
	{
		printf("func getCount() err:%d\n", ret);
	}
	printf("ncount:%d\n", ncount);
	system("pause");
}