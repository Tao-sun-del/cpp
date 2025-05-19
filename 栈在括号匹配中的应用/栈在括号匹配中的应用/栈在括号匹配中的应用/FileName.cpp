#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct stack{
	char data[100];
	int top;
}stack;
void init(stack& s)
{
	s.top = -1;
}
void workstack(stack& s,char c)
{
	if (c == '(' || c == '[' || c == '{')
	{
		s.top++;
		s.data[s.top] = c;
	}
	if (c == ')' || c == ']' || c == '}')
	{
		if (s.top < 0)
		{
			cout <<c<< "Åä¶Ô´íÎó" << endl;
			return;
		}
		if ((c ==')'&& s.data[s.top]=='(')|| (c == ']' && s.data[s.top] == '[')|| (c == '}' && s.data[s.top] == '{'))
		{
		    cout<<s.data[s.top]<<"Óë"<<c<<"Åä¶Ô"<<endl;
			s.top--;
		}
		else
			cout << s.data[s.top] << "Óë" << c << "Åä¶Ô´íÎó" << endl;
	}
}
void check(stack& s)
{
	if (s.top != -1)cout << "´íÎó";
}
int main()
{
	stack s;
	init(s);
	string c; cin >> c;
	for(int i=0;i<c.size();i++)
	{
		workstack(s, c[i]);
	}
	check(s);
	return 0;
}