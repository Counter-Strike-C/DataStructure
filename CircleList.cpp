///循环链表
/// 

#include "SQList.h"
using namespace std;

//初始化单循环链表
Status InitList_C(LinkList &L)
{
	L = new Lnode;
	if (L == NULL)
		L->next = L;
	return OK;
}

//合并两个带尾指针的单循环链表
LinkList Connect(LinkList Ta, LinkList Tb)
{
	LinkList p = Ta->next;
	Ta->next = Tb->next->next;  //tb表头连接ta表尾
	delete Tb->next;
	Tb->next = p;    //表尾指向表头
	return Tb;

}