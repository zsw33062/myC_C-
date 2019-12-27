#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>



void trimSpace(char *inbuf, char **outbuf)
{
	*outbuf = malloc(20);   //不能重新分配内存  啊 大哥...
	//分配了内存 是临时的 函数结束后 会释放 内存
	if (inbuf==NULL)
	{
		printf("the input is NULL\n");
	}
	char *new_buf =malloc(20);
	char *tmpinbuf = inbuf;
	while (isspace(*tmpinbuf))
	{
		tmpinbuf++;
	}
	char *tmp = malloc(20);
	tmp = new_buf;
	while (!isspace(*tmpinbuf))
	{
		*new_buf = *tmpinbuf;
		new_buf++;
		tmpinbuf++;
	}

	*new_buf = '\0';
	//strcpy(new_buf,tmp);
	char *tmptmp = tmp;
	char *tmpout_buf = outbuf;
	printf("tmptmp:%s\n", tmptmp);
	while (*tmptmp!='\0')
	{
		*tmpout_buf = *tmptmp;
		tmptmp++;
		tmpout_buf++;
	}
	*tmpout_buf = '\0';
	*outbuf = tmp;
	//return 0;
}
void main()
{	
	char *new_str = NULL;// = malloc(20);
	char *str = "    abcdefgddddd    ";
	trimSpace(str, &new_str);
	printf("new string is \n%s\n",new_str);
	//puts(new_str);
	printf("\nhello...\n");
	system("pause");
	return;
}
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

//void copy(char *p, char *q)
//{
//	char *tmpp = p;
//	char *tmpq = q;
//	while (*tmpp!='\0')
//	{
//		*tmpq = *tmpp;
//		*tmpq++;
//		*tmpp++;
//	}
//	*tmpq = '\0';
//}
//void main()
//{	
//	char *p = "asdfsdf";
//	char *q=malloc(100);
//	copy(p, q);
//	printf("q:%s\n", q);
//	printf("hello...\n");
//	system("pause");
//	return;
//}