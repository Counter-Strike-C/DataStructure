#pragma once
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#define MaxInt 32727      //表示极大值
#define MVNum 100       //最大顶点数
#define MAX_TREE_SIZE 100
const int MAXLEN = 255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char VerTexType;      //顶点数据类型为字符型
typedef int ArcType;     //边的权值类型为整型
using namespace std;

#pragma region 邻接矩阵存储结构
typedef struct {
	VerTexType vexs[MVNum];  //顶点表
	ArcType arcvs[MVNum][MVNum];   //邻接矩阵
	int vexnum, arcnum;     //顶点数和边数
}AMGraph;

//利用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph& G)
{
	cin >> G.vexnum >> G.arcnum;   //输入总顶点数和总边数
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];

	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcvs[i][j] = MaxInt;
	int i = 0;
	int j = 0;
	for (int k = 0; k < G.arcnum; k++)  //构造邻接矩阵
	{
		char v1;
		char v2;
		int w;
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcvs[i][j] = w;
		G.arcvs[j][i] = G.arcvs[i][j];

	}
}

int LocateVex(AMGraph& G, VerTexType& v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (v == G.vexs[i])return i;
	return -1;
}
#pragma endregion

#pragma region 邻接链表存储结构

typedef struct VNode
{
	VerTexType data;
	ArcNode* firstarc;       //指向第一条依附该顶点的指针
}VNode, AdjList[MVNum];


//弧边的节点结构
typedef struct ArcNode
{
	int adjvex;         //该边指向的顶点的位置
	struct ArcNode* nextarc;     //指向吓一条边的指针
	OtherInfo info;         //和边相关的信息
}ArcNode;
typedef struct OtherInfo
{
	int message;
}OtherInfo;
#pragma endregion

