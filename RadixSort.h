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

#define MAXE 20    //线性表中最多元素个数
#define MAXR 10    //基数的最大取值 
#define MAXD 8     //关键字位数的最大取值


typedef int KeyType;    	//定义关键字类型
typedef struct          	//记录类型
{
	KeyType key;         	//关键字项
	int data;       	//其他数据项，类型为InfoType
}  RecType;	            	//排序的记录类型定义 

typedef struct node
{
	char data[MAXD];     //记录关键字定义的字符串
	struct node* next;
}Rectype1;      //单链表中每个结点的类型