#pragma once
//ѡ�������㷨
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

//��ѡ������
void SelectSort(RecType R[], int n)
{
	int i, j, k;
	RecType tmp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (R[j].key < R[k].key)
				k = j;     //�ҵ���С��һ���±�
		if (k != i)
		{
			tmp = R[i];
			R[i] = R[k];
			R[k] = tmp;
		}
	}
}

//������ĵ����㷨
void sift(RecType R[], int low, int high)
{
	int i = low;
	int j = 2 * i;
	RecType tmp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key)j++;
		if (tmp.key < R[j].key)  //���˫��С
		{
			R[i] = R[j]; //�򽻻�����R[j]������˫�׽ڵ�λ��
			i = j;          //�޸�i��j��ֵ���Ա��������ɸѡ
			j = 2 * i;
		}
		else break;      //˫�״��ٵ���
	}
	R[i] = tmp;
}

//��������㷨   O(nlog2 n)
void HeapSort(RecType R[], int n)
{
	int i;
	RecType tmp;
	for (i = n / 2; i >= 1; i--)     //ѭ��������ʼ�ѣ�����ԭ����δ��ʼ�����
		sift(R, i, n);

	for (i = n; i >= 2; i--)   //����n-1��ѭ������ɶ�����
	{
		tmp = R[1];   //R[1]��R[i]���н���
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);    //ɸѡR[1]�ڵ㣬�õ�i-1���ڵ�Ķ�
	}
}