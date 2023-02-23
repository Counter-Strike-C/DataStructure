#include "SQList.h"
using namespace std;

void Union(SqList& La, SqList& Lb)
{
	int La_len = La.length;
	int Lb_len = Lb.length;
	for (int i = 1; i <= Lb_len; i++)
	{
		ElemType e = Lb.elem[i-1];
		if (SQList::LocateElem(La, e))SQList::ListInsert_Sq(La, ++La_len, e);
	}
}