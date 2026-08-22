#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}
	node->data = x;
	node->next = node;
	node->prev = node;
	return node;
}


//初始化
LTNode* LTInit()
{
	//创建一个哨兵位
	LTNode*phead = LTBuyNode(-1);
	return phead;
}


//销毁
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}


//链表打印
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}


//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTBuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;

	phead->prev->next = newnode;
	phead->prev = newnode;

}


//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTBuyNode(x);
	newnode->prev = phead;
	newnode->next = phead->next;

	phead->next->prev = newnode;
	phead->next = newnode;
}


//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead && phead != phead->next);

	LTNode* del = phead->prev;

	del->prev->next = phead;
	phead->prev = del->prev;

	free(del);
	del = NULL;
}


//头删
void LTPopFront(LTNode* phead)
{
	assert(phead && phead != phead->next);

	LTNode* del = phead->next;
	del->prev = phead;
	phead->next = del->next;

	free(del);
	del = NULL;
}


//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//没找到
	return NULL;
}


//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = LTBuyNode(x);
	newnode->prev = pos;
	newnode->next = pos->next;

	pos->next->prev = newnode;
	pos->next = newnode;
}


//删除pos节点
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
	pos = NULL;
}
