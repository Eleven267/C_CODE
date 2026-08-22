#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义双向链表节点的结构
typedef int LTDataType;
typedef struct listNode
{
	LTDataType data;
	struct listNode* next;
	struct listNode* prev;
}LTNode;


//双向链表方法:

// 双向链表初始化
LTNode* LTInit();

//销毁
void LTDestroy(LTNode* phead);


//链表打印
void LTPrint(LTNode* phead);


//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);
//头删
void LTPopFront(LTNode* phead);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);

//删除pos节点
void LTErase(LTNode* pos);