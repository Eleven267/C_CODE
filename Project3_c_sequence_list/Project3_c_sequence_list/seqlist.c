#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
//初始化
void SLInit(SL* ps)
{
	ps->arr = (SLDataType*)malloc(4 * sizeof(SLDataType));
	ps->size = 0;
	ps->capacity = 4;
}

//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表打印
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d", s.arr[i]);
	}
	printf("\n");
}


void SLCheckCapacity(SL* ps)
{
	//查看空间够不够
	if (ps->capacity == ps->size)
	{
		//申请空间
		int newcapacity = ps->capacity = 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("reallooc fail!");
			exit(1);//退出
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}


//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//等价于assert(ps=!NULL)
	SLCheckCapacity(ps);
	//插入
	ps->arr[ps->size++] = x;

}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//整体往后移一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	//赋值
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//顺序表不为空
	--ps->size;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);//顺序表不为空
	//整体往前挪动一位
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)//pos是下标位置
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i>pos; i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除指定位置的数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i<ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//顺序表的查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
