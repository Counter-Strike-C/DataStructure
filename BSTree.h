#pragma once
//二叉排序树
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
		return SearchBST(bt->lchild, k);     //在左子树中寻找
	else
		return SearchBST(bt->rchild, k);     //在右子树中寻找
}


//二叉搜索数插入
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

//创建二叉搜索树
BSTNode* CreatBST(int A[], int n)   //返回树根指针
{
	BSTNode* bt = NULL;
	int i = 0;
	while (i < n)
	{
		InsertBST(bt, A[i]);   //将A[i]插入排序树T中
		i++;
	}
	return bt;   //返回建立的二叉排序树的根指针
}

//二叉排序树删除节点的算法
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

//当被删除的节点有左右子树时的删除过程
void Delete1(BSTNode* p, BSTNode*& r)
{
	BSTNode* q;
	if (r->rchild != NULL)
		Delete1(p, r->rchild);    //找到左字数中最大的右节点
	else
	{
		p->key = r->key;
		p->data = r->data;        //值替换
		q = r;
		r = r->lchild;      
		free(q);
	}
}