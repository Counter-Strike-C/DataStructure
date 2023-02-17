#include "SQList.h"
using namespace std;
//��ʼ������
Status InitList_L(LinkList  &L)
{
	//1��ͷָ��ָ��ͷ�ڵ�L
	L = new Lnode;

	//2����ͷ�ڵ��ָ�����ÿ�
	L->next = NULL;
	return OK;
}

//�ж������Ƿ�Ϊ��
int ListEmpty(LinkList& L)
{
	if (L->next)
		return 0;
	else
		return 1;

}

//��������
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

//�������
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

//������ĳ���
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

//��ȡ��i���ڵ�
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

//��ֵ����
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

//�ڵ�i��Ԫ��֮ǰ�����½ڵ�
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

//�����Ա��е�i��Ԫ��ɾ��
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p->next && j<i-1)  //�ҵ���i���ڵ�p
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

//ͷ�巨��������
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

//β�巨��������
void CreateList_R(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	LinkList r = L;  //βָ��ָ��ͷ�ڵ�
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