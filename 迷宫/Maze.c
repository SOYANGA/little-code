#define _CRT_SECURE_NO_WARNINGS 1
#include "Maze.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	if (ps->_a == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ps->_top = 0;
	ps->_capcity = 3;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_top = ps->_capcity = 0;
	free(ps->_a);
	ps->_a = NULL;
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->_capcity == ps->_top)
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType)*(ps->_capcity) * 2);
		if (ps->_a == NULL)
		{
			exit(EXIT_FAILURE);
		}
		ps->_capcity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);
	ps->_top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps->_a);
	assert((ps->_top) > 0);
	return ps->_a[ps->_top - 1];
}
//为空为0
//非空为1
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//////////////////////////////////////////////////////
////////////////////////////////////////////////////
//不带环单通路，与多通路（不带环）

//多通路与单通路的区别就是：
//1.单通路的迷宫的出口是一个点
//2.多通路的出口是迷宫的一条边
//3.多通路的前提是已经确定有通路，然后只需要把判断是否有出那段函数屏蔽掉，让他以为没有通路然后将所有可能都走完就可以了。
//int CheckAccess(Pos next)
//{
//	if (maze[next._row][next._col] == 1
//		&&next._col<N
//		&&next._row<N
//		&&next._col>=0
//		&&next._row>=0)
//		return 1;
//	else
//		return 0;
//}
//int GetMazePath(Pos entry, Pos exit)
//{
//	Stack path;
//	StackInit(&path);
//	StackPush(&path, entry);
//	while (StackEmpty(&path))
//	{
//		Pos next;
//		Pos cur = StackTop(&path);
//		maze[cur._row][cur._col] = 2;
//		//判断是否是出口
//		//if (cur._col == exit._col
//		//	&&cur._row == exit._row)
//		//{
//		//	StackDestory(&path);
//		//	return 1;
//		//}
//
//		///////////////////////////////////////////////
//		//判断上能不能走
//		next = cur;
//		next._row -= 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//判断下能不能走
//		next._row = cur._row + 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//判断左能不能走
//		next._col = cur._col - 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//判断上能不能走
//		next._col = cur._col + 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//回溯
//		StackPop(&path);
//	}
//	return 0;
//}
//void PrintMazePath(int Maze[N][N])
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d ", Maze[i][j]);
//		}
//		printf("\n");
//	}
//}
//void Test()
//{
//	PrintMazePath(maze);
//	Pos entry, exit;
//	entry._row = 5;
//	entry._col = 2;
//	exit._row = 4;
//	exit._col = 5;
//	if (GetMazePath(entry, exit) == 1)
//	{
//		printf("可以找到迷宫通路，如下：\n");
//		PrintMazePath(maze);
//		//printf("迷宫最短路径是 %d \n",);
//	}
//	else
//	{
//		printf("找不到通路\n");
//		PrintMazePath(maze);
//	}
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//通路间带环
int CheckAccess(Pos cur,Pos next)
{
	if ((maze[next._row][next._col] == 1 || maze[next._row][next._col] > maze[cur._row][cur._col] + 1)
		&& next._col < N 
		&&next._row < N 
		&&next._col >= 0 
		&& next._row >= 0)
		return 1;
	else
		return 0;
}
Stack path;
int pathSizeMin = 0;//只有有通路的时候才打印
int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&path))
	{
		Pos next;
		Pos cur = StackTop(&path);
		//判断是否是出口,且求路径出长度
		if (cur._col == exit._col
			&&cur._row == exit._row)
		{
			if (pathSizeMin == 0 || pathSizeMin > StackSize(&path))
			{
				pathSizeMin = StackSize(&path);
			}
		}
		///////////////////////////////////////////////
		//判断上能不能走
		next = cur;
		next._row -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//判断下能不能走
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;

			StackPush(&path, next);
			continue;
		}
		//判断左能不能走
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;

			StackPush(&path, next);
			continue;
		}
		//判断右能不能走
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;

			StackPush(&path, next);
			continue;
		}
		//回溯
		StackPop(&path);

	}
	if (pathSizeMin == 0)
		return 0;
	else
		return 1;
}
void PrintMazePath(int Maze[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", Maze[i][j]);
		}
		printf("\n");
	}
}


void Test()
{
	PrintMazePath(maze);
	Pos entry, exit;
	entry._row = 5;
	entry._col = 1;
	exit._row = 4;
	exit._col = 5;
	printf("\n");
	printf("迷宫是否有出口?:%d \n",GetMazePath(entry, exit));
	PrintMazePath(maze);
	printf("迷宫最短路径是 %d \n", pathSizeMin);
	StackDestory(&path);
}