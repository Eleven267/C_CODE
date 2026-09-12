#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

//函数实现


//设置光标坐标
void SetPos(short x, short y)
{
	//获取标准输出设置的句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定位光标的位置
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}



//1.打印环境界面
//2.功能介绍
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 17);
	system("pause");
	system("cls");
	SetPos(25, 12);
	wprintf(L"用↑.↓.←.→来控制蛇的移动，按F3加速，按F4减速\n");
	SetPos(37, 15);
	wprintf(L"加速能够得到更高的分数\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
}



//3.绘制地图
void CreatMap()
{
	//上
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}



//4.初始化蛇
void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;

	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//头插法插入链表
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//设置贪吃蛇属性
	ps->_dir = RIGHT;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}



//5.创建食物
void CreatFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);
	
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}
	//创建食物节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}



//游戏初始化
void GameStart(pSnake ps)
{
	//0.设置光标大小，光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(houtput, &CursorInfo);//设置控制台光标状态

	//1.打印环境界面
	//2.功能介绍
	WelcomeToGame();
	//3.绘制地图
	CreatMap();
	//4.创建贪吃蛇
	InitSnake(ps);
	//5.创建食物
	CreatFood(ps);
}



//打印帮助信息
PrintHelpInfo() 
{
	SetPos(64, 15);
	wprintf(L"%ls",L"不能穿墙，不能咬到自己");
	SetPos(64, 16);
	wprintf(L"%ls", L"用↑.↓.←.→来控制蛇的移动");
	SetPos(64, 17);
	wprintf(L"%ls", L"按F3加速，按F4减速");
	SetPos(64, 18);
	wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");
	SetPos(64, 20);
	wprintf(L"%ls", L"YRS制作");
}



#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)



 void pause()
{
	 while (1)
	 {
		 Sleep(200);
		 if (KEY_PRESS(VK_SPACE))
		 {
			 break;
		 }
	 }
}



 //判断下一步坐标是否是食物
 int NextIsFood(pSnakeNode pn, pSnake ps)
 {
	 return(ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
 }



 //下一个位置是食物，吃掉食物
 void EatFood(pSnakeNode pn, pSnake ps)
 {
	 //头插，把链表挂上去
	 ps->_pFood->next = ps->_pSnake;
	 ps->_pSnake = ps->_pFood;

	 //释放下一个位置节点
	 free(pn);
	 pn = NULL;
	 pSnakeNode cur = ps->_pSnake;
	 //打印蛇
	 while(cur)
	 {
		 SetPos(cur->x, cur->y);
		 wprintf(L"%lc", BODY);
		 cur = cur->next;
	 }
	 ps->_score += ps->_food_weight;
	 //重新创建食物
	 CreatFood(ps);
 }



 //下一个位置不是食物
 void NoFood(pSnakeNode pn, pSnake ps)
 {
	 pn->next = ps->_pSnake;
	 ps->_pSnake = pn;

	 pSnakeNode cur = ps->_pSnake;
	 while (cur->next->next != NULL)
	 {
		 SetPos(cur->x, cur->y);
		 wprintf(L"%lc", BODY);
		 cur = cur->next;
	 }

	 SetPos(cur->next->x, cur->next->y);
	 printf("  ");

	 free(cur->next);
	 cur->next = NULL;
 }



 //检测蛇是否撞墙
 void KillByWall(pSnake ps)
 {
	 if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 || ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	 {
		 ps->_status = KILL_BY_WALL;
	 }
 }



 //检测蛇是否撞到自己
 void KillBySelf(pSnake ps)
 {
	 pSnakeNode cur = ps->_pSnake->next;
	 while (cur)
	 {
		 if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		 {
			 ps->_status = KILL_BY_SELF;
			 break;
		 }
		 cur = cur->next;
	 }
 }



//蛇的移动
void SnakeMove(pSnake ps)
{
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	switch(ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	//判断下一步坐标是否是食物
	if (NextIsFood(pNextNode,ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}

	//检测蛇是否撞墙
	KillByWall(ps);
	//检测蛇是否撞到自己
	KillBySelf(ps);
}



//游戏运行逻辑
void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印总分与食物分值
		SetPos(64, 9);
		printf("总分数:%d", ps->_score);
		SetPos(64, 11);
		printf("当前食物分数:%2d", ps->_food_weight);
		
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)//上
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)//下
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)//左
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)//右
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))//暂停
		{
			pause();
		}
		else if (KEY_PRESS(VK_SPACE))//退出
		{
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))//加速
		{
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))//减速
		{
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}
		//蛇的移动
		SnakeMove(ps);
		Sleep(ps->_sleep_time);
		
	} while (ps->_status == OK);
}



//结束游戏，善后工作
void GameEnd(pSnake ps)
{
	SetPos(20, 12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("您主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		printf("您撞到了墙上，游戏结束\n");
		break;
	case KILL_BY_SELF:
		printf("您撞到了自己，游戏结束\n");
		break;
	}
	SetPos(0,26);

	//释放蛇身链表
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}