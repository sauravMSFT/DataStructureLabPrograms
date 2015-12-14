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
	node temp = *start;
	node newNode = (node)malloc(sizeof(node));
	if (newNode == NULL)
	{
		printf("\nOut of memory.");
		return;
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &newNode->info);
	newNode->ptr = NULL;
	if (*start == NULL)
	{
		*start = newNode;
	}
	else
	{
		while (temp->ptr != NULL)
		{
			temp = temp->ptr;
		}
		temp->ptr = newNode;
	}
	printf("\nNode with data %d was inserted.", newNode->info);
}
void Delete(node *start)
{
	node temp;
	int data;
	if (*start == NULL)
	{
		printf("Queue underflow.");
		return;
	}
	temp = *start;
	(*start) = (*start)->ptr;
	data = temp->info;
	//free(temp);
	printf("\nNode with data = %d was deleted from the queue.", data);
}
void Display(node *start)
{
	node temp = *start;
	if (temp == NULL)
	{
		printf("\nThe queue is empty.");
		return;
	}
	printf("\nThe queue contains:\n");
	while (temp != NULL)
	{
		printf(" %d <--", temp->info);
		temp = temp->ptr;
	}
}
void main()
{
	node start = NULL;
	int ch;
	while (1)
	{
		printf("\nQUEUE IMPLEMENTATION");
		printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		//system("cls");
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