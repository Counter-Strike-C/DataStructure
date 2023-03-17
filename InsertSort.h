#pragma once  //排序算法
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


//直接插入排序
void InsertSort(RecType R[], int n)
{
	int i, j;
	RecType tmp;
	for (i = 0; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)   //反序时
		{
			tmp = R[i];
			j = i - 1;
			do
			{
				R[j + 1] = R[j];
				j--;
			} while (j>=0&&R[j].key>tmp.key);
			R[j + 1] = tmp;
		}
	}
 }

//折半插入排序
void BinInsertSort(RecType R[], int n)
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)     //反序时
		{
			tmp = R[i];
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp.key < R[mid].key)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)     //记录后移
				R[j+1] = R[j];
		}
	}
}