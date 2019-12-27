#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int getStr1Str2(char *source, char *buf1,char *buf2)
{
	if (source==NULL||buf1==NULL||buf2==NULL)
	{
		printf("func err:source==NULL||buf1==NULL||buf2==NULL\n");
	}
	//int ret = 0;
	char *tmpsource = source;
	char *tmpbuf1 = buf1;
	char *tmpbuf2 = buf2;
	while (*tmpsource!='\0')
	{
		*tmpbuf1 = *tmpsource;
		tmpsource++;
		tmpbuf1++;
		*tmpbuf2 = *tmpsource;
		tmpsource++;
		tmpbuf2++;
	}
	*tmpbuf1 = '\0';
	*tmpbuf2 = '\0';
	return 0;
}
void main0201()
{	
	int ret = 0;
	char *source = "1a2b3c4d5e";
	char *buf1 = malloc(10);
	char *buf2 = malloc(10);
	ret = getStr1Str2(source, buf1, buf2);
	if (ret!=0)
	{
		printf("func getStr1Str2 err: %d",ret);
	}
	printf("source:%s\n",source);
	printf("buf1:%s\n", buf1);
	printf("buf2:%s\n", buf2);
	printf("hello...\n");
	system("pause");
	return;
}