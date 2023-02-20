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
typedef char ElemType;

typedef struct {
	int a;

}SElemType;

typedef struct {
	SElemType* base;  //栈底指针
	SElemType* top;  //栈顶指针
	int stacksize;  //栈可用最大容量

}SqStack;

typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;

//初始化栈
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE];  

	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack& S)
{
		return S.top == S.base?TRUE:FALSE;
}

//求顺序栈的长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//清空栈
Status ClearStack(SqStack S)
{
	if (S.base)S.top = S.base;
	return OK;
}

//销毁栈
Status DestroyStack(SqStack& S)
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//入栈
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize)  //栈满
		return ERROR;
	*S.top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack& S, SElemType e)
{
	if (S.top == S.base)
		return;
	e = *--S.top;
	return OK;
}

#pragma region 链栈操作

Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}

Status StackEmpty(LinkStack S)
{
	if (S == NULL) return TRUE;
	else return FALSE;
}

//入栈
Status Push(LinkStack & S, SElemType e)
{
	StackNode *p = new StackNode;  //新节点
	p->data = e;
	p->next = S;    //c插入栈顶
	S = p;  //修改栈顶指针
	return OK;
}

//出栈
Status Pop(LinkStack& S, SElemType& e)
{
	if (S == NULL)return ERROR;
	e = S->data;
	StackNode * p = S;
	S = S->next;
	delete p;
	return OK;
}
#pragma endregion
