#include<stdio.h>
#include<malloc.h>
struct node {
	char data;
	struct node* lchild;
	struct node* rchild;
};
struct node* createnode(char data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)return NULL;
	newnode->data = data;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	return newnode;
}
void insertnode(struct node* root, struct node* l, struct node* r)
{
	root->lchild = l;
	root->rchild = r;
}
void preorder(struct node*root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void midorder(struct node* root)
{
	if (root != NULL)
	{
		midorder(root->lchild); printf("%c", root->data);
		midorder(root->rchild);
	}
}void lastorder(struct node* root)
{
	if (root != NULL)
	{
		lastorder(root->lchild);
		lastorder(root->rchild); printf("%c", root->data);
	}
}
int main()
{
	struct node* A = createnode('A');
	struct node* B = createnode('B');
	struct node* C = createnode('C');
	insertnode(A, B, C);
	preorder(A);
	printf("\n");
	midorder(A);
	printf("\n");
	lastorder(A);
	printf("\n");
	return 0;
}