#pragma once
#include<Windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define POS_X 24
#define POS_Y 5

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'


//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//游戏的状态
//正常，撞墙，撞到自己，正常退出
enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};

//蛇身节点类型
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//下一个指针节点
	struct SnakeNode* next;
}SnakeNode,*pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood;//指向食物节点的指针
	enum DIRECTION _dir;//蛇的方向
	enum GAME_STATUS _status;//游戏的状态
	int _food_weight;//一个食物分数
	int _score;//总成绩
	int _sleep_time;//休息时间（时间越短，速度越快）
}Snake,*pSnake;

//函数声明

//设置光标坐标
void SetPos(short x, short y);

//游戏初始化
void GameStart(pSnake ps);

//欢迎界面打印
void WelcomeToGame();

//绘制地图
void CreatMap();

//初始化蛇
void InitSnake(pSnake ps);

//创建食物
void CreatFood(pSnake ps);

//游戏运行逻辑
void GameRun(pSnake ps);

//蛇的移动
void SnakeMove(pSnake ps);

//判断下一步坐标是否是食物
int NextIsFood(pSnakeNode pn,pSnake ps);

//下一个位置是食物，吃掉食物
void EatFood(pSnakeNode pn, pSnake ps);

//下一个位置不是食物
void NoFood(pSnakeNode pn, pSnake ps);

//检测蛇是否撞墙
void KillByWall(pSnake ps);

//检测蛇是否撞到自己
void KillBySelf(pSnake ps);

//结束游戏，善后工作
void GameEnd(pSnake ps);

