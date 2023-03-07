#pragma once
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
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

void DFS(AMGraph &G, int v)
{
	int visited[MAXLEN];
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

#pragma endregion

