#pragma once
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include "Queue.h"
#define MaxInt 32727      //��ʾ����ֵ
#define MVNum 100       //��󶥵���
#define MAX_TREE_SIZE 100
const int MAXLEN = 255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char VerTexType;      //������������Ϊ�ַ���
typedef int ArcType;     //�ߵ�Ȩֵ����Ϊ����
using namespace std;

#pragma region �ڽӾ���洢�ṹ
typedef struct {
	VerTexType vexs[MVNum];  //�����
	ArcType arcvs[MVNum][MVNum];   //�ڽӾ���
	int vexnum, arcnum;     //�������ͱ���
}AMGraph;

//�����ڽӾ����ʾ������������
Status CreateUDN(AMGraph& G)
{
	cin >> G.vexnum >> G.arcnum;   //�����ܶ��������ܱ���
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];

	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcvs[i][j] = MaxInt;
	int i = 0;
	int j = 0;
	for (int k = 0; k < G.arcnum; k++)  //�����ڽӾ���
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

//�ҵ������λ��
int LocateVex(AMGraph& G, VerTexType& v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (v == G.vexs[i])return i;
	return -1;
}

//������ȱ����ڽӾ���
void DFS(AMGraph &G, int v)
{
	int visited[MAXLEN];
	visited[v] = 1;
	cout << v;
	for (int i = 0; i < G.vexnum; i++)
	{
		if ((G.arcvs[v][i] != 0) && (!visited[i]))      //���v��i���ڽӵ㣬���δ���ʣ���ݹ����DFS
			DFS(G, i);
	}
}

#pragma endregion

#pragma region �ڽ�����洢�ṹ

//����Ľṹ
typedef struct VNode
{
	VerTexType data;
	ArcNode* firstarc;       //ָ���һ�������ö����ָ��
}VNode, AdjList[MVNum];


//���ߵĽṹ
typedef struct ArcNode
{
	int adjvex;         //�ñ�ָ��Ķ����λ��
	struct ArcNode* nextarc;     //ָ��x��һ���ߵ�ָ��
	OtherInfo info;         //�ͱ���ص���Ϣ
}ArcNode;

typedef struct OtherInfo   //��Ϣ����
{
	int message;
}OtherInfo;

//ͼ�Ľṹ����
typedef struct
{
	AdjList vertices;       //vertex�ĸ���
	int vexnum, arcnum;     //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;

//�����ڽӱ��ʾ������������	
Status CreateUDG(ALGraph& G)   
{
	cin >> G.vexnum >> G.arcnum;   //�����ܶ��������ܱ���
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;     //���붥��ֵ
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; ++k)  //������߹����ڽӱ�
	{
		int v1, v2;
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);   
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;   //�����µı߽ڵ�
		p1->adjvex = j;     //�ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;  //ͷ�巨�����߽������
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
		if (v == G.vertices[i].data)return i;   //�ҵ�ָ���ڵ�λ��
	return -1;
}

//������ȱ����ٽ�����
void DFS(ALGraph* G, int v)
{
	ArcNode* p;
	int w;
	int visited[MAXLEN];
	visited[v] = 1;     //���ѷ��ʱ��
	cout << v;
	p = G->vertices[v].firstarc;    //pָ�򶥵�v�ĵ�һ����ͷ�ڵ�

	while (p != NULL)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			DFS(G, w);    //���w����δ���ʣ��ݹ������
		p = p->nextarc;   //pָ�򶥵�v����һ����ͷ�ڵ�
	}
}

//������ȱ���
void BFS(ALGraph* G, int v)
{
	queue<int> qu;
	int w, i;
	ArcNode* p;
	//SqQueue qu;    //���廷�ζ���
	//InitQueue(qu);
	int visited[MAXLEN];        //���嶥���������
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;    //��ʼ���������
	cout << v;
	visited[v] = 1;
	qu.push(v);   //��v��ʼ���

	while (!qu.empty())  //֪������Ϊ�ս���
	{
		w = qu.front();
		qu.pop();
		p = G->vertices[w].firstarc;   // ȡ����һ����
		while (p!=NULL)
		{
			if (visited[p->adjvex] == 0)//���û�з��ʵ�
			{
				cout << p->adjvex;
				visited[p->adjvex] = 1;  //������
				qu.push(p->adjvex);   //���ѷ��ʵĵ����
			}
		}
	}
	cout << endl;
	//�㷨ʱ�临�Ӷ�δO(n+e)
}
#pragma endregion


#pragma region ��С�������㷨

//Prim�㷨
#define INF 32767
void Prim(AMGraph& G, int v)
{
	int lowcost[MAXLEN];
	int min;
	int closet[MAXLEN], i, j, k;
	for (int i = 0; i < G.vexnum; i++)    //��lowcost��closet�ó�ֵ
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
				k = j;          //��¼����v����Ķ�����
			}
		}

		cout << closet[k] << "��" << k << "��ȨΪ��" << min << endl;
		lowcost[k] = 0;       //���k�Ѿ�����U

		for(j=0;j<G.vexnum;j++)  //�޸�����lowcost��closet
			if (lowcost[j] != 0 && G.arcvs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcvs[k][j];
				closet[j] = k;
			}
	}
}


//Kruskal�㷨
typedef struct
{
	int u;      //�ߵ���ʼ����
	int v;       //�ߵ���ֹ����
	int w;      //�ߵ�Ȩֵ
}Edge;

//Kruskal�㷨
void Kruskal(AMGraph& G)
{
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXLEN];       //��ͨ�������
	Edge E[MAXLEN]; //������б�
	k = 0;         //E�������±��0��ʼ
	for(i=0;i<G.vexnum;i++)     //��G�����ı߼�E���߼��ĳ�ʼ��
		for(j=0;j<G.vexnum;j++)
			if (G.arcvs[i][i] != 0 && G.arcvs[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.arcvs[i][j];
			}
	InsertSort(E, G.arcnum);   //����ʹ�õ������� O(n^2)
	//HeapSort(E, g.e);    //������O(eloge)
	for (i = 0; i < G.arcnum; i++)  //��ʼ����������
	{
		vset[i] = i;  //��ͨ������ʼ��
	}
	k = 1;
	j = 0;
	while (k < G.arcnum)   //���ɵı���С��nʱѭ��
	{
		u1 = E[j].u;   //ȡһ���ߵ�ͷβ����
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];      //�õ��������������ļ��ϱ��
		if (sn1 != sn2)      //���������ڲ�ͬ�ļ���
		{
			cout << u1 << " " << v1 << " " << E[j].w << endl;
			k++;    //���ɱ�����1
			for (i = 0; i < G.arcnum; i++)  //��������ͬ����
				if (vset[i] == sn2)   //���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i] = sn1;
		}
		j++;
	}
}

void InsertSort(Edge* E, int v)
{

}

//dijkstra�㷨,vΪԴ����
void Dijkstra(AMGraph G,int v)
{
	int dist[MAXLEN], path[MAXLEN];
	int s[MAXLEN];
	int mindis, i, j, u;
	for (i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.arcvs[v][i];  //�����ʼ��
		s[i] = 0;        //s[]�ÿ�
		if (G.arcvs[v][i] < INF)     //·����ʼ��
			path[i] = v;         //����v��i�б�ʱ
		else
			path[i] = -1;       //����v��iû��ʱ
	}
	s[v] = 1;     //Դ��v����s��

	for (i = 0; i < G.vexnum; i++)     //ѭ��n-1�Σ������u����s��
	{
		mindis = INF;
		for(j=0;j<G.vexnum;j++)
			if (s[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		s[u] = 1;		//����u���뵽s
		for(j=0;j<G.vexnum;j++)      //�޸Ĳ���s�еĶ������
			if(s[j] == 0)
				if (G.arcvs[u][j] < INF && dist[u] + G.arcvs[u][j] < dist[j])
				{
					dist[j] = dist[u] + G.arcvs[u][j];
					path[j] = u;
				}
	}
	Dispath(dist, path, s, G.arcnum, v);       //������·��
}



//������·��
void Dispath(int * dis, int * path, int * s, int n, int v)
{

}
#pragma endregion

