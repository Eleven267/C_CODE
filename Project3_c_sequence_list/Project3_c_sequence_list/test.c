#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SLTest1()
{
	SL sl;
	//初始化
	SLInit(&sl);

	//尾插
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPrint(sl);

	//头插
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(sl);

	//尾删
	SLPopBack(&sl);
	SLPrint(sl);


	//头删
	SLPopFront(&sl);
    SLPrint(sl);
	
	//销毁
	SLDestroy(&sl);
}

void SLTest2()
{
	SL sl;
	//初始化
	SLInit(&sl);

	//尾插
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);

	//在指定位置之前插入数据
	SLInsert(&sl,2,9);
	SLPrint(sl);


	//删除指定位置的数据
	SLErase(&sl, 2);
	SLPrint(sl);

	//顺序表的查找
	int m=SLFind(&sl, 3);
	if (m < 0)
	{
		printf("没有找到\n");
	}
	else
	{
		printf("找到了，下标为%d\n", m);
	}


	//销毁
	SLDestroy(&sl);
}

int main()
{
	//SLTest1();
	SLTest2();
	return 0;
}