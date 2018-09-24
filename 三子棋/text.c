#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//创建棋盘
	init_board(board, ROW, COL);//初始化棋盘
	print_board(board, ROW, COL);//打印棋盘
	do
	{
		player_move(board, ROW, COL);//玩家走
		print_board(board, ROW, COL);//打印出玩家走后的棋盘
		ret = (is_win(board, ROW, COL));//判断玩家是否赢（玩家能走的前提是玩家还没输，所以游戏结果只有玩家赢或平局）
		if ('B'==ret)//Beat
		{
			printf("恭喜你，你赢了电脑!+_+\n");
			break;
		}
		if ('P' == ret)//Dogfall
		{
			printf("平局。-_-\n");
			break;
		}
		computer_move(board, ROW, COL);//电脑走
		print_board(board, ROW, COL);//打印出电脑走后的棋盘
		ret = (is_win(board, ROW, COL));//判断电脑是否赢（电脑能走的前提是玩家还没输，所以游戏结果只有电脑赢即你输了或平局）
		if ('B' == ret)//Beat
		{
			printf("很遗憾，你被电脑打败了@_@ \n");
			break;
		}
		if ('P' == ret)//Dogfall
		{
			printf("平局。-_-\n");
			break;
		}

	} while ('C' == ret);//Continue


}
void menu()
{
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------三子棋小游戏----------------------------------------------------------------\n");
	printf("--------------------------------------------1.play---------------------------------------------------------------------\n");
	printf("--------------------------------------------0.exit----------------------------------------------------------------------\n");

}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));//随机数生成起点
	do
	{
		menu();//菜单
		printf("请选择\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();//游戏具体内容1.初始化棋盘2.打印棋盘3.玩家移动4.判断胜负5.电脑移动6.判断胜负
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入");
		}
	} while (input);
	system("pause");
	return 0;
}


