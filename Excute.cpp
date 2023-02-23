#include "String.h"
using namespace std;

int main()
{
	SString S;
	string s2 = "aabcdaaacaaabbaa";
	string s1 = "ababa";
	
	strcpy_s(S.ch, s1.c_str());
	
	S.length = s1.length();
	int next[MAXLEN + 1];
	
	for (int i = 0; i < MAXLEN+1; i++)
	{
		next[i] = 0;
	}

	for (int i = 0; i < S.length; i++)
	{
		cout << S.ch[i];
	}
	cout << endl;

	get_next(S, next);

	for (int i = 0; i < S.length; i++)
	{
		cout << next[i];
	}
	cout << endl;

	SString P;
	
	strcpy_s(P.ch, s2.c_str());
	P.length = s2.length();
	int tar = Index_KMP(P,S);

	for (int i = 0; i < P.length; i++)
	{
		cout << P.ch[i];
	}
	cout << endl;

	for (int i = 0; i < tar; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < S.length; i++)
	{
		cout << S.ch[i];
	}
	cout << endl;
	system("pause");
	return 0;
}