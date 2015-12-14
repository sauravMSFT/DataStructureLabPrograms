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
int count = 0;
node Create()
{
	node temp = malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		exit(0);
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &temp->info);
	temp->ptr = NULL;
	return temp;
}
void InsertFront(node *first, node *last)
{
	node temp = Create();
	if (*first == NULL)
	{
		*first = *last = temp;
		return;
	}
	else
	{
		temp->ptr = *first;
		(*last)->ptr = temp;
		*first = temp;
	}
	printf("\nNode with data %d was inserted.", temp->info);
}
void InsertRear(node *first, node *last)
{
	node temp = Create();
	if (*first == NULL)
	{
		*first = *last = temp;
		return;
	}
	else
	{
		(*last)->ptr = temp;
		temp->ptr = *first;
		*last = temp;
	}
	printf("\nNode with data %d was inserted.", temp->info);
}
void DeleteFront(node *first, node *last)
{
	if (*first == NULL)
	{
		printf("\nStack underflow.");
		return;
	}
	printf("\nNode with data %d was deleted.", (*first)->info);
	if ((*first)->ptr == *first)
	{
		//free(*first);
		*first = *last = NULL;
		return;
	}
	(*last)->ptr = (*first)->ptr;
	//free(*first);
	*first = (*last)->ptr;
}
void DeleteRear(node *first, node *last)
{
	int data;
	node temp;
	if (*first == NULL)
	{
		printf("Stack underflow.");
		return;
	}
	data = (*last)->info;
	if ((*first)->ptr == *first)
	{
		//free(*first);
		*first = *last = NULL;
		return;
	}
	temp = *first;
	while (temp->ptr != *last)
	{
		temp = temp->ptr;
	}
	temp->ptr = *first;
	//free(last);
	*last = temp;
	printf("\nNode with data %d was deleted.", data);
}
void Display(node *first, node *last)
{
	node temp = *first;
	if (temp == NULL)
	{
		printf("\nThe stack is empty.");
		return;
	}
	printf("\nThe stack contains:\n");
	while (temp->ptr != *first)
	{
		printf("--> %d ", temp->info);
		temp = temp->ptr;
	}
	printf("--> %d", (*last)->info);
}
void main()
{
	node first = NULL, last = NULL;
	int i, ch;
	while (1)
	{
		printf("\nCIRCULAR LINKED LIST");
		printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &i);
		//system("cls");
		//clrscr();
		switch (i)
		{
		case 1:
			printf("\n1. Insert at front");
			printf("\n2. Insert at rear");
			printf("\nEnter your choice: ");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: InsertFront(&first, &last);
				break;
			case 2: InsertRear(&first, &last);
				break;
			default: printf("\n You chose an invalid option.");
			}

			break;
		case 2: printf("\n1. Delete from front");
			printf("\n2. Delete from rear");
			printf("\nEnter your choice: ");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: DeleteFront(&first, &last);
				break;
			case 2: DeleteRear(&first, &last);
				break;
			default: printf("\n You chose an invalid option.");
			}

			break;
		case 3: Display(&first, &last);
			break;
		case 4: return;
		default: printf("\nInvalid choice. Try again.");
		}
	}
}