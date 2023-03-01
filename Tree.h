#pragma once

#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#define MAXSIZE 100
#define MAX_TREE_SIZE 100
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


//���ڵ�
typedef struct PTNode
{
	TElemType data;
	int parent;
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;  //���ڵ��λ�úͽڵ����
}PTree;

//��������

//���ӽڵ�
typedef struct CTNode
{
	int child;
	struct CTNode* Next;
}*ChildPtr;

//˫�׽ڵ�ṹ
typedef struct
{
	TElemType data;
	ChildPtr firstchild;  //ָ��˫��
}CTBox;

//���ṹ,��˫�׵ĺ�������
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//�ڵ����͸��ڵ�λ��
}CTree;