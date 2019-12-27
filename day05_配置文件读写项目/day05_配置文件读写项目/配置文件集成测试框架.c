#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define CPGNAME "e:/mycfg.ini"

void mymenu()
{
	printf("\n====================================\n");
	printf("1 ����д �����ļ�\n");
	printf("2 ���Զ� �����ļ�\n");
	printf("0 �˳�\n");
	printf("\n====================================\n");
}
//��ȡ ������
int TGetCfg()
{
	//�� ������
	int	 ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	int	 vlen = 0;

	printf("\n����� key��");
	scanf("%s", name);
	//printf("\n����� value��");
	//scanf("%s", value);

	ret = GetCfgItem(CPGNAME/*in*/, name/*in*/, value/*in*/, &vlen/*out*/);
	if (ret != 0)
	{
		printf("func WriteCfgItem() err,%d\n", ret);
		return ret;
	}
	
	printf("value:%s\n", value);
		
	return 0;
}
//д  ������
int TWriteCfg()
{
	//д  ������
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	
	printf("\n����� key��");
	scanf("%s", name);
	printf("\n����� value��");
	scanf("%s", value);
	int len = strlen(value);
	ret = WriteCfgItem(CPGNAME/*in*/, name/*in*/, value/*in*/, len/*in*/);
	if (ret != 0)
	{
		printf("func WriteCfgItem() err,%d\n", ret);
	}
	printf("���������%s=%s\n",name, value);
	return ret;
}

void main()
{	
	int choice;
	
	for (;;)
	{
		//��ʾһ���˵�
		mymenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			TWriteCfg();		//д  ������
				break;
		case 2:
			TGetCfg();			//�� ������
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}
	printf("hello...\n");
	system("pause");
}
