#pragma once
//归并排序
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

//一次二路归并，将两个相邻的有序子序列归并为一个有序序列。
void Merge(RecType R[], int low, int mid, int high)
{
	RecType *R1;
	int i = low, j = mid + 1, k = 0;   //k是R1的下标，i、j分别为第1、2段的下标
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));
	while(i<=mid && j<=high)
		if (R[i].key <= R[j].key)     //将第1段中的记录放入R1中
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else         //将第2段中的记录放入R1中
		{
			R1[k] = R[j];
			j++;
			k++;
		}
	while (i<=mid)    //将第1段余下部分复制到R1
	{
		R1[k] = R[i];
		i++;
		k++;
	}
	while (j <= high)    //将第2段余下部分复制到R1
	{
		R1[k] = R[j];
		j++;
		k++;
	}

	for (k = 0, i = low; i < high; k++, i++)    	//将R1复制回R中
		R[i] = R1[k];
	free(R1);
}

//一趟二路归并（段长度为length ）
void MergePass(RecType R[], int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)     //归并length长的两相邻子表
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)     //余下的两个子表，后者长度小于length
		Merge(R, i, i + length - 1, n - 1);
}

//二路归并排序算法
void MergeSort(RecType R[],int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}