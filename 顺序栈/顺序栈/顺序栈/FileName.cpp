#include<stdio.h>
#include<stdlib.h>
#define Maxnum 10
typedef struct stack {
	int data[Maxnum];
	int top = -1;
}stack;
void push(stack& S, int x)//��ջ
{
	S.top += 1;
	if (S.top >= Maxnum)
	{
		printf("false");
		return;
	}
	S.data[S.top] = x;
}
void pop(stack& S)//��ջ
{
	printf("%d��ջ\n", S.data[S.top]);
	S.top -= 1;
}
void bl(stack& S)//����
{
	while (S.top >= 0)
	{
		printf("%d ", S.data[S.top]);
		S.top--;
	}
}
int main()
{
	stack S;
	for (int i = 0; i <= 5; i++)
		push(S, i);
	pop(S);
	bl(S);
	return 0;
}