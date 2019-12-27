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
	//���� node ��ƫ��������t1 �ĵ�ַ
	//Linux �ں�����    
	Teacher t1, t2, t3;
	t1.node.next = &(t3.node);
	t2.node.next = &(t3.node);
	t2.node.next = NULL;

}

SLIST *SLIST_Create();	//��������
int SLIST_Print(SLIST *pHead);	//��������
int SLIST_NodeInsert(SLIST *pHead, int x, int y);	//����ֵ ��x ֮ǰ ɾ�� y
int SLIST_NodeDel(SLIST *pHead, int y);
int SLIST_Destroy(SLIST *pHead);
SLIST *SLIST_Create()	//��������
{
	// 1  ��ͣ��malloc �½��
	// 2  �½�� ������
	// 3  ���½���� ��ǰ�ڵ�

	//1 ���Ͻ��� ���� malloc �½ڵ�
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
		//����ҵ�� ��� ����ʼ��
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			return NULL;
		}
		// 		printf("\nPlsease enter your data:%d");
		// 		scanf("%d", &tmpdata);
		pM->data = data;
		pM->next = NULL;

		//2 �½�� ������
		pCur->next = pM;
		//3 �½�� ��ɵ�ǰ���
		//pCur = pCur->next;
		pCur = pM;	//�������β�� ׷��

		//printf("Plsease enter your data:");
		scanf("%d", &data);
	}
	return pHead;

	//������� �͸���ָ��Ĺ�ϵ
}
//һ�� ��� ������ڣ�������ڣ�
//ָ�� ����������
int SLIST_Create2(SLIST **myp)	//��������
{
	// 1  ��ͣ��malloc �½��
	// 2  �½�� ������
	// 3  ���½���� ��ǰ�ڵ�

	//1 ���Ͻ��� ���� malloc �½ڵ�
	//2 
	SLIST *pHead, *pM, *pCur;
	int ret = 0;
	int data = 0;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func SLIST_Create2() err:%d",ret);
		///eturn -1;//һ����� ��� ���� �ɽ��� �Ż�
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
		//����ҵ�� ��� ����ʼ��
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

		//2 �½�� ������
		pCur->next = pM;
		//3 �½�� ��ɵ�ǰ���
		//pCur = pCur->next;
		pCur = pM;	//�������β�� ׷��

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

	//������� �͸���ָ��Ĺ�ϵ
}
int SLIST_Print(SLIST *pHead)	//��������
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
int SLIST_NodeInsert(SLIST *pHead, int x, int y)	//����ֵ ��x ֮ǰ ���� y
{
	//�����ǵ���ģ���ǰ��� ��λ�� ������ ǰ����� ��next �� ��

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

	//��������
	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
		//���½�� ���� ��������

	}
	pM->next = pCur;
	pPre->next = pM;
	return 0;
}
int SLIST_NodeDel(SLIST *pHead, int y)
{
	SLIST *pPre,  *pCur;
	//��ʼ�� ״̬
	pPre = pHead;
	pCur = pPre->next;

	//��������
	while (pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
	}
	//ɾ������
	if (pCur==NULL)
	{
		printf("û���ҵ� ���ֵΪ��%�Ľ��\n", y);
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
		free(pHead);	//����
		pHead = ptmp->next;

	}
	return 0;

}
int SLIST_Reverse(SLIST *pHead)
{
	SLIST *p = NULL;	//ǰ��ָ��
	SLIST *q = NULL;	//��ǰָ��
	SLIST *t = NULL;	//�����һ�����
	//1 ���� ����  ��һ�����һ����� ������
	//2 ���õ���� 


	//��ʼ��
	//��Ϊ���� Ѱ�� ���õ����
	p = pHead->next;
	q = pHead->next->next;
	//p = pHead;
	//q = pHead->next;
	if (pHead==NULL||pHead->next==NULL||pHead->next->next==NULL)
	{
		return 0;
	}

	//һ��һ����������
	while (q)
	{
		t = q->next;	//�����ߵ�����
		
		q->next = p;	//����
		
		p = q;			//��p����һ�����

		q = t;
	}
	//ͷ��� ���β����� �� �� NULL
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
