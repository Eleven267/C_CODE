#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"Seqlist.h"

//导入历史数据
void LoadContact(contact* con)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("fopen error!\n");
		return;
	}
	//循环读取⽂件数据

	peoInfo info;
	while (fread(&info, sizeof(peoInfo), 1, pf))
	{
		SeqListPushBack(con, info);
	}
	printf("历史数据导入通讯录成功！\n");
}

//初始化通讯录
void ContactInit(contact* con)
{
	SLInit(con);
	LoadContact(con);
}

//销毁通讯录数据
void ContactDestroy(contact* con)
{
	SaveContact(con);
	SLDestroy(con);
}

//添加通讯录数据
void ContactAdd(contact* con)
{
	//获取用户输入的内容
	peoInfo info;
	printf("请输入姓名：\n");
	scanf("%19s", info.name);

	printf("请输入性别：\n");
	scanf("%9s", info.gender);

	printf("请输入年龄：\n");
	scanf("%d", &info.age);

	printf("请输入联系电话：\n");
	scanf("%19s", info.tel);

	printf("请输入地址：\n");
	scanf("%99s", info.addr);

	//往通讯录里添加联系人数据
	SLPushBack(con, info);
}

int FindByName(contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//删除通讯录数据
void ContactDel(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的用户姓名：\n");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要删除的用户不存在，删除失败！\n");
		return;
	}
	SLErase(&con, find);
	printf("删除成功！\n");

}

//展⽰通讯录数据
void ContactShow(contact* con)
{
	//表头
	printf("%-10s %-4s %-4s %15s %-20s\n", "姓名", "性别", "年龄", "联系电话", "地址");

	for (int i = 0; i < con->size; i++)
	{
		printf("%-10s %-4s %-4d %15s %-20s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
}

//修改通讯录数据
void ContactModify(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的用户名称:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要查找的用户不存在，修改失败！\n");

		return;
	}
	peoInfo info;
	printf("请输入要修改的姓名：\n");
	scanf("%s", con->arr[find].name);
	printf("请输入要修改的性别：\n");
	scanf("%s", con->arr[find].gender);
	printf("请输入要修改的年龄：\n");
	scanf("%d", &con->arr[find].age);
	printf("请输入要修改的联系电话：\n");
	scanf("%s", con->arr[find].tel);
	printf("请输入要修改的地址：\n");
	scanf("%s", con->arr[find].addr);
	printf("修改成功！\n");
}

//查找通讯录数据
void ContactFind(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) {
		printf("要查找的用户不存在，查找失败！\n");
		return;
	}
	printf("查找成功！\n");
	printf("%-10s %-4s %-4s %15s %-20s\n", "姓名", "性别", "年龄", "联系电话", "地址");
	printf("%-10s %-4s %-4d %15s %-20s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);
}

//保存
void SaveContact(contact* con)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}
	//将通讯录数据写⼊⽂件

	for (int i = 0; i < con->size; i++)
	{
		fwrite(con->arr + i, sizeof(peoInfo), 1, pf);
	}
	printf("通讯录数据保存成功！\n");
}
