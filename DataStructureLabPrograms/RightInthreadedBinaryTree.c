#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
struct NODE
{
	int info;
	struct NODE *left, *right;
	int rt;
};	typedef struct NODE *node;

node Create(int);
void Insert(int, node *);
void InsertLeft(int, node *);
void InsertRight(int, node *);
void Inorder(node);
node InorderSuccessor(node);

void main()
{
	int choice, n, i, item;
	node head = Create(-999);
	head->right = head;
	head->rt = 0;
	while (1)
	{
		printf("\n1. Create\n2. Inorder Traversal\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the number of nodes to be created: ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("\nEnter the data for node %d: ", i + 1);
				scanf("%d", &item);
				Insert(item, &head);
			}
			break;
		case 2: 
			Inorder(head);
			break;
		case 3: return;
		default:printf("\nInvalid choice. Try again.");
		}
	}
}
node Create(int info)
{
	node newNode = malloc(sizeof(struct NODE));
	newNode->left = NULL;
	newNode->info = info;
	return newNode;
}
void Insert(int item, node *head)
{
	node cur, ptr;
	if ((*head)->left == NULL)
	{
		InsertLeft(item, head);
		return;
	}
	cur = (*head)->left;
	while (cur != (*head))
	{
		ptr = cur;
		if (item < cur->info)
		{
			if (cur->left != NULL)cur = cur->left;
			else break;
		}
		else if (item > cur->info)
		{
			if (cur->rt == 0)cur = cur->right;
			else break;
		}
	}
	if (item < cur->info)InsertLeft(item, &ptr);
	else
	{
		if (item > cur->info&&cur->rt == 1)InsertRight(item, &ptr);
	}
}
void InsertLeft(int item, node(*n))
{
	node newNode;
	newNode = Create(item);
	(*n)->left = newNode;
	newNode->right = (*n);
	newNode->rt = 1;
}
void InsertRight(int item, node(*n))
{
	node temp, newNode;
	newNode = Create(item);
	temp = (*n)->right;
	(*n)->right = newNode;
	(*n)->rt = 0;
	newNode->right = temp;
	newNode->rt = 1;
}
void Inorder(node head)
{
	node temp;
	if (head->left == NULL)
	{
		printf("\nThe tree is empty.");
		return;
	}
	temp = head;
	while (1)
	{
		temp = InorderSuccessor(temp);
		if (temp == head)	return;
		printf("%d\n", temp->info);
	}
}
node InorderSuccessor(node n)
{
	node temp;
	temp = n->right;
	if (n->rt == 1)
		return temp;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}