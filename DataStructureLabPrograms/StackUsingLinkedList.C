#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>
struct NODE
{
	int info;
	struct NODE *ptr;
};
typedef struct NODE * node;
void CreateAndInsert(node *start)
{
	int x;
	node temp = (node )malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		return;
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &x);
	temp->info = x;
	temp->ptr = NULL;
	if (*start == NULL)
	{
		*start = temp;
	}
	else
	{
		temp->ptr = *start;
		*start = temp;
	}
	printf("\nNode with data %d was inserted.", temp->info);
}
void Delete(node *start)
{
	node temp;
	int data;
	if (*start == NULL)
	{
		printf("Stack underflow.");
		return;
	}
	temp = *start;
	(*start) = (*start)->ptr;
	data = temp->info;
	free(temp);
	printf("\nNode with data = %d was deleted from the stack.", data);
}
void Display(node *start)
{
	node temp = *start;
	if (temp == NULL)
	{
		printf("\nThe stack is empty.");
		return;
	}
	printf("\nThe stack contains:\n");
	while (temp != NULL)
	{
		printf("--> %d ", temp->info);
		temp = temp->ptr;
	}
}
void main()
{
	node start = NULL;
	int ch;
	while (1)
	{
		printf("\nSTACK IMPLEMENTATION");
		printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		system("cls");
		//clrscr();
		switch (ch)
		{
		case 1:
			CreateAndInsert(&start);
			break;
		case 2: Delete(&start);
			break;
		case 3: Display(&start);
			break;
		case 4: return;
		default: printf("\nInvalid choice. Try again.");
		}
	}
}