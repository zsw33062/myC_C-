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






LinkList *LinkList_Create(); //创建一个链表

void LinkList_Destroy(LinkList *list);	//销毁链表

void LinkList_Clear(LinkList *list);	//清空链表

int LinkList_Length(LinkList *list);	//获取链表长度

int LinkList_Insert(LinkList *list,LinkListNode* node,int pos);	//在链表的某一个位置插入节点

LinkListNode *LinkList_Get(LinkList *list, int pos);	//获取链表的某一个位置的结点点

LinkListNode *LinkList_Delete(LinkList *list, int pos);	//删除某一个位置的链表结点


#endif