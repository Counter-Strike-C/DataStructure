#pragma once
//���������㷨
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


//ð������
void BubbleSort(RecType R[], int n)
{
	int i, j;
	RecType temp;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--)
			if (R[j].key < R[j - 1].key)
			{
				temp = R[j];    //����R[j]��R[j-1]
				R[j] = R[j - 1];
				R[j - 1] = temp;
			}
}

//�Ľ���ð�������㷨
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
				temp = R[j];    //����R[j]��R[j-1]
				R[j] = R[j - 1];
				R[j - 1] = temp;
				exchange = true;
			}
		if (exchange == false) return;  //�������������;�����㷨
	}
}

//���������㷨
void QuickSort(RecType R[], int s, int t) //��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i = s, j = t; RecType tmp;
	if (s < t)
	{
		tmp = R[s];
		while (i != j)
		{
			while (j > i && R[j].key >= tmp.key) j--;
			R[i] = R[j];  //ֱ���ҵ�һ����tmpС��ֵ
			while (i < j && R[i].key <= tmp.key)i++;
			R[j] = R[i];//ֱ���ҵ�һ����tmp���ֵ
		}
		R[i] = tmp;  //��ʱi=j��
		QuickSort(R, s, i - 1);    //����������еݹ�����
		QuickSort(R, j + 1, t);   //����������еݹ�����
	}
}