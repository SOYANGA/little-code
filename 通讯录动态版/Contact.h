#define _CRT_SECURE_NO_WARNINGS 1
#ifndef   _CNTACT_H_
#define   _CNTACT_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#define MAX 1000
#define MAX_NAME  20
#define MAX_SEX 5
#define MAX_ADDR  20
#define MAX_TEL  20

typedef struct  PERSON
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tell[MAX_TEL];
	char address[MAX_ADDR];
}person;
typedef struct  DATE
{
	int count;
	int max;
	person * my_people;
}date;

void Add(date*people);
void Del(date*people);
void Find(date*people);
void change(date*people);
void show(date*people);
void sort(date*people);
void initdate(date*people);
void Desdate(date* people);
void Req_mem(date *people);
void Dec_mem(date *people);
#endif //  _CNTACT_H_