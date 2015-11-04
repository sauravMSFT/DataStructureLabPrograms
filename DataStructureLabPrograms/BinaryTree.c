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
	printf("Enter data for %s: ", a);
	scanf("%d", &((*n)->info));
}
int LeftOrRight(node root, char child[])
{
	int ch;
	printf("Create %s child of %d? Yes[1] or No[0]: ", child, root->info);
	do
	{
		scanf("%d", &ch);
		if ((ch != 0) && (ch != 1))
		{
			printf("\nInvalid choice. Try again: ");
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
	if (LeftOrRight(*root, "Right"))
	{
		(*root)->rchild = CreateNode();
		temp = (*root)->rchild;
		ReadData(&temp, "Right child");
		Create(&temp);
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

