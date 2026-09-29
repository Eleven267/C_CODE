#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//堆的结构
typedef int HPDataType;
typedef struct Heap
{
	int* arr;
	int size;
	int capacity;
}HP;

//堆方法的实现

//交换
void Swap(int* x, int* y);

//向上调整
void AdjustUp(HPDataType* arr, int child);

//向下调整
void AdjustDown(HPDataType* arr, int parent, int n);

//初始化
void HPInit(HP* php);

//销毁
void HPDertroy(HP* php);

//打印
void HPPrint(HP* php);

//判空
bool HPEmpty(HP* php);

//插入数据
void HPPush(HP* php, HPDataType x);

//删除数据（堆顶）
void HPPop(HP* php);

//取堆顶数据
HPDataType HPTop(HP* php);

//求size
int HPSize(HP* php);
