#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	printf("   1   2   3 \n");
	printf("  ___________\n");
	for (i = 0; i < row; i++)
	{
		printf("%d", i + 1);
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
			printf(" |---|---|---|\n");
	}
	printf(" ~~~~~~~~~~~~~\n");
	printf("\n");
}
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入你下的坐标：");
	while (1)
	{
		scanf("%d%d", &x, &y);
		x = x - 1;
		y = y - 1;
		if (0 <= (x) && (x) < row && 0 <= (y) && (y) < col)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = 'X';
				break;
			}
			else
				printf("输入的坐标被占用\n");
		}
		else
			printf("输入的坐标不存在\n");
	}
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (is_full(board, row, col) == 1)
			break;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
char is_win(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	for (x = 1; x < row - 1; x++)
	{
		for (y = 0; y < col; y++)
		{
			if ((board[x][y] == board[x - 1][y]) && (board[x][y] == board[x + 1][y]) && board[x][y] != ' ')//判断列
			{
				return 'B';
			}
		}
	}
	for (x = 0; x < row; x++)
	{
		for (y = 1; y < col - 1; y++)
		{
			if ((board[x][y] == board[x][y - 1]) && (board[x][y] == board[x][y + 1]) && board[x][y] != ' ')//判断行
			{
				return  'B';
			}
		}
	}

	for (x = 1; x < row - 1; x++)
	{
		for (y = 1; y < col - 1; y++)
		{
			if (((board[x][y] == board[x - 1][y - 1]) && (board[x][y] == board[x + 1][y + 1]) && board[x][y] != ' ')
				|| ((board[x][y] == board[x - 1][y + 1]) && (board[x][y] == board[x + 1][y - 1])) && board[x][y] != ' ')//判断斜边
				return  'B';
		}
	}
	if (is_full(board, ROW, COL) == 1)    //判断棋盘是否满了（平局）  
	{
		return 'P';   //表示棋盘满了  
	}
	return'C';
}
