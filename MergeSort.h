#pragma once
//�鲢����
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

//һ�ζ�·�鲢�����������ڵ����������й鲢Ϊһ���������С�
void Merge(RecType R[], int low, int mid, int high)
{
	RecType *R1;
	int i = low, j = mid + 1, k = 0;   //k��R1���±꣬i��j�ֱ�Ϊ��1��2�ε��±�
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));
	while(i<=mid && j<=high)
		if (R[i].key <= R[j].key)     //����1���еļ�¼����R1��
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else         //����2���еļ�¼����R1��
		{
			R1[k] = R[j];
			j++;
			k++;
		}
	while (i<=mid)    //����1�����²��ָ��Ƶ�R1
	{
		R1[k] = R[i];
		i++;
		k++;
	}
	while (j <= high)    //����2�����²��ָ��Ƶ�R1
	{
		R1[k] = R[j];
		j++;
		k++;
	}

	for (k = 0, i = low; i < high; k++, i++)    	//��R1���ƻ�R��
		R[i] = R1[k];
	free(R1);
}

//һ�˶�·�鲢���γ���Ϊlength ��
void MergePass(RecType R[], int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)     //�鲢length�����������ӱ�
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)     //���µ������ӱ����߳���С��length
		Merge(R, i, i + length - 1, n - 1);
}

//��·�鲢�����㷨
void MergeSort(RecType R[],int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}