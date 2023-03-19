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

}