///ѭ������
/// 

#include "SQList.h"
using namespace std;

//��ʼ����ѭ������
Status InitList_C(LinkList &L)
{
	L = new Lnode;
	if (L == NULL)
		L->next = L;
	return OK;
}

//�ϲ�������βָ��ĵ�ѭ������
LinkList Connect(LinkList Ta, LinkList Tb)
{
	LinkList p = Ta->next;
	Ta->next = Tb->next->next;  //tb��ͷ����ta��β
	delete Tb->next;
	Tb->next = p;    //��βָ���ͷ
	return Tb;

}