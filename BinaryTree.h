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

#pragma region ��������˳��洢
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion

#pragma region ����������ʽ�洢
typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;   //���Һ���ָ��
}BiNode,*BiTree;

//����������
typedef struct BiThrNode
{
	int data;
	int ltag, rtag;
	struct BiThrNode* lchild, * rchild;
}BiThrNode,*BiThrTree;

//��������
typedef struct TriNode {
	TElemType data;
	struct BiNode* lchild,*parent, *rchild;   //���Һ���ָ��
}TriTNode, * TriTree;

//�ȸ�����
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

//�и�����
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

//�������
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

//���ʸ��ڵ�
void visit(BiTree T)
{

}

//����ǵݹ��㷨
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


//��α����㷨
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

//�������Ĵ���
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

//���ƶ�����
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

//��������������
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

//����ڵ�����
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

//����Ҷ�ӽڵ����
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


