#pragma once
//选择排序算法
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

typedef int KeyType;    	//定义关键字类型
typedef struct          	//记录类型
{
	KeyType key;         	//关键字项
	int data;       	//其他数据项，类型为InfoType
}  RecType;	            	//排序的记录类型定义 

//简单选择排序
void SelectSort(RecType R[], int n)
{
	int i, j, k;
	RecType tmp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (R[j].key < R[k].key)
				k = j;     //找到最小的一个下标
		if (k != i)
		{
			tmp = R[i];
			R[i] = R[k];
			R[k] = tmp;
		}
	}
}

//堆排序的调整算法
void sift(RecType R[], int low, int high)
{
	int i = low;
	int j = 2 * i;
	RecType tmp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key)j++;
		if (tmp.key < R[j].key)  //如果双亲小
		{
			R[i] = R[j]; //则交换，将R[j]调整到双亲节点位置
			i = j;          //修改i和j的值，以便继续向下筛选
			j = 2 * i;
		}
		else break;      //双亲大不再调整
	}
	R[i] = tmp;
}

//堆排序的算法   O(nlog2 n)
void HeapSort(RecType R[], int n)
{
	int i;
	RecType tmp;
	for (i = n / 2; i >= 1; i--)     //循环建立初始堆，调整原数组未初始大根堆
		sift(R, i, n);

	for (i = n; i >= 2; i--)   //进行n-1次循环，完成堆排序
	{
		tmp = R[1];   //R[1]和R[i]进行交换
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);    //筛选R[1]节点，得到i-1个节点的堆
	}
}