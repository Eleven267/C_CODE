#define _CRT_SECURE_NO_WARNINGS 1
#include<locale.h>
#include"snake.h"

//游戏测试逻辑
void test()
{
	int ch = 0;
	do
	{
		//创建贪吃蛇
		Snake snake = { 0 };
		//游戏初始化
		GameStart(&snake);
		//运行
		GameRun(&snake);
		//结束游戏，善后工作
		GameEnd(&snake);
		SetPos(22, 15);
		printf("再来一局吗？（Y/N）");
		ch = getchar();
		getchar();//清理\n
	} while (ch == 'Y' || ch == 'y');
}
  
int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	test();
	return 0;
}