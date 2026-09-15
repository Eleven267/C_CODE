#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void Test()
{
	ST st;
	//初始化
	StackInit(&st);
	//插入
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	//删除
	//StackPop(&st);
	//StackPop(&st);
	//取top
	/*while (!StackEmpty(&st))
	{
		int top = StackTop(&st);
		printf("%d", top);
		StackPop(&st);
	}*/
	int size = StackSize(&st);
	printf("%d", size);
	//销毁
	StackDestory(&st);
}

int main()
{
	Test();
	return 0;
}