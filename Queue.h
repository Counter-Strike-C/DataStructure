#pragma once
#include <stdlib.h>
#include<iostream>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char QElemType;

typedef struct {
	int a;

}QElemType;

typedef struct StackNode
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;


Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXSIZE];  //分配数组空间
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear) return ERROR;  //队空
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType& e)
{
	if ((Q.rear+1)%MAXSIZE) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//取队头元素
Status GetHead(SqQueue &Q,QElemType &e)
{
	if (Q.front != Q.rear)
	{

		e = Q.base[Q.front];
		return OK;
	}
	else return ERROR;
}