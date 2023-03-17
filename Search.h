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

#define MAXL <表中最多记录个数>
typedef struct
{
	int key; 	  	//KeyType为关键字的数据类型
	int data;  		//其他数据项
}  RecType;			//查找顺序表元素类型

//顺序查找
int Search_Seq(RecType R[], int n,int key)   //若返回其位置信息
{
	int i = 0;
	while (i < n && R[i].key != key)
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1;
}

//二叉树查找
int Search_Bin(RecType R[], int n, int k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid].key == k)return mid + 1;    //查找成功返回逻辑序号
		if (k < R[mid].key)high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
