#ifndef _MYMLINKLIST_H_H_
#define	_MYMLINKLIST_H_H_

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *next;
}LinkListNode;


// typedef void LinkList;
// 
// typedef struct _tag_LinkListNode
// {
// 	struct _tag_LinkListNode *next;
// }LinkListNode;






LinkList *LinkList_Create(); //����һ������

void LinkList_Destroy(LinkList *list);	//��������

void LinkList_Clear(LinkList *list);	//�������

int LinkList_Length(LinkList *list);	//��ȡ������

int LinkList_Insert(LinkList *list,LinkListNode* node,int pos);	//�������ĳһ��λ�ò���ڵ�

LinkListNode *LinkList_Get(LinkList *list, int pos);	//��ȡ�����ĳһ��λ�õĽ���

LinkListNode *LinkList_Delete(LinkList *list, int pos);	//ɾ��ĳһ��λ�õ�������


#endif