#include "SQList.h"
using namespace std;
//初始化链表
Status InitList_L(LinkList  &L)
{
	//1、头指针指向头节点L
	L = new Lnode;

	//2、将头节点的指针域置空
	L->next = NULL;
	return OK;
}

//判断链表是否为空
int ListEmpty(LinkList& L)
{
	if (L->next)
		return 0;
	else
		return 1;

}

//销毁链表
Status DestroyList_L(LinkList& L)
{
	Lnode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

//清空链表
Status ClearList(LinkList& L)
{
	Lnode * p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;    
	return OK;
}

//求单链表的长度
int ListLength_L(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;

	}
	return i;
}

//获取第i个节点
Status GetElem_L(LinkList L, int i, ElemType& e)
{
	LinkList p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}

//按值查找
int LocateElem_L(LinkList L, ElemType e)
{
	LinkList p;
	p = L->next;
	int j = 0;
	while (p&&p->data.a!=e.a)
	{
		p = p->next;
		j++;
	}
	if (p)return j;
	else
	return 0;
}

//在第i个元素之前插入新节点
Status ListInsert_L(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)return ERROR;
	Lnode *s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//将线性表中第i个元素删除
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p->next && j<i-1)  //找到第i个节点p
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j > i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}//ListDelete_L

//头插法建立链表
void CreateList_H(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	LinkList p;
	for (int i = n; i > 0; --i)
	{
		p = new Lnode;
		cin >> p->data.a;
		p->next = L->next;
		L->next = p;
	}
}//CreateList_H

//尾插法建立链表
void CreateList_R(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	LinkList r = L;  //尾指针指向头节点
	LinkList p;
	for (int i = 0; i < n; i++)
	{
		p = new Lnode;
		cin >> p->data.a;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}//CreateList_R