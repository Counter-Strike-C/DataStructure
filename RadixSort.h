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
}RecType1;      //单链表中每个结点的类型

void RadixSort(RecType1*& p, int r, int d)
//p为待排序序列链表指针，r为基数，d为关键字位数
{
	RecType1* head[MAXR],* tail[MAXR],* t;  //定义各链队的首尾指针
	int i, j, k;
	for (i = 0; i < d; i--)       		//从低位到高位做d趟排序
	{
		for (j = 0; j < r; j++)       	//初始化各链队首、尾指针
			head[j] = tail[j] = NULL;

		while (p != NULL)         	//对于原链表中每个结点循环
		{
			k = p->data[i] - '0'; 		//找第k个链队
			if (head[k] == NULL) 		//进行分配，即采用尾插法建立单链表
			{
				head[k] = p;  tail[k] = p;
			}
			else
			{
				tail[k]->next = p;  tail[k] = p;
			}
			p = p->next;       	 	//取下一个待排序的结点
		}
		p = NULL; 
		for (j = 0; j < r; j++) //对于每一个链队循环进行收集
			if (head[j] != NULL)
			{
				if (p == NULL)
				{
					p = head[j];
					t = tail[j];
				}
				else
				{
					t->next = head[j];
					t = tail[j];
				}
			}
		t->next = NULL; 	//最后一个结点的next域置NULL
	}
}
