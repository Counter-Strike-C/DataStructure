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
	SElemType* base;  //ջ��ָ��
	SElemType* top;  //ջ��ָ��
	int stacksize;  //ջ�����������

}SqStack;

typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;

//��ʼ��ջ
Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE];  

	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack& S)
{
		return S.top == S.base?TRUE:FALSE;
}

//��˳��ջ�ĳ���
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//���ջ
Status ClearStack(SqStack S)
{
	if (S.base)S.top = S.base;
	return OK;
}

//����ջ
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

//��ջ
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize)  //ջ��
		return ERROR;
	*S.top++ = e;
	return OK;
}

//��ջ
Status Pop(SqStack& S, SElemType e)
{
	if (S.top == S.base)
		return;
	e = *--S.top;
	return OK;
}

#pragma region ��ջ����

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

//��ջ
Status Push(LinkStack & S, SElemType e)
{
	StackNode *p = new StackNode;  //�½ڵ�
	p->data = e;
	p->next = S;    //c����ջ��
	S = p;  //�޸�ջ��ָ��
	return OK;
}

//��ջ
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
