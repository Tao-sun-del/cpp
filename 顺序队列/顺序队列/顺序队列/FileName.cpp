#include<stdio.h>
#define Maxnum 10
typedef struct queue {
	int data[Maxnum];
	int front=0, rear=0;
}queue;//�Ƚ��ȳ�
void inqueue(queue &S,int x)//���
{
	if ((S.rear + 1) % Maxnum == S.front)
	{
		printf("����\n");
		return;//����
	}
	S.data[S.rear] = x;
	S.rear = (S.rear + 1) % Maxnum;//ѭ��
	printf("%d���\n", x);
}
void outqueue(queue& S)//����
{
	if (S.front == S.rear)
	{
		printf("�ѿ�\n");
		return;//�п�
	}
	printf("%d����\n", S.data[S.front]);
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