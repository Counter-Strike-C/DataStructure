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

//霍夫曼树节点定义
typedef struct {
	int weight;
	int parent, lch,rch;
}HTNode,*HuffmanTree;

char* HuffmanCode;

void CreateHuffmanTree(HuffmanTree HT, int n)
{
	if (n <= 1)return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i < m; ++i)
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}

	for (int i = 1; i < n; i++)
	{
		cin >> HT[i].weight;
	}
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, s1, s2);

		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//筛选出最小的两个数
void Select(HuffmanTree HT, int ii, int &s1, int &s2)
{
	int tmp = HT[0].weight;
	s1 = 0;
	for (int  i = 0; i < ii; i++)
	{
		if (tmp > HT[i].weight)
		{
			tmp = HT[i].weight;
			s1 = i;
		}
	}
	int tmp = HT[0].weight;
	s2 = 0;
	for (int i = 0; i < ii; i++)
	{
		if (i == s1)continue;
		if (tmp > HT[i].weight)
		{
			tmp = HT[i].weight;
			s1 = i;
		}
	}
}

typedef struct
{
	char cd;		//存放哈夫曼码
} HuffmanCode;

//创建哈夫曼编码
void CreateHuffmanCode(HuffmanTree& HT, int n)
{
	char ** HC = new char* [n + 1];
	char *cd = new char[n];
	cd[n - 1] = '\0';
	int start,c,f;
	for (int i = 0; i <= n; i++)
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lch == c) cd[start] = '0';
			else cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
	  
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}

