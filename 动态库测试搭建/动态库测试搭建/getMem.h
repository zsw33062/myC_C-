#include <string.h>
char *getMem(char **myp)
{
	char *p = NULL;

	p = (char *)malloc(100);

	strcpy(p, "aaaaaabbbbb");
	*myp = p;
	return 0;

}