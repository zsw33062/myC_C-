#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int trim_str(char *in, char *out)
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
void main0102()
{
	char *str="     asdfkljdsafj;lkfdsa;kj       ";
	char *buf = malloc(100);
	int ret = 0;
	printf("str:%s\n", str);
	ret = trim_str(str, buf);
	if (ret != 0)
	{
		printf("func trimSpace() err: %d\n",ret);
		return;
	}
	printf("str:%s\n", str);
	printf("buf:%s\n", buf);
	printf("hello...\n");
	system("pause");
	return;
}