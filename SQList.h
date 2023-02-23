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

//���Ա��ʾ1
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//���Ա��ʾ2
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

//˫������
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

static class SQList
{
public:

	//���Ա�ĳ�ʼ��
	Status InitList_Sq(SqList& L)
	{
		L.elem = new ElemType[MAXSIZE];
		if (!L.elem)exit(OVERFLOW);
		L.length = 0;
		return OK;
	}

	//�������Ա�
	void DestroyList(SqList& L)
	{
		if (L.elem)delete L.elem;
	}

	//������Ա�
	void ClearList(SqList& L) {
		L.length = 0;   //�����Ա�����Ϊ0
	}

	//�����Ա�ĳ���
	int GetLength(SqList L)
	{
		return L.length;
	}

	//�ж����Ա��Ƿ�Ϊ��
	int IsEmpty(SqList L)
	{
		return L.length == 0 ? 1 : 0;
	}

	int GetElem(SqList L, int i, ElemType& e) {
		if (i<1 || i>L.length)return ERROR;
		e = L.elem[i - 1];
		return OK;
	}

	//�ҵ�Ԫ��λ��
	static int LocateElem(SqList L, ElemType e)
	{
		for (int i = 0; i < L.length; i++)
		{
			if (L.elem[i].a==e.a)return i + 1;
		}
	}

	//ɾ��ָ��Ԫ��
	Status ListDelete_Sq(SqList& L, int i) {
		if (i<1 || i>L.length)return ERROR;
		for (int j =  i; j < L.length; j++)
		{
			L.elem[j - 1] = L.elem[j];
		}

		L.length--;
		return OK;
	}

	//����Ԫ��
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

