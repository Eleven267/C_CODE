#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100
//定义联系人数据结构
//姓名 性别 年龄 电话 地址
typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;


//通讯录相关方法
typedef struct seqlist contact;//顺序表改名为通讯录 struct seqlist//前置声明

//初始化通讯录
void ContactInit(contact* con);

//销毁通讯录数据
void ContactDestroy(contact* con);

//添加通讯录数据
void ContactAdd(contact* con);

//删除通讯录数据
void ContactDel(contact* con);

//展⽰通讯录数据
void ContactShow(contact* con);

//查找通讯录数据
void ContactFind(contact* con);

//修改通讯录数据
void ContactModify(contact* con);


