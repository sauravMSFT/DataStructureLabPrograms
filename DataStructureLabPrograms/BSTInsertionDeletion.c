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
void Inorder(node *);
void Preorder(node *);
void Postorder(node *);
bool Search(node *, node *, node *, int);
node FindMinimum(node *);
node Delete(node *, int);

void main()
{
	int choice, data;
	node root = NULL;
	while (1)
	{
		printf("\nBINARY SEARCH TREE\n");
		printf("\n1. Insert\n2. Delete\n3. Pre-Order Traversal\n4. In-Order Traversal\n5. Post-Order Traversal\n6. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: printf("\nEnter data to be inserted: ");
			scanf("%d", &data);
			Insert(&root, data);
			break;

		case 2: printf("\nEnter the node to be deleted: ");
			scanf("%d", &data);
			root = Delete(&root, data);
			break;

		case 3: printf("\n\nPre-Order Traversal\n");
			Preorder(&root);
			break;

		case 4: printf("\n\nIn-Order Traversal\n");
			Inorder(&root);
			break;

		case 5: printf("\n\nPost-Order Traversal\n");
			Postorder(&root);
			break;

		case 6: return;
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
		if (num <= ((*n)->info))
			Insert(&((*n)->lchild), num);
		else
			Insert(&((*n)->rchild), num);
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
bool Search(node *root, node *parent, node *toDelete, int key)
{
	node temp;
	*parent = NULL;
	temp = *root;
	while (temp != NULL)
	{
		if (temp->info == key)
		{
			*toDelete = temp;
			return true;
		}
		*parent = temp;
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
	node lchild, rchild, toDelete, parent, temp;
	bool found;
	if (*root == NULL)
	{
		printf("\nThe tree is empty.");
		return *root;
	}
	parent = toDelete = NULL;
	found = Search(root, &parent, &toDelete, key);
	if (found == false)
	{
		printf("\nThe node (%d) is not present in the tree.", key);
		return *root;
	}
	if (toDelete->lchild == NULL || toDelete->rchild == NULL)
	{
		lchild = toDelete->lchild;
		rchild = toDelete->rchild;
		if (parent == NULL)
		{
			if (toDelete->lchild != NULL)toDelete = toDelete->lchild;
			else toDelete = toDelete->rchild;
			return toDelete;
		}
		else
		{
			if (parent->lchild == toDelete)parent->lchild = lchild;
			else parent->rchild = rchild;
		}
	}
	else
	{
		temp = FindMinimum(&((*root)->rchild));
		(*root)->info = temp->info;
		(*root)->rchild = Delete(&((*root)->rchild), temp->info);
	}
	return *root;
}

