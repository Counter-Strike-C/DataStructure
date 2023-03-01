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


//树节点
typedef struct PTNode
{
	TElemType data;
	int parent;
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;  //根节点的位置和节点个数
}PTree;

//孩子链表

//孩子节点
typedef struct CTNode
{
	int child;
	struct CTNode* Next;
}*ChildPtr;

//双亲节点结构
typedef struct
{
	TElemType data;
	ChildPtr firstchild;  //指向双亲
}CTBox;

//树结构,带双亲的孩子链表
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//节点数和根节点位置
}CTree;