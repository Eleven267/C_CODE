#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test01()
{
	HP hp;
	HPInit(&hp);

	HPPush(&hp, 70);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 25);
	HPPush(&hp, 56);
	HPPush(&hp, 30);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	HPDertroy(&hp);
}


//堆排序1(要借助堆的结构，不好)
void HeapSort01(int* arr, int n)
{
	HP hp;
	HPInit(&hp);
	for (int i = 0;i< n; i++)
	{
		HPPush(&hp, arr[i]);
	}
	int i = 0;
	while (!HPEmpty(&hp))
	{
		int top = HPTop(&hp);
		arr[i++] = top;
		HPPop(&hp);
	}//打印出来的数据递减（大堆）
	HPDertroy(&hp);
}

//堆排序（借助堆的思想，好）时间复杂度 n*logn
void HPSort(int* arr, int n)
{
	//1.根据数组建堆(向下调整算法）时间复杂度n
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}

	//2.向上调整建堆 时间复杂度n*logn
	/*for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}*/

	//堆顶和最后一个数据换位置，size--，在进行向下调整（循环） n*logn
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

void test02()
{
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 70);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 25);
	HPPush(&hp, 56);
	HPPush(&hp, 30);
	HPPrint(&hp);

	while (!HPEmpty(&hp))
	{
		int top = HPTop(&hp);
		printf("%d ", top);
		HPPop(&hp);
	}//打印出来的数据递减（大堆）

	HPDertroy(&hp);
}

int main()
{
	//test02();
	int arr[6] = { 9,2,4,8,14,3 };
	HPSort(arr, 6);
	for (int i= 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}