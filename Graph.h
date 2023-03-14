#pragma once
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include "Queue.h"
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

//找到顶点的位置
int LocateVex(AMGraph& G, VerTexType& v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (v == G.vexs[i])return i;
	return -1;
}

//深度优先遍历邻接矩阵
void DFS(AMGraph &G, int v)
{
	int visited[MAXLEN];
	visited[v] = 1;
	cout << v;
	for (int i = 0; i < G.vexnum; i++)
	{
		if ((G.arcvs[v][i] != 0) && (!visited[i]))      //如果v和i是邻接点，如果未访问，则递归调用DFS
			DFS(G, i);
	}
}

#pragma endregion

#pragma region 邻接链表存储结构

//顶点的结构
typedef struct VNode
{
	VerTexType data;
	ArcNode* firstarc;       //指向第一条依附该顶点的指针
}VNode, AdjList[MVNum];


//弧边的结构
typedef struct ArcNode
{
	int adjvex;         //该边指向的顶点的位置
	struct ArcNode* nextarc;     //指向x下一条边的指针
	OtherInfo info;         //和边相关的信息
}ArcNode;

typedef struct OtherInfo   //信息定义
{
	int message;
}OtherInfo;

//图的结构定义
typedef struct
{
	AdjList vertices;       //vertex的复数
	int vexnum, arcnum;     //图的当前顶点数和弧数
}ALGraph;

//采用邻接表表示法创建无向网	
Status CreateUDG(ALGraph& G)   
{
	cin >> G.vexnum >> G.arcnum;   //输入总顶点数，总边数
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;     //输入顶点值
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; ++k)  //输入各边构造邻接表
	{
		int v1, v2;
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);   
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;   //生成新的边节点
		p1->adjvex = j;     //邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;  //头插法建立边界点链表
		ArcNode* p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
}

int LocateVex(ALGraph& G, int& v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (v == G.vertices[i].data)return i;   //找到指定节点位置
	return -1;
}

//深度优先遍历临界链表
void DFS(ALGraph* G, int v)
{
	ArcNode* p;
	int w;
	int visited[MAXLEN];
	visited[v] = 1;     //置已访问标记
	cout << v;
	p = G->vertices[v].firstarc;    //p指向顶点v的第一条边头节点

	while (p != NULL)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			DFS(G, w);    //如果w顶点未访问，递归访问它
		p = p->nextarc;   //p指向顶点v的下一条边头节点
	}
}

//广度优先遍历
void BFS(ALGraph* G, int v)
{
	queue<int> qu;
	int w, i;
	ArcNode* p;
	//SqQueue qu;    //定义环形队列
	//InitQueue(qu);
	int visited[MAXLEN];        //定义顶点访问数组
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;    //初始化标记数组
	cout << v;
	visited[v] = 1;
	qu.push(v);   //从v开始入队

	while (!qu.empty())  //知道队列为空结束
	{
		w = qu.front();
		qu.pop();
		p = G->vertices[w].firstarc;   // 取出第一条边
		while (p!=NULL)
		{
			if (visited[p->adjvex] == 0)//如果没有访问到
			{
				cout << p->adjvex;
				visited[p->adjvex] = 1;  //访问了
				qu.push(p->adjvex);   //将已访问的点入队
			}
		}
	}
	cout << endl;
	//算法时间复杂度未O(n+e)
}
#pragma endregion


#pragma region 最小生成树算法

//Prim算法
#define INF 32767
void Prim(AMGraph& G, int v)
{
	int lowcost[MAXLEN];
	int min;
	int closet[MAXLEN], i, j, k;
	for (int i = 0; i < G.vexnum; i++)    //给lowcost和closet置初值
	{
		lowcost[i] = G.arcvs[v][i];
		closet[i] = v;
	}

	for (i = 1; i < G.vexnum; i++)
	{
		min = INF;
		for (j = 0; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;          //记录距离v最近的顶点编号
			}
		}

		cout << closet[k] << "到" << k << "边权为：" << min << endl;
		lowcost[k] = 0;       //标记k已经加入U

		for(j=0;j<G.vexnum;j++)  //修改数组lowcost和closet
			if (lowcost[j] != 0 && G.arcvs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcvs[k][j];
				closet[j] = k;
			}
	}
}


//Kruskal算法
typedef struct
{
	int u;      //边的起始顶点
	int v;       //边的终止顶点
	int w;      //边的权值
}Edge;

//Kruskal算法
void Kruskal(AMGraph& G)
{
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXLEN];       //连通分量编号
	Edge E[MAXLEN]; //存放所有边
	k = 0;         //E的数组下标从0开始
	for(i=0;i<G.vexnum;i++)     //由G产生的边集E，边集的初始化
		for(j=0;j<G.vexnum;j++)
			if (G.arcvs[i][i] != 0 && G.arcvs[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.arcvs[i][j];
			}
	InsertSort(E, G.arcnum);   //排序使用递增排序 O(n^2)
	//HeapSort(E, g.e);    //堆排序O(eloge)
	for (i = 0; i < G.arcnum; i++)  //初始化辅助数据
	{
		vset[i] = i;  //连通分量初始化
	}
	k = 1;
	j = 0;
	while (k < G.arcnum)   //生成的边数小于n时循环
	{
		u1 = E[j].u;   //取一条边的头尾顶点
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];      //得到两个顶点所属的集合编号
		if (sn1 != sn2)      //两顶点属于不同的集合
		{
			cout << u1 << " " << v1 << " " << E[j].w << endl;
			k++;    //生成边数增1
			for (i = 0; i < G.arcnum; i++)  //两个集合同意编号
				if (vset[i] == sn2)   //集合编号为sn2的改为sn1
					vset[i] = sn1;
		}
		j++;
	}
}

void InsertSort(Edge* E, int v)
{

}

//dijkstra算法,v为源点编号
void Dijkstra(AMGraph G,int v)
{
	int dist[MAXLEN], path[MAXLEN];
	int s[MAXLEN];
	int mindis, i, j, u;
	for (i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.arcvs[v][i];  //距离初始化
		s[i] = 0;        //s[]置空
		if (G.arcvs[v][i] < INF)     //路径初始化
			path[i] = v;         //顶点v到i有边时
		else
			path[i] = -1;       //顶点v到i没边时
	}
	s[v] = 1;     //源点v放入s中

	for (i = 0; i < G.vexnum; i++)     //循环n-1次，逐个将u放入s中
	{
		mindis = INF;
		for(j=0;j<G.vexnum;j++)
			if (s[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		s[u] = 1;		//顶点u加入到s
		for(j=0;j<G.vexnum;j++)      //修改不在s中的顶点距离
			if(s[j] == 0)
				if (G.arcvs[u][j] < INF && dist[u] + G.arcvs[u][j] < dist[j])
				{
					dist[j] = dist[u] + G.arcvs[u][j];
					path[j] = u;
				}
	}
	Dispath(dist, path, s, G.arcnum, v);       //输出最短路径
}



//输出最短路径
void Dispath(int * dis, int * path, int * s, int n, int v)
{

}
#pragma endregion

