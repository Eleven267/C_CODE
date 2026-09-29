#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//初始化
void HPInit(HP* php)
{
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//销毁
void HPDertroy(HP* php)
{
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//打印
void HPPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}



//交换
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


//向上调整
void AdjustUp(HPDataType* arr,int child)
{
	int paraent = (child - 1) / 2;
	while (child>0)
	{
		//大堆>(顶最大)
		//小堆<（顶最小）
		if (arr[child] > arr[paraent])
		{
			Swap(&arr[child], &arr[paraent]);
			child = paraent;
			paraent= (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


//判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//插入数据
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//判断空间是否足够
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newCapacity;
	}
	php->arr[php->size] = x;
	//向上调整
	AdjustUp(php->arr, php->size);
	php->size++;
}



//向下调整
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])//小堆arr[child] > arr[child + 1]
		{
			child++;
		}
		if (arr[child] > arr[parent])//小堆(arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}



//删除数据（堆顶）
void HPPop(HP* php)
{
	assert(!HPEmpty(php));
	//交换堆顶与最后一个数据
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	//向下调整
	AdjustDown(php->arr, 0, php->size);
}



//取堆顶数据
HPDataType HPTop(HP* php)
{
	assert(!HPEmpty(php));
	return php->arr[0];
}


//求size
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}