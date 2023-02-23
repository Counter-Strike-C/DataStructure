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

typedef struct {
	int a;


}ElemType;

//线性表表示1
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//线性表表示2
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

//双向链表
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

static class SQList
{
public:

	//线性表的初始化
	Status InitList_Sq(SqList& L)
	{
		L.elem = new ElemType[MAXSIZE];
		if (!L.elem)exit(OVERFLOW);
		L.length = 0;
		return OK;
	}

	//销毁线性表
	void DestroyList(SqList& L)
	{
		if (L.elem)delete L.elem;
	}

	//清空线性表
	void ClearList(SqList& L) {
		L.length = 0;   //将线性表长度置为0
	}

	//求线性表的长度
	int GetLength(SqList L)
	{
		return L.length;
	}

	//判断线性表是否为空
	int IsEmpty(SqList L)
	{
		return L.length == 0 ? 1 : 0;
	}

	int GetElem(SqList L, int i, ElemType& e) {
		if (i<1 || i>L.length)return ERROR;
		e = L.elem[i - 1];
		return OK;
	}

	//找到元素位置
	static int LocateElem(SqList L, ElemType e)
	{
		for (int i = 0; i < L.length; i++)
		{
			if (L.elem[i].a==e.a)return i + 1;
		}
	}

	//删除指定元素
	Status ListDelete_Sq(SqList& L, int i) {
		if (i<1 || i>L.length)return ERROR;
		for (int j =  i; j < L.length; j++)
		{
			L.elem[j - 1] = L.elem[j];
		}

		L.length--;
		return OK;
	}

	//插入元素
	static Status ListInsert_Sq(SqList& L, int i, ElemType e) {
		if (i<1 || i>L.length)return ERROR;
		for (int j = i; j < L.length; j ++)
		{
			L.elem[j ] = L.elem[j-1];
		}
		L.elem[i - 1] = e;
		L.length++;
		return OK;
	}



};

