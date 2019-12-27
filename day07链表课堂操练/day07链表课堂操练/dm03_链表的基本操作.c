#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;

typedef struct Node2
{
	struct Node2 *next;
}myNode;
typedef struct Teacher
{
	char name[64];
	char name2[128];
	int data;
	struct Node node;

	struct Teacher *next;
}Teacher;
void main()
{
	//利用 node 的偏移量来求t1 的地址
	//Linux 内核链表    
	Teacher t1, t2, t3;
	t1.node.next = &(t3.node);
	t2.node.next = &(t3.node);
	t2.node.next = NULL;

}

SLIST *SLIST_Create();	//创建链表
int SLIST_Print(SLIST *pHead);	//遍历链表
int SLIST_NodeInsert(SLIST *pHead, int x, int y);	//插入值 在x 之前 删除 y
int SLIST_NodeDel(SLIST *pHead, int y);
int SLIST_Destroy(SLIST *pHead);
SLIST *SLIST_Create()	//创建链表
{
	// 1  不停地malloc 新结点
	// 2  新结点 入链表
	// 3  让新结点变成 当前节点

	//1 不断接受 输入 malloc 新节点
	//2 
	SLIST *pHead, *pM, *pCur;
	int data = 0;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	printf("Plsease enter your data:");
	scanf("%d", &data);
	//pHead->data = tmpdata;
	pCur = pHead;
	while (data != -1)
	{
		//创建业务 结点 并初始化
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			return NULL;
		}
		// 		printf("\nPlsease enter your data:%d");
		// 		scanf("%d", &tmpdata);
		pM->data = data;
		pM->next = NULL;

		//2 新结点 入链表
		pCur->next = pM;
		//3 新结点 变成当前结点
		//pCur = pCur->next;
		pCur = pM;	//链表结点的尾部 追加

		//printf("Plsease enter your data:");
		scanf("%d", &data);
	}
	return pHead;

	//链表操作 和辅助指针的关系
}
//一个 入口 多个出口（多个出口）
//指针 做函数参数
int SLIST_Create2(SLIST **myp)	//创建链表
{
	// 1  不停地malloc 新结点
	// 2  新结点 入链表
	// 3  让新结点变成 当前节点

	//1 不断接受 输入 malloc 新节点
	//2 
	SLIST *pHead, *pM, *pCur;
	int ret = 0;
	int data = 0;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLIST_Create2() err:%d",ret);
		///eturn -1;//一个入口 多个 出口 可进行 优化
		goto END;
	}
	pHead->data = 0;
	pHead->next = NULL;
	printf("Plsease enter your data:");
	scanf("%d", &data);
	//pHead->data = tmpdata;
	pCur = pHead;
	while (data != -1)
	{
		//创建业务 结点 并初始化
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			ret = -2;
			printf("func malloc() err: %d", ret);
			goto END;
		}
		// 		printf("\nPlsease enter your data:%d");
		// 		scanf("%d", &tmpdata);
		pM->data = data;
		pM->next = NULL;

		//2 新结点 入链表
		pCur->next = pM;
		//3 新结点 变成当前结点
		//pCur = pCur->next;
		pCur = pM;	//链表结点的尾部 追加

		//printf("Plsease enter your data:");
		scanf("%d", &data);
	}
END:
	if (ret != 0)
	{
		SLIST_Destroy(pHead);
	}
	else
	{
		*myp = pHead;
	}
	return ret;

	//链表操作 和辅助指针的关系
}
int SLIST_Print(SLIST *pHead)	//遍历链表
{

	SLIST *pCur = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	pCur = pHead->next;

	printf("\nBegin:\t");
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\tEnd\n");
	return 0;
}
int SLIST_NodeInsert(SLIST *pHead, int x, int y)	//插入值 在x 之前 插入 y
{
	//链表是单向的，当前结点 的位置 保存在 前驱结点 的next 域 中

	SLIST *pPre, *pM, *pCur;
	pPre = pHead;
	pCur = pPre->next;
//	int data = 0;
	pM = (SLIST *)malloc(sizeof(SLIST));

	if (pM == NULL)
	{
		return -1;
	}
	pM->next = NULL;
	pM->data = y;

	//遍历链表
	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
		//让新结点 连接 后续链表

	}
	pM->next = pCur;
	pPre->next = pM;
	return 0;
}
int SLIST_NodeDel(SLIST *pHead, int y)
{
	SLIST *pPre,  *pCur;
	//初始化 状态
	pPre = pHead;
	pCur = pPre->next;

	//遍历链表
	while (pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
	}
	//删除操作
	if (pCur==NULL)
	{
		printf("没有找到 结点值为：%的结点\n", y);
	}
	pPre->next = pCur->next;
	if (pCur!=NULL)
	{
		free(pCur);
	}
	return 0;
}
int SLIST_Destroy(SLIST *pHead)
{
	SLIST *ptmp = NULL;
	if (pHead!=NULL)
	{
		return -1;
	}
	ptmp = pHead;
	while (ptmp!=NULL)
	{
		ptmp = pHead->next;
		free(pHead);	//备份
		pHead = ptmp->next;

	}
	return 0;

}
int SLIST_Reverse(SLIST *pHead)
{
	SLIST *p = NULL;	//前驱指针
	SLIST *q = NULL;	//当前指针
	SLIST *t = NULL;	//缓存的一个结点
	//1 链表 逆置  ：一个结点一个结点 的逆置
	//2 逆置的起点 


	//初始化
	//最为合适 寻找 逆置的起点
	p = pHead->next;
	q = pHead->next->next;
	//p = pHead;
	//q = pHead->next;
	if (pHead==NULL||pHead->next==NULL||pHead->next->next==NULL)
	{
		return 0;
	}

	//一个一个结点的逆置
	while (q)
	{
		t = q->next;	//缓存后边的链表
		
		q->next = p;	//逆置
		
		p = q;			//让p下移一个结点

		q = t;
	}
	//头结点 变成尾部结点 后 置 NULL
	pHead->next->next = NULL;
	pHead->next = p;

	return 0;
}
void main0101()
{
	int ret = 0;
	SLIST *pHead = NULL;
	pHead = SLIST_Create();
	ret = SLIST_Print(pHead);
	ret = SLIST_NodeInsert(pHead, 20, 19);
	printf("After insert:\t");
	ret = SLIST_Print(pHead);
	ret = SLIST_NodeDel(pHead, 19);
	printf("After delete:\t");
	ret = SLIST_Print(pHead);
	ret = SLIST_Reverse(pHead);
	printf("After reverse:");
	ret = SLIST_Print(pHead);

	printf("hello...\n");
	system("pause");
}
