#pragma once
#include <stdlib.h>
#include<iostream>
#define MAXSIZE 100
const int MAXLEN=255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	char ch[MAXLEN +1];
	int length;
}SString;