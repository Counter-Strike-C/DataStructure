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

#pragma region 队列顺序表示
typedef struct StackNode
{
	QElemType* base;
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
	if ((Q.rear + 1) % MAXSIZE) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
//取队头元素
Status GetHead(SqQueue& Q, QElemType& e)
{
	if (Q.front != Q.rear)
	{

		e = Q.base[Q.front];
		return OK;
	}
	else return ERROR;
}
#pragma endregion

#pragma region 队列链式表示
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode ,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue_L(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));  //头节点
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue& Q) {
	while (Q.front)
	{
		QueuePtr p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return OK;
}

//入列
Status EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

//出列
Status DeQueue(LinkQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear) return ERROR;
	 QueuePtr p = Q.front->next;
	 e = p->data; 
	 Q.front->next = p->next;
	 if (Q.rear == p)Q.rear = Q.front;
	 delete p;
	 return OK;
}

//队头元素
Status GetHead(LinkQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)return ERROR;
	e = Q.front->next->data;
	return OK;
}
#pragma endregion
