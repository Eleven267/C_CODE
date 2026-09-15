#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义栈的结构
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//指向栈顶位置
	int capacity;//栈的容量
}ST;

//初始化
void StackInit(ST* ps);

//插入数据（入栈）
void StackPush(ST* ps,STDataType x);
//删除数据（出栈）
void StackPop(ST* ps);

//取栈顶元素
STDataType StackTop(ST* ps);

//获取栈中有效数据个数
int StackSize(ST* ps);

//栈是否为空
bool StackEmpty(ST* ps);

//销毁
void StackDestory(ST* ps);


