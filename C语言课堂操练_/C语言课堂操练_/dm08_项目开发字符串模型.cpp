#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//char *p="abcd1122abcd333333abcd3323qqqq"  
//���ַ����� abcd�� ���ֵĴ���
//1	�� �Զ��庯���ӿڣ������������
//2	�Զ����ҵ���� �� main��������ֿ�

void main0801()
{
	int ncount = 0;
	//strstr(str, str2);
	//��ʼ�� ��p ָ��ﵽ ���ҵ�����
	//strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
	//����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
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
		p = p + strlen("abcd");	//��p ָ�� �ﵽ���ҵ�����
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
	//��ʼ��  ��pָ��ﵽҪ���ҵ�ֵ
	char *p = mystr;
	//��Ҫ���׸ı��β� �� ֵ
	if (mystr == NULL || sub == NULL || ncount == NULL)
	{
		ret = -1;
		printf("func getCount() err:%d  (mystr == NULL || sub == NULL || ncount == NULL)\n", ret);
		return -1;
	}
	while (p = strstr(p, sub))
	{
		tempCount++;
		p = p + strlen(sub);	//��p ָ�� �ﵽ���ҵ�����
		if (*p == '\0')
		{
			break;
		}
	}
	*ncount = tempCount;	//��Ӹ��� ��ָ����ڵ��������
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