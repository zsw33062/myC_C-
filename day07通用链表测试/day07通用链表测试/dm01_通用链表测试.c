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

	//ҵ������ �� �����㷨����Ч���� 
	LinkList_Insert(list, (LinkListNode *)&t1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t3, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t4, LinkList_Length(list));


	//��������
	for (i = 0; i < LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("%d ", tmp->age);
		}
	}

	//ɾ������
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
LinkList *LinkList_Create(); //����һ������

void LinkList_Destroy(LinkList *list);	//��������

void LinkList_Clear(LinkList *list);	//�������

void LinkList_Length(LinkList *list);	//��ȡ������

void LinkList_Insert(LinkList *list, LinkListNode* node, int pos);	//�������ĳһ��λ�ò���ڵ�

LinkListNode *LinkList_Get(LinkList *list, int pos);	//��ȡ�����ĳһ��λ�õĽ���

LinkListNode *LinkList_Delete(LinkList *list, int pos);	//ɾ��ĳһ��λ�õ�������
*/
