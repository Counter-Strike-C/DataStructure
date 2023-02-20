#include "SQList.h"
using namespace std;


//获取第i个节点
DuLinkList GetElemP_DuL(DuLinkList& L, int i)
{
	DuLinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	DuLinkList e = p;
	return e;
}

Status ListInsert_DuL(DuLinkList& L, int i, ElemType e)
{
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))return ERROR;
	DuLinkList s = new DuLNode;
	s -> data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;

}

//删除指定节点
Status ListDelete_DuL(DuLinkList& L, int i, ElemType& e)
{
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))return ERROR;  
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}