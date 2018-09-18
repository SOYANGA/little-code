#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define N 6
static  int maze[N][N] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1 },
	{ 0, 1, 0, 0, 0, 0 },
};

typedef struct Pos
{
	int _row;
	int _col;
}Pos;

int GetMazePath(Pos entry, Pos exit);
int CheckAccess(Pos cur,Pos next);
void PrintMazePath(int Maze[N][N]);
void Test();
////////////////

typedef Pos DataType;
typedef struct Stack
{
	DataType* _a;
	int _top;
	int _capcity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);