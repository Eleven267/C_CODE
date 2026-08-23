#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Contact.h"
//定义顺序表结构

//静态顺序表
//#define N 100
//struct seqlist
//{
//	int arr[N];
//	int size;
//};


//动态顺序表
//typedef int  SLDataType;//便于后续整体修改
typedef peoInfo  SLDataType;

typedef struct seqlist
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}SL;//与typedef struct seqlist SL;效果一样（改名）

//顺序表初始化
void SLInit(SL* ps);

//顺序表销毁
void SLDestroy(SL* ps);

//顺序表打印
void SLPrint(SL s);

//头部插⼊删除/尾部插⼊删除
void SLPushBack(SL* ps, SLDataType x);//尾插
void SLPushFront(SL* ps, SLDataType x);//头插
void SLPopBack(SL* ps);//尾删
void SLPopFront(SL* ps);//头删


//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x);

//删除指定位置的数据
void SLErase(SL* ps, int pos);

//顺序表的查找
int SLFind(SL* ps, SLDataType x);


