#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
enum Bool
{
	false,
	true
};	typedef enum Bool bool;
struct NODE
{
	int info;
	struct NODE *lchild, *rchild;
};	typedef struct NODE *node;

node CreateNode();
void ReadData(node *, char[]);
void Insert(node *, int);
void Inorder(node);
bool Search(node *, int);
node FindMinimum(node *);
node Delete(node *, int);

void main()
{
	int choice, info;
	node root = NULL;
	bool found;
	while (1)
	{
		//printf("\nBINARY SEARCH TREE\n");
		printf("\n1. Insert\n2. Delete\n3. In-Order Traversal\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: printf("\nEnter info to be inserted: ");
			scanf("%d", &info);
			Insert(&root, info);
			break;
		case 2: printf("\nEnter the node to be deleted: ");
			scanf("%d", &info);
			if (root == NULL)
			{
				printf("\nThe tree is empty.");
				break;
			}
			found = Search(&root, info);
			if (found == false)
			{
				printf("\nThe node (%d) is not present in the tree.", info);
				break;
			}
			root = Delete(&root, info);
			break;
		case 3: if (root == NULL)
				{
					printf("\nThe tree is empty.");
					break;
				}
			else printf("\n\nIn-Order Traversal\n");
			Inorder(root);
			break;
		case 4: return;
		default:printf("\nInvalid choice. Try again.");
		}
	}
}
node CreateNode()
{
	node temp = malloc(sizeof(struct NODE));
	temp->lchild = temp->rchild = NULL;
	return temp;
}
void ReadData(node *n, char a[])
{
	if ((*n) == NULL)return;
	printf("\nEnter info for %s: ", a);
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
		if (num <= ((*n)->info))
			Insert(&((*n)->lchild), num);
		else
			Insert(&((*n)->rchild), num);
	}
}
void Inorder(node n)
{
	if (n != NULL)
	{
		Inorder(n->lchild);
		printf("%d =>", n->info);
		Inorder(n->rchild);
	}
}
bool Search(node *root, int key)
{
	node temp;
	temp = *root;
	while (temp != NULL)
	{
		if (temp->info == key)
		{
			return true;
		}
		if (key <= (temp->info))
		{
			temp = temp->lchild;
		}
		else
		{
			temp = temp->rchild;
		}
	}
	return false;
}
node FindMinimum(node *root)
{
	node n = *root;
	while ((n)->lchild != NULL)n = n->lchild;
	return n;
}
node Delete(node *root, int key)
{
	node temp;

	if (*root == NULL)
	{
		return *root;
	}
	else if (key < (*root)->info)
	{
		(*root)->lchild = Delete(&((*root)->lchild), key);
	}
	else if (key >(*root)->info)
	{
		(*root)->rchild = Delete(&((*root)->rchild), key);
	}
	else
	{
		if ((*root)->lchild == NULL && (*root)->rchild == NULL)
		{
			free(*root);
			return NULL;
		}
		else if ((*root)->lchild == NULL)
		{
			temp = *root;
			(*root) = (*root)->rchild;
			free(temp);
		}
		else if ((*root)->rchild == NULL)
		{
			temp = *root;
			(*root) = (*root)->lchild;
			free(temp);
		}
		else
		{
			temp = FindMinimum(&(*root)->rchild);
			(*root)->info = temp->info;
			(*root)->rchild = Delete(&(*root)->rchild, temp->info);
		}
	}
	return *root;
}

