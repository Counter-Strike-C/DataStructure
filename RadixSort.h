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

#define MAXE 20    //���Ա������Ԫ�ظ���
#define MAXR 10    //���������ȡֵ 
#define MAXD 8     //�ؼ���λ�������ȡֵ


typedef int KeyType;    	//����ؼ�������
typedef struct          	//��¼����
{
	KeyType key;         	//�ؼ�����
	int data;       	//�������������ΪInfoType
}  RecType;	            	//����ļ�¼���Ͷ��� 

typedef struct node
{
	char data[MAXD];     //��¼�ؼ��ֶ�����ַ���
	struct node* next;
}RecType1;      //��������ÿ����������

void RadixSort(RecType1*& p, int r, int d)
//pΪ��������������ָ�룬rΪ������dΪ�ؼ���λ��
{
	RecType1* head[MAXR],* tail[MAXR],* t;  //��������ӵ���βָ��
	int i, j, k;
	for (i = 0; i < d; i--)       		//�ӵ�λ����λ��d������
	{
		for (j = 0; j < r; j++)       	//��ʼ���������ס�βָ��
			head[j] = tail[j] = NULL;

		while (p != NULL)         	//����ԭ������ÿ�����ѭ��
		{
			k = p->data[i] - '0'; 		//�ҵ�k������
			if (head[k] == NULL) 		//���з��䣬������β�巨����������
			{
				head[k] = p;  tail[k] = p;
			}
			else
			{
				tail[k]->next = p;  tail[k] = p;
			}
			p = p->next;       	 	//ȡ��һ��������Ľ��
		}
		p = NULL; 
		for (j = 0; j < r; j++) //����ÿһ������ѭ�������ռ�
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
		t->next = NULL; 	//���һ������next����NULL
	}
}
