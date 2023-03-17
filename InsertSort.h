#pragma once  //�����㷨
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

typedef int KeyType;    	//����ؼ�������
typedef struct          	//��¼����
{
	KeyType key;         	//�ؼ�����
	int data;       	//�������������ΪInfoType
}  RecType;	            	//����ļ�¼���Ͷ��� 


//ֱ�Ӳ�������
void InsertSort(RecType R[], int n)
{
	int i, j;
	RecType tmp;
	for (i = 0; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)   //����ʱ
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

//�۰��������
void BinInsertSort(RecType R[], int n)
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)     //����ʱ
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
			for (j = i - 1; j >= high + 1; j--)     //��¼����
				R[j+1] = R[j];
		}
	}
}