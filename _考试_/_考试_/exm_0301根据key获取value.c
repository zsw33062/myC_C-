#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int trim_str1102(char *in, char *out)
{
	int i = 0;
	int j = strlen(in) - 1;
	int str_count = 0;
	while (isspace(in[i]) && in[i] != '0')// 其中的 逻辑性
	{
		//还是得 靠 内家 功夫
		i++;
	}
	while (isspace(in[j] && j > 0))
	{
		j--;
	}
	str_count = j - i + 1;	//拷贝的起始位置

	memcpy(out, in + i, str_count);
	out[str_count] = '\0';

	return 0;
}
//一层层 的把功能实现
//1  在keyvaluebuf 字符中查找关键字keybuf
//2  再查找=
//3  去空格

	/***********************************************************************
	3		键值对（key1=value1）字符串，在开发中经常使用：
		要求1 ：请自己定义一个借口，实现根据key 获取value：40 分
		要求2 ：编写测试用例。30分
		要求3 ：键值对中间 可能有n多空格，请去除空格 30分
			注意：键值对字符格式可能如下:
				"key1=value2"
				"key2=              value2"
				"key3  = value3"
				"key4          =value4"
				"key5   =    "
				"key6     = "
				"key7    =     "
	                                                                      */
	/************************************************************************/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	char *p = NULL;
	int ret = 0;
	//int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
	if (keyvaluebuf==NULL||keybuf==NULL||valuebuf==NULL)
	{
		printf("keyvaluebuf==NULL||keybuf==NULL||valuebuf==NULL)  err");
		return -1;
	}
	//1 查找key是不是在母串中
	p = keyvaluebuf;//初始化 辅助指针变量
	p = strstr(p, keybuf);
	if (p==NULL)
	{
		return -1;
	}
	//让辅助指针变量 重新初始化  重新达到 下一次检索的条件
	p = p + strlen(keybuf);

	//2 看看 有没有= 号

	p = strstr(p, "=");
	
	//让辅助指针变量 重新初始化  重新达到 下一次检索的条件
	p = p + strlen("=");
	//3 在等号后 去掉空格

	ret = trim_str1102(p, valuebuf);//函数的返回值  异常重要
	if (ret != 0)
	{
		printf("func trim_str1102() err: %d\n", ret);
		return 0;
	}
	return ret;
}
void main0301()
{	
//	getKeyByValue("key1=value1", "key1", buf, &len);

	int ret = 0;
	char *keyandvalue = "key1 =     value2";
	char *key = "key1";
	char *buf = malloc(1024);
	memset(buf, 0, sizeof(buf));
	int  buflen = 0;
	ret=getKeyByValue(keyandvalue, key, buf, &buflen);
	if (ret != 0)
	{
		printf("func getKeyByValue() err: %d\n", ret);
		system("pause");
		return;
	}
	printf("buf:%s\n",buf);
	system("pause");
	return;
}