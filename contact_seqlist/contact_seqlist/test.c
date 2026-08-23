#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
#include"Contact.h"

////通讯录测试方法
//void ContactTest01()
//{
//	contact con;
//	//初始化
//	ContactInit(&con);
//
//	//添加数据
//	ContactAdd(&con);
//	ContactAdd(&con);
//
//	//展⽰通讯录数据
//	ContactShow(&con);
//
//	//删除通讯录数据
//	//ContactDel(&con);
//
//	//修改通讯录数据
//	ContactModify(&con);
//	ContactShow(&con);
//
//	//查找通讯录数据
//	ContactFind(&con);
//
//	//销毁
//	ContactDestroy(&con);
//
//}

void menu()
{
	printf("**************通讯录************\n");
	printf("*****1、添加用户2、删除用户*****\n");
	printf("*****3、查找用户4、修改用户*****\n");
	printf("*****5、展示用户0、退出*********\n");
	printf("********************************\n");
}



int main()
{
	int op = -1;
	contact con;
	ContactInit(&con);
	do
	{
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactFind(&con);
			break;
		case 4:
			ContactModify(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出操作")
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
			return 0;
		}
	} while (op != 0);

	ContactDestroy(&con);
}