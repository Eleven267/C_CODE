#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}


//销毁
void StackDestory(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}


//插入数据（入栈）
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//增容
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	ps->arr[ps->top++] = x;
}


//栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}


//删除数据（出栈）
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	--ps->top;
}

//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

//获取栈中有效数据个数
int StackSize(ST* ps)
{
	return ps->top;
}