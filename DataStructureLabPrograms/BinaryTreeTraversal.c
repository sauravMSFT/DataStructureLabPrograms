#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
struct NODE
{
	int info;
	struct NODE *lchild, *rchild;
};	typedef struct NODE *node;
node CreateNode()
{
	node temp = malloc(sizeof(struct NODE));
	temp->lchild = temp->rchild = NULL;
	return temp;
}
void ReadData(node *n, char a[])
{
	if ((*n) == NULL)return;
	printf("\nEnter data for %s: ", a);
	scanf("%d", &((*n)->info));
}
void Insert(node *n, int num)
{
	if (*n == NULL)
	{
		*n = CreateNode();
		(*n)->info = num;
	}
	else
	{
		if (num < ((*n)->info))
		{
			Insert(&((*n)->lchild), num);
		}
		else
		{
			Insert(&((*n)->rchild), num);
		}
	}
}
void CreateTree(node *root, int size)
{
	int i, data;
	for (i = 0; i < size; ++i)
	{
		printf("\nEnter data for Node %d: ", i + 1);
		scanf("%d", &data);
		Insert(root, data);
	}
}
void Inorder(node *n)
{
	if ((*n) != NULL)
	{
		Inorder(&(*n)->lchild);
		printf("%d =>", (*n)->info);
		Inorder(&(*n)->rchild);
	}
}
void Preorder(node *n)
{
	if ((*n) != NULL)
	{
		printf("%d =>", (*n)->info);
		Preorder(&(*n)->lchild);
		Preorder(&(*n)->rchild);
	}
}
void Postorder(node *n)
{
	if ((*n) != NULL)
	{
		Postorder(&(*n)->lchild);
		Postorder(&(*n)->rchild);
		printf("%d =>", (*n)->info);
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
	printf("\n\nIn-Order Traversal\n");
	Inorder(&root);
	printf("\n\nPre-Order Traversal\n");
	Preorder(&root);
	printf("\n\nPost-Order Traversal\n");
	Postorder(&root);
}

