//单链表
#include<stdio.h>
#include<stdlib.h>
typedef struct list {
	int data;
	struct list* next;
}list;
list* initlist() {
	list* head = (list*)malloc(sizeof(list));
	head->next = NULL;
	head->data = 0;
	return head;
}//链表初始化（头节点）
void createnode(list* L,int x)//尾插结点
{
	list* node = (list*)malloc(sizeof(list));
	node->data = x;
	node->next = NULL;
	list* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = node;
}
void headinsert(list* L, int x)//头插结点
{
	list* head = L;
	list* node = (list*)malloc(sizeof(list));
	node->data = x;
	node->next = NULL;
	node->next = head->next;
	head->next = node;
}
void listdelete(list* L, int x)//删除结点
{
	list* pre = NULL;
	list* p = L;
	pre = p;
	p = p->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			pre->next = p->next;
			p = pre;
		}
		pre = p;
		p = p->next;
	}
}
//void findinsert(list*L,int x)//查找
void freelist(list*L)//释放内存
{
	list* p = L;
	while (p != NULL)
	{
		list* c = p;
		p = p->next;
		free(c);
	}
}
void printlist(list* L)//打印
{
	list* p = L;
	p = p->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
int main()
{
	list*L=initlist();
	for(int i=1;i<=10;i++)
	createnode(L,i);
	headinsert(L, 6);
	listdelete(L, 6);
	printlist(L);
	freelist(L);
	return 0;
}
//不带头结点
list* initlist()
{
	list* head = NULL;
	return head;
}
list* tailinsert(list* L, int x)
{
	list* newcode = (list*)malloc(sizeof(list));
	newcode->data = x;
	newcode->next = NULL;
	list* p = L;
	if (p = NULL)return newcode;
}
int main()
{
	list* L = initlist();
	L = tailinsert(L,3);
}