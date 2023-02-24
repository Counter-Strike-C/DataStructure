#pragma once
#include <stdlib.h>
#include<iostream>
#define MAXSIZE 100
const int MAXLEN=255;
const int CHUNKSIZE=255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#pragma region ����˳��洢
typedef struct
{
	char ch[MAXLEN + 1];
	int length;
}SString;

void get_next(SString T, int(&next)[MAXLEN + 1])
{
	int j = 0, k = -1;

	next[0] = -1;
	while (j < T.length - 1)
	{
		if (k == -1 || T.ch[j] == T.ch[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void GetNextval(SString t, int(&nextval)[MAXLEN + 1])  //��ģʽ��t���nextvalֵ
{
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length)
	{
		if (k == -1 || t.ch[j] == t.ch[k])
		{
			j++; k++;
			if (t.ch[j] != t.ch[k])
				nextval[j] = k;
			else
				nextval[j] = nextval[k];
		}
		else  k = nextval[k];
	}
}

//KMP�㷨
int Index_KMP(SString S, SString T)
{

	int next[MAXLEN + 1];
	//get_next(T, next);
	GetNextval(T, next);    //�Ľ���ȡֵ
	int i = 0;
	int j = 0;
	while (i<S.length && j<T.length)
	{
		if (j == -1	 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= T.length)return i - T.length;   //����ģʽƥ�䴮�����ַ�
	else return -1;     //���ز�ƥ���־
}
#pragma endregion

#pragma region ������ʽ�洢
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct  Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail;
	int curlen;
}LString;
#pragma endregion

