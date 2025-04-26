#include<stdio.h>
#define maxsize 10
typedef struct {
	int data[maxsize];//静态数组
	int length;
}sqlist;
void initlist(sqlist &L)
{
	for (int i = 0; i < maxsize; i++)L.data[i] = 0;
	L.length = 0;
}
void listinsert(sqlist& L,int x,int k)//插入
{
	L.length++;
	for (int i = L.length; i >= x; i--)
		L.data[i] = L.data[i - 1];
	L.data[x] = k;
}
void listdelete(sqlist& L, int x)//删除
{
	L.length--;
	for (int i = x; i <= L.length; i++)
		L.data[i] = L.data[i + 1];
}
int main()
{
	sqlist L;
	initlist(L);
	for (int i = 0; i < 8; i++)
	{
		L.data[i] = i;
		L.length++;
	}
	listinsert(L, 3, 9);
	listdelete(L, 5);
	for (int i = 0; i < L.length; i++)printf("data[%d]=%d\n", i, L.data[i]);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#define initsize 10
typedef struct {
	int* data;//动态数组
	int maxsize;//最大容量
	int length;//当前长度
}sqlist;
void initlist(sqlist& L)
{
	L.data = (int*)malloc(sizeof(int) * initsize);
	L.length = 0;
	L.maxsize = initsize;
}
void increaselist(sqlist& L, int len)
{
	int* p = L.data;
	L.data = (int*)malloc(sizeof(int) * (initsize + len));
	for (int i = 0; i < initsize; i++)
	{
		L.data[i] = p[i];
	}
	for (int i = L.maxsize; i < L.maxsize + len; i++)
	{
		L.data[i] = i;
		L.length++;
	}
	L.maxsize += len;
	free(p);
	
}
int main()
{
	sqlist L;
	initlist(L);
	for (int i = 0; i < L.maxsize; i++)
	{
		L.data[i] = i;
		L.length++;
	}
	increaselist(L, 5);
	for (int i = 0; i < L.maxsize; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	return 0;
}