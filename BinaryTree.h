#pragma once
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
typedef struct {
	int a;
	string ch;
}TElemType;

#pragma region 二叉树的顺序存储
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion

#pragma region 二叉树的链式存储
typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;   //左右孩子指针
}BiNode,*BiTree;

//线索二叉树
typedef struct BiThrNode
{
	int data;
	int ltag, rtag;
	struct BiThrNode* lchild, * rchild;
}BiThrNode,*BiThrTree;

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
	stack<BiTree> s;
	BiTree p;
	
	p = T;
	while (p || s.empty())
	{
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p=s.top();
			s.pop();
			p = p->rchild;
			cout << p->data.a << endl;
		}
	}
	return OK;
}


//层次遍历算法
Status LevelOrder(BiNode* b)
{
	BiTree  p;
	queue<BiTree>  qu;
	qu.push(b);
	while (!qu.empty())
	{
		p=qu.front();

		qu.pop();
		cout << p->data.a << endl;
		if (p->lchild != NULL)qu.push(p->lchild);
		if (p->rchild != NULL)qu.push(p->rchild);
	}
}

//二叉树的创建
Status CreateBiTree(BiTree& T)
{
	string ch;
	cin >> ch;
	if (ch == "#")T = NULL;
	else
	{
		if (!(T = new BiNode))
			exit(OVERFLOW);
		T->data.ch = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

//复制二叉树
int Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
		NewT = NULL;
	else
	{
		NewT = new BiNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

//计算二叉树的深度
int m = 0, n = 0;
int Depth(BiTree T)
{
	
	if (T == NULL) return 0;
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		return m > n ? m + 1 : n + 1;
	}	
}

//计算节点总数
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

//计算叶子节点个数
int LeafCount(BiTree T)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
	{
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

//

#pragma endregion


