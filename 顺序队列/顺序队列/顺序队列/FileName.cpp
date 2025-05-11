#include<stdio.h>
#define Maxnum 10
typedef struct queue {
	int data[Maxnum];
	int front=0, rear=0;
}queue;//先进先出
void inqueue(queue &S,int x)//入队
{
	if ((S.rear + 1) % Maxnum == S.front)
	{
		printf("已满\n");
		return;//判满
	}
	S.data[S.rear] = x;
	S.rear = (S.rear + 1) % Maxnum;//循环
	printf("%d入队\n", x);
}
void outqueue(queue& S)//出队
{
	if (S.front == S.rear)
	{
		printf("已空\n");
		return;//判空
	}
	printf("%d出队\n", S.data[S.front]);
	S.front = (S.front + 1) % Maxnum;
}
int main()
{
	queue S;
	for(int i=1;i<=10;i++)
	inqueue(S, i);
	for (int i = 1; i <= 10; i++)
		outqueue(S);
	return 0;
}