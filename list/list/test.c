#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

void ListTest01()
{
	LTNode* plist = LTInit();

	//尾插
	/*LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPrint(plist);*/

	//头插
	LTPushFront(plist, 3);
	LTPushFront(plist, 2);
	LTPushFront(plist, 1);
	LTPrint(plist);


	////尾删
	//LTPopBack(plist);
	//LTPrint(plist);

	////头删
	//LTPopFront(plist);
	//LTPrint(plist);

	//查找
	LTNode* find = LTFind(plist, 3);
	LTInsert(find, 4);
	LTPrint(plist);

	//删除pos节点
	LTErase(find);
	LTPrint(plist);

	//销毁
	LTDestroy(plist);
	plist = NULL;
}
	

int main()
{
	ListTest01();
	return 0;
}