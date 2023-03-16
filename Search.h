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

#define MAXL <��������¼����>
typedef struct
{
	int key; 	  	//KeyTypeΪ�ؼ��ֵ���������
	int data;  		//����������
}  RecType;			//����˳���Ԫ������

//˳�����
int Search_Seq(RecType R[], int n,int key)   //��������λ����Ϣ
{
	int i = 0;
	while (i < n && R[i].key != key)
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1;
}

//����������
int Search_Bin(RecType R[], int n, int k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid].key == k)return mid + 1;    //���ҳɹ������߼����
		if (k < R[mid].key)high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
