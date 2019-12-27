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
	while (isspace(in[i]) && in[i] != '0')// ���е� �߼���
	{
		//���ǵ� �� �ڼ� ����
		i++;
	}
	while (isspace(in[j] && j > 0))
	{
		j--;
	}
	str_count = j - i + 1;	//��������ʼλ��

	memcpy(out, in + i, str_count);
	out[str_count] = '\0';

	return 0;
}
//һ��� �İѹ���ʵ��
//1  ��keyvaluebuf �ַ��в��ҹؼ���keybuf
//2  �ٲ���=
//3  ȥ�ո�

	/***********************************************************************
	3		��ֵ�ԣ�key1=value1���ַ������ڿ����о���ʹ�ã�
		Ҫ��1 �����Լ�����һ����ڣ�ʵ�ָ���key ��ȡvalue��40 ��
		Ҫ��2 ����д����������30��
		Ҫ��3 ����ֵ���м� ������n��ո���ȥ���ո� 30��
			ע�⣺��ֵ���ַ���ʽ��������:
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
	//1 ����key�ǲ�����ĸ����
	p = keyvaluebuf;//��ʼ�� ����ָ�����
	p = strstr(p, keybuf);
	if (p==NULL)
	{
		return -1;
	}
	//�ø���ָ����� ���³�ʼ��  ���´ﵽ ��һ�μ���������
	p = p + strlen(keybuf);

	//2 ���� ��û��= ��

	p = strstr(p, "=");
	
	//�ø���ָ����� ���³�ʼ��  ���´ﵽ ��һ�μ���������
	p = p + strlen("=");
	//3 �ڵȺź� ȥ���ո�

	ret = trim_str1102(p, valuebuf);//�����ķ���ֵ  �쳣��Ҫ
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