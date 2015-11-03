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
int LeftOrRight(node root, char child[])
{
	int ch;
	printf("\nCreate %s child of %d? Yes[1] or No[0]:", child, root->info);
	do
	{
		scanf("%d", &ch);
		if ((ch != 0) && (ch != 1))
		{
			printf("Invalid choice. Try again.\n");
		}
	} while ((ch != 0) && (ch != 1));
	return ch;
}
void Create(node *root)
{
	node temp;
	if (LeftOrRight(*root, "Left"))
	{
		(*root)->lchild = CreateNode();
		temp = (*root)->lchild;
		ReadData(&temp, "Left child");
		Create(&temp);
	}
	else
	{
		(*root)->lchild = NULL;
	}
	if (LeftOrRight(*root, "Right"))
	{
		(*root)->rchild = CreateNode();
		temp = (*root)->rchild;
		ReadData(&temp, "Right child");
		Create(&temp);
	}
	else
	{
		(*root)->rchild = NULL;
	}
}
void Inorder(node *root)
{
	if ((*root) != NULL)
	{
		Inorder(&(*root)->lchild);
		printf("%d =>", (*root)->info);
		Inorder(&(*root)->rchild);
	}
}
void main()
{
	system("cls");
	printf("\nBINARY TREE\n");
	node root = CreateNode();
	ReadData(&root, "Root");
	Create(&root);
	printf("\nInorder Traversal\n");
	Inorder(&root);
}

