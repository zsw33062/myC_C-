#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct Teacher
{
	int data;
	struct Teacher *next;
}Teacher;

//静态链表
//有局限性  固定个数 节点的内存的生命周期
//有 静态的 就有动态的 

Teacher *Creat1IST()
{
	Teacher t1, t2, t3;
	Teacher *phead = NULL;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;

	t1.next = &t2;
	t2.next = &t3;
	t3.next = NULL;
	phead = &t1;
	while (phead)
	{
		printf("data: %d\n", phead->data);
		phead = phead->next;
	}
	return 0;
}


void main0201()
{
	Teacher *head = Creat1IST();

	
	printf("hello...\n");
	system("pause");
}
