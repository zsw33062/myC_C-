#define _CRT_SECURE_NO_WARNINGS

#include"socketclientdll.h"
#include "socketclientdll.c"


int main()
{
	int ret = 0, buflen = 5, outbuflen = 0;
	void *handle = NULL;
	unsigned char buf[100] = "124141";
	unsigned char outbuf[100];

	ret = cltSocket_init(&handle);
	if (ret != 0)
	{
		printf("cltSocket_init err: %d", ret);
		goto End;
	}

	ret = cltSocket_senddata(handle, buf, buflen);
	if (ret != 0)
	{
		printf("cltSocket_senddata err: %d", ret);
		goto End;
	}

	cltSocket_resvdata(handle, outbuf, &outbuflen);
	if (ret != 0)
	{
		printf("cltSocket_resvdata err: %d", ret);
		goto End;

	}
	printf("%d", outbuflen);
	printf("%s", outbuf);

End:
	if (handle != NULL)
	{
		cltSocket_destory(handle);
		handle = NULL;

	}
	system("pause");
	return ret;
}

