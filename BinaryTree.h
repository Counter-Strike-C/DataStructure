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

#pragma region ��������˳��洢
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion


#pragma region ����������ʽ�洢
typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;   //���Һ���ָ��
}BiNode,*BiTree;

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
	BiTree P;
	
}
#pragma endregion


