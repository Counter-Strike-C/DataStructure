#pragma once
//交换排序算法
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


//冒泡排序
void BubbleSort(RecType R[], int n)
{
	int i, j;
	RecType temp;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--)
			if (R[j].key < R[j - 1].key)
			{
				temp = R[j];    //交换R[j]和R[j-1]
				R[j] = R[j - 1];
				R[j - 1] = temp;
			}
}

//改进的冒泡排序算法
void BubbleSort1(RecType R[], int n)
{
	int i, j;
	bool exchange;
	RecType temp;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
			if (R[j].key < R[j - 1].key)
			{
				temp = R[j];    //交换R[j]和R[j-1]
				R[j] = R[j - 1];
				R[j - 1] = temp;
				exchange = true;
			}
		if (exchange == false) return;  //若是有序的则中途结束算法
	}
}

//快速排序算法
void QuickSort(RecType R[], int s, int t) //对R[s]至R[t]的元素进行快速排序
{
	int i = s, j = t; RecType tmp;
	if (s < t)
	{
		tmp = R[s];
		while (i != j)
		{
			while (j > i && R[j].key >= tmp.key) j--;
			R[i] = R[j];  //直到找到一个比tmp小的值
			while (i < j && R[i].key <= tmp.key)i++;
			R[j] = R[i];//直到找到一个比tmp大的值
		}
		R[i] = tmp;  //此时i=j了
		QuickSort(R, s, i - 1);    //对左区间进行递归排序
		QuickSort(R, j + 1, t);   //对又区间进行递归排序
	}
}