#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Mylinklist.h"

typedef struct Teacher
{
	LinkListNode node;
	char name[32];
	int age;
}Teacher;

int main()
{
	int			i = 0;

	Teacher		t1, t2, t3, t4;

	LinkList	*list = NULL;


	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	list = LinkList_Create();
	if (list == NULL)
	{
		printf("func LinkList_Create() err\n");
		return;
	}

	//业务数据 和 链表算法的有效分离 
	LinkList_Insert(list, (LinkListNode *)&t1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t3, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t4, LinkList_Length(list));


	//遍历链表
	for (i = 0; i < LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("%d ", tmp->age);
		}
	}

	//删除链表
	printf("\n");
	while (LinkList_Length(list) > 0)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("%d ", tmp->age);
		}
	}

	LinkList_Destroy(list);
	printf("hello...\n");
	system("pause");
}

/*
LinkList *LinkList_Create(); //创建一个链表

void LinkList_Destroy(LinkList *list);	//销毁链表

void LinkList_Clear(LinkList *list);	//清空链表

void LinkList_Length(LinkList *list);	//获取链表长度

void LinkList_Insert(LinkList *list, LinkListNode* node, int pos);	//在链表的某一个位置插入节点

LinkListNode *LinkList_Get(LinkList *list, int pos);	//获取链表的某一个位置的结点点

LinkListNode *LinkList_Delete(LinkList *list, int pos);	//删除某一个位置的链表结点
*/
