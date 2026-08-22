#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListTest1()
{
	//创建节点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//将四个节点链接起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//链表打印
	SLTNode* plist = node1;
	SLTPrint(plist);
}


void SListTest2()
{
	//尾插
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPrint(plist);
	SListDesTroy(&plist);
	SLTPrint(plist);

	//尾删
	/*SLTPopBack(&plist);
	SLTPrint(plist);*/

	////头删
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//查找
	//SLTNode* find = SLTFind(plist, 1);

	////在指定位置之前插⼊数据
	//SLTInsert(&plist, find, 8);
	//SLTPrint(plist);


	////在指定位置之后插⼊数据
	//SLTInsertAfter(find, 8);
	//SLTPrint(plist);

	////删除pos节点
	//SLTErase(&plist, find);
	//SLTPrint(plist);

	//删除pos之后的节点
	//SLTEraseAfter(find);
	//SLTPrint(plist);

}


int main()
{
	SListTest2();
	return 0;
}