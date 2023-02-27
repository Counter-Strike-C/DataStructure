#pragma once
#include <stdlib.h>
#include<iostream>
#include "Stack.h"
#define MAXSIZE 100
const int MAXLEN = 255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct {
	int a;

}TElemType;

#pragma region 二叉树的顺序存储
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion


#pragma region 二叉树的链式存储
typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;   //左右孩子指针
}BiNode,*BiTree;

//三叉链表
typedef struct TriNode {
	TElemType data;
	struct BiNode* lchild,*parent, *rchild;   //左右孩子指针
}TriTNode, * TriTree;

//先根遍历
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL) return OK;
	else
	{
		visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//中根遍历
Status InOrderTraverse(BiTree T)
{
	if (T == NULL) return OK;
	else
	{
		PreOrderTraverse(T->lchild);
		visit(T);
		PreOrderTraverse(T->rchild);
	}
}

//后根遍历
Status PostOrderTraverse(BiTree T)
{
	if (T == NULL) return OK;
	else
	{
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		visit(T);
	}
}

//访问根节点
void visit(BiTree T)
{

}

//中序非递归算法
Status InOrderTraverse(BiTree T)
{
	BiTree P;
	
}
#pragma endregion


