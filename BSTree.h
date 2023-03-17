#pragma once
//����������
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#define MAXSIZE 100
const int MAXLEN = 255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
using namespace std;

typedef struct node
{
	int key;
	int data;
	struct node* lchild, * rchild;
}BSTNode;

BSTNode* SearchBST(BSTNode * bt, int k)
{
	if (bt == NULL || bt->key == k)
		return bt;
	if (k < bt->key)
		return SearchBST(bt->lchild, k);     //����������Ѱ��
	else
		return SearchBST(bt->rchild, k);     //����������Ѱ��
}


//��������������
int InsertBST(BSTNode*& p, int k)
{
	if (p == NULL)
	{
		p = new BSTNode();
		p->key = k;
		p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (k == p->key)
		return 0;
	else if (k < p->key)
		return InsertBST(p->lchild, k);
	else
		return InsertBST(p->rchild, k);
}

//��������������
BSTNode* CreatBST(int A[], int n)   //��������ָ��
{
	BSTNode* bt = NULL;
	int i = 0;
	while (i < n)
	{
		InsertBST(bt, A[i]);   //��A[i]����������T��
		i++;
	}
	return bt;   //���ؽ����Ķ����������ĸ�ָ��
}

//����������ɾ���ڵ���㷨
int DeleteBST(BSTNode*& bt, int k)
{
	if (bt == NULL) return 0;
	else
	{
		if (k < bt->key) return DeleteBST(bt->lchild, k);
		else if (k > bt->key) return DeleteBST(bt->rchild, k);
		else
		{
			Delete(bt);
			return 1;
		}
	}
}

void Delete(BSTNode*& p)
{
	BSTNode* q;
	if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else Delete1(p, p->lchild);
}

//����ɾ���Ľڵ�����������ʱ��ɾ������
void Delete1(BSTNode* p, BSTNode*& r)
{
	BSTNode* q;
	if (r->rchild != NULL)
		Delete1(p, r->rchild);    //�ҵ��������������ҽڵ�
	else
	{
		p->key = r->key;
		p->data = r->data;        //ֵ�滻
		q = r;
		r = r->lchild;      
		free(q);
	}
}