#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct NODE
{
	int info;
	struct NODE *rlink, *llink;
};
typedef struct NODE * node;
int count = 0;
node Create()
{
	node temp = malloc(sizeof(struct NODE));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		exit(0);
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &temp->info);
	temp->rlink = temp;
	temp->llink = temp;
	return temp;
}
void InsertFront(node *first, node *last, node *temp)
{
	if (*first == NULL)
	{
		*first = *last = *temp;
	}
	else
	{
		(*temp)->rlink = *first;
		(*temp)->llink = *last;
		(*last)->rlink = *temp;
		(*first)->llink = *temp;
		*first = *temp;
	}
}
void InsertRear(node *first, node *last, node *temp)
{
	if (*first == NULL)
	{
		*first = *last = *temp;
	}
	else
	{
		(*last)->rlink = *temp;
		(*temp)->rlink = *first;
		(*temp)->llink = *last;
		(*first)->llink = *temp;
		*last = *temp;
	}
}
void InsertPosition(node *first, node *last, int pos)
{
	node prev = NULL, cur = *first, temp; 
	int i;
	if (pos <= 0 || pos > count + 1)
	{
		printf("\nYou entered an invalid position.");
		return;
	}
	temp = Create();
	if (pos == 1) InsertFront(first, last, &temp);
	else if (pos == count + 1) InsertRear(first, last, &temp);
	else
	{
		for (i = 1; i < pos; ++i)
		{
			prev = cur;
			cur = cur->rlink;
		}
		temp->rlink = cur;
		temp->llink = prev;
		prev->rlink = temp;
		cur->llink = temp;
	}
	++count;
}
void DeleteFront(node *first, node *last)
{
	if (*first == NULL)
	{
		printf("\nList underflow.");
		return;
	}
	if ((*first)->rlink == *first)
	{
		free(*first);
		*first = *last = NULL;
	}
	else
	{
		(*last)->rlink = (*first)->rlink;
		free(*first);
		(*first)->rlink->llink = *last;
		*first = (*first)->rlink;
	}
}
void DeleteRear(node *first, node *last)
{
	int data;
	if (*first == NULL)
	{
		printf("\nList underflow.");
		return;
	}
	data = (*last)->info;
	if ((*first)->rlink == *first)
	{
		free(*first);
		*first = *last = NULL;
	}
	else
	{
		(*last)->llink->rlink = *first;
		(*first)->llink = (*last)->llink;
		*last = (*last)->llink;
		printf("\nNode with data %d was deleted.", data);
	}
}
void DeletePosition(node *first, node *last, int pos)
{
	node prev = NULL, cur = *first, temp;
	int i;
	if (pos <= 0 || pos > count)
	{
		printf("\nYou entered an invalid position.");
		return;
	}
	if (pos == 1) DeleteFront(first, last);
	else if (pos == count) DeleteRear(first, last);
	else
	{
		for (i = 1; i < pos; ++i)
		{
			prev = cur;
			cur = cur->rlink;
		}
		temp = cur;
		prev->rlink = cur->rlink;
		cur->rlink->llink = prev;
		free(temp);
	}
	--count;
}
void Display(node *first, node *last)
{
	node temp = *first;
	if (temp == NULL)
	{
		printf("\nThe list is empty.");
		return;
	}
	printf("\nThe list contains:\n");
	while (temp->rlink != *first)
	{
		printf("--> %d ", temp->info);
		temp = temp->rlink;
	}
	printf("--> %d", (*last)->info);
}
void main()
{
	node first = NULL, last = NULL;
	int i, pos;
	while (1)
	{
		printf("\nDOUBLY CIRCULAR LINKED LIST");
		printf("\n1. Insert - Front\n2. Insert - Rear\n3. Insert - Position\n4. Delete - Front");
		printf("\n5. Delete - Reart\n6. Delete - position\n7. Display\n8. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &i);
		//system("cls");
		//clrscr();
		switch (i)
		{
		case 1: InsertPosition(&first, &last, 1);
				break;
		case 2: InsertPosition(&first, &last, count + 1);
				break;
		case 3: printf("\nEnter the position where you want to insert the new node: ");
				scanf("%d", &pos);
				InsertPosition(&first, &last, pos);
				break;
		case 4: DeletePosition(&first, &last, 1);
				break;
		case 5: DeletePosition(&first, &last, count);
				break;
		case 6: printf("\nEnter the position from where you want to delete the a node: ");
				scanf("%d", &pos);
				DeletePosition(&first, &last, pos);
				break;
		case 7: Display(&first, &last);
				break;
		case 8: return;
		default: printf("\nInvalid choice. Try again.");
		}
	}
}