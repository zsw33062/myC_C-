#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main01_fputs()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/2.txt";	//ͳһ��45�� ��Linux ��Windows 
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	fp = fopen(filename2, "r+");		//�Զ�д�ķ�ʽ��һ�����ڵ��ļ�
	if (fp == NULL)
	{
		printf("func fopen() err \n");
	}
	printf("�򿪳ɹ�\n");

	/*for (i = 0; i < strlen(a); i++)
	{
	fputc(a[i], fp);
	}*/
	fputs(a, fp);

	fclose(fp);				//fp���  �ڴ����׵�ַ ����Դ���׵�ַ
}
char * myfgets(char *myp, int max, FILE * fp)
{
	strcpy(myp, "aaaaa");
	return myp;
}

void main01_fgets()
{
	int i = 0;
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	char *filename2 = "c:/22.txt";	//ͳһ��45�� ��Linux ��Windows 
	//char a[30] = "abcdefghijklmnopqrstuvwxyz";
	char buf[1024];
	//fp = fopen(filename2, "r+");		//�Զ�д�ķ�ʽ��һ�����ڵ��ļ� ����ļ������� ����
	fp = fopen(filename2, "r+");		//�Զ�д�ķ�ʽ��һ�����ڵ��ļ� ����ļ������� �½�
	if (fp == NULL)						//
	{
		printf("func fopen() err \n");
	}
	printf("�򿪳ɹ�\n");
	//1 //C ������ ��һ��һ�е�copy���ݵ�buf ָ�� ��ָ���ڴ�ռ��� �����C �����ַ���
	//2 �� \nҲ���������ǵ�buff��
	//3 �ڴ������������ڴ��ַ  +   �ڴ�ĳ��ȣ�
	while (!feof(fp))
	{	//_Check_return_opt_ _CRTIMP char * __cdecl fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		char *p = fgets(buf, 1024, fp);		//��� 1023�� ��һ��\0
		//C ������ ��һ��һ�е�copy���ݵ�buf ָ�� ��ָ���ڴ�ռ��� �����C �����ַ���
		if (p == NULL)
		{
			goto End;
		}
		printf("%s", buf);	//����һ��һ�еĶ�ȡ���� ��\nҲ������������
		/*char tmpc = fgetc(fp);
		printf("%c ", tmpc);*/
	}
End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	//fclose(fp);				//fp���  �ڴ����׵�ַ ����Դ���׵�ַ
}
void main0201()
{
	//main01_fputs();
	main01_fgets();
	
	printf("\nhello...\n");
	system("pause");
}
