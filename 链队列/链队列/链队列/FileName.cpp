#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct list {
	int data;
	struct list* next;
}list;
typedef struct queue {
	list* front,*rear;
}queue;
queue* initqueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	list*head =(list*)malloc(sizeof(list));
	head->data = 0;
	head->next = NULL;
	q->front = head;
	q->rear = head;
	return q;
}
void bpqueue(queue* q)
{
	list* p = (list*)malloc(sizeof(list));
	p = q->front->next;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
void inqueue(queue* q, int x)
{
	cout << "入队";
	list* newnode = (list*)malloc(sizeof(list));
	newnode->data = x;
	newnode->next = NULL;
	q->rear->next = newnode;
	q->rear = newnode;
	bpqueue(q);
}
void outqueue(queue* q)
{
	cout << "出队";
	list* p = q->front->next;
	if (p == q->rear)
	{
		q->rear = q->front;
		free(p);
		return;
	}
	q->front->next= p->next;
	free(p);
	bpqueue(q);
}
int main()
{
	queue* q = initqueue();
	for(int i=1;i<=15;i++)
	inqueue(q, i);
	for(int i=1;i<=5;i++)
		outqueue(q);
	return 0;
}