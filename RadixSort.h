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
}Rectype1;      //��������ÿ����������