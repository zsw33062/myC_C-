//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//演示， 指针数组的用法
//演示，找错误，注意return

//求关键字 在表中的位置
//一个入口 多个出口

//int searchKeyTable(const char *table[], const int size, const char *key, int *pos)
//{
//	int rv = 0;
//	int i = 0;
//	int inum = 0;
//	if (table == NULL || key == NULL || pos == NULL)
//	{
//		rv = -1;
//		printf("func searchKeyTable err %d\n", rv);
//		return rv;
//	}
//	//间接的证明 数组 做函数参数的退化
//	inum = (sizeof(table) / sizeof(*table));//都是指针
//
//	for (i = 0; i < size; i++)
//	{
//		if (strcmp(key, table[i]) == 0)
//		{
//			*pos = i;
//			//break;
//			return rv;
//		}
//	}
//	//没有找到
//	if (i == size)
//	{
//		*pos = -1;
//	}
//	return rv;
//}
//
//#define  DIM(a) (sizeof(a)/sizeof(*a))
//
//void main0401()
//{	
//	int inum = 0;
//	int pos = 0;
////	int a[10];
//	int i = 0;
//	//指针数组
//	char * c_keyword[] = {
//
//		"while",
//		"case",
//		"static",
//		"do"
//	};
//	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
//	//	===>带参数的宏   宏 展开
//	//searchKeyTable(c_keyword, (sizeof(c_keyword)/sizeof(*c_keyword)), "do", &pos);
//	printf("pos: %d\n", pos + 1);
//
//	searchKeyTable(c_keyword, DIM(c_keyword), "static", &pos);
//	printf("pos: %d\n", pos + 1);
//
//	printf("hello...\n");
//	system("pause");
//}
//
////main函数是操作系统 调用的函数
//在程序执行的时候可以向 main 函数 传递参数
/************************************************************************/
//argc 命令行参数
//argv 命令行 参数数组
//env 函数变量数组
//
//int main()
//int main(int argc)
//int main(int argc, char *argv[], char **env)

/************************************************************************/

//int main0402(int argc, char *argv[], char **env)//env 环境变量的值
//{											//操作系统 帮我们分配的内存
//	int i = 0;
//
//	printf("****************  Begin  argv  *************************\n");
//	printf("\n");
//	printf("\n");
//	for (i = 0; i < argc; i++)
//	{
//
//		printf("%s\n", argv[i]);
//	}
//	printf("\n");
//	printf("\n");
//	printf("****************  End	 argv  *************************\n");
//	printf("\n");
//	printf("\n");
//
//	printf("****************  Begin  env  *************************\n");
//	printf("\n");
//	printf("\n");
//	for (i = 0; env[i] != NULL; i++)//env 是以'\0' 结束的
//	{
//		printf("%s\n", env[i]);
//	}
//	printf("\n");
//	printf("\n");
//	printf("****************  End  env  *************************\n");
//	system("pause");
//	return 0;
//
//}
void main0403()
{
	int inum = 0;
	int pos = 0;
//	int a[10];
	int i = 0;
	//指针数组

	//指针数组的自我结束能力
	char *  c_keyword[] = {

		"while",
		"case",
		"static",
		"do",
		'\0'
	};
	char * c_keyword2[] = {

		"while",
		"case",
		"static",
		"do",
		0
	};
	char * c_keyword3[] = {

		"while",
		"case",
		"static",
		"do",
		NULL
	};
	/*for (i = 0; c_keyword != NULL; i++)
	{
	printf("%s \n", c_keyword[i]);
	}*/
	for (i = 0; c_keyword[i] != NULL; i++)
	{
		printf("%s \n", c_keyword[i]);
		
	}
	printf("\n.........\n");
	for (i = 0; c_keyword2[i] != NULL; i++)
	{
		printf("%s \n", c_keyword2[i]);
	}
	printf("\n.........\n");
	for (i = 0; c_keyword3[i] != NULL; i++)
	{
		printf("%s \n", c_keyword3[i]);
	}
	printf("\n.........\n");
	printf("hello...\n");
	system("pause");
}
