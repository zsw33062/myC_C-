//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//��ʾ�� ָ��������÷�
//��ʾ���Ҵ���ע��return

//��ؼ��� �ڱ��е�λ��
//һ����� �������

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
//	//��ӵ�֤�� ���� �������������˻�
//	inum = (sizeof(table) / sizeof(*table));//����ָ��
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
//	//û���ҵ�
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
//	//ָ������
//	char * c_keyword[] = {
//
//		"while",
//		"case",
//		"static",
//		"do"
//	};
//	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
//	//	===>�������ĺ�   �� չ��
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
////main�����ǲ���ϵͳ ���õĺ���
//�ڳ���ִ�е�ʱ������� main ���� ���ݲ���
/************************************************************************/
//argc �����в���
//argv ������ ��������
//env ������������
//
//int main()
//int main(int argc)
//int main(int argc, char *argv[], char **env)

/************************************************************************/

//int main0402(int argc, char *argv[], char **env)//env ����������ֵ
//{											//����ϵͳ �����Ƿ�����ڴ�
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
//	for (i = 0; env[i] != NULL; i++)//env ����'\0' ������
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
	//ָ������

	//ָ����������ҽ�������
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
