#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
struct NODE
{
	int info;
	struct NODE *lchild, *rchild;
};	typedef struct NODE *node;
node CreateNode(int num)
{
	node temp = malloc(sizeof(struct NODE));
	temp->lchild = temp->rchild = NULL;
	temp->info = num;
	return temp;
}
void Insert(node *n, int num)
{
	if (*n == NULL)
	{
		*n = CreateNode(num);
	}
	else
	{
		if (num < ((*n)->info))
			Insert(&((*n)->lchild), num);
		else
			Insert(&((*n)->rchild), num);
	}
}
void CreateTree(node *n, int size)
{
	int i, data;
	for (i = 0; i < size; ++i)
	{
		printf("\nEnter data for Node %d: ", i + 1);
		scanf("%d", &data);
		Insert(n, data);
	}
}
void DrawTree(node *n, int count)
{
	int i;
	if (*n != NULL)
	{
		DrawTree(&(*n)->rchild, count + 1);
		for (i = 0; i < count; ++i)
			printf("\t");
		printf("%d\n", (*n)->info);
		DrawTree(&(*n)->lchild, count + 1);
	}
}
void main()
{
	int size;
	node root = NULL;
	printf("\nBINARY SEARCH TREE AND TRAVERSAL\n");
	printf("\nEnter the size of the tree: ");
	scanf("%d", &size);
	CreateTree(&root, size);
	printf("\n\nDrawing Tree\n");
	DrawTree(&root, 0);
}