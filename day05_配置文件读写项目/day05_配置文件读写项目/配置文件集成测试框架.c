#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define CPGNAME "e:/mycfg.ini"

void mymenu()
{
	printf("\n====================================\n");
	printf("1 测试写 配置文件\n");
	printf("2 测试读 配置文件\n");
	printf("0 退出\n");
	printf("\n====================================\n");
}
//获取 配置项
int TGetCfg()
{
	//读 配置项
	int	 ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	int	 vlen = 0;

	printf("\n请键入 key：");
	scanf("%s", name);
	//printf("\n请键入 value：");
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
//写  配置项
int TWriteCfg()
{
	//写  配置项
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	
	printf("\n请键入 key：");
	scanf("%s", name);
	printf("\n请键入 value：");
	scanf("%s", value);
	int len = strlen(value);
	ret = WriteCfgItem(CPGNAME/*in*/, name/*in*/, value/*in*/, len/*in*/);
	if (ret != 0)
	{
		printf("func WriteCfgItem() err,%d\n", ret);
	}
	printf("你的输入是%s=%s\n",name, value);
	return ret;
}

void main()
{	
	int choice;
	
	for (;;)
	{
		//显示一个菜单
		mymenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			TWriteCfg();		//写  配置项
				break;
		case 2:
			TGetCfg();			//读 配置项
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
