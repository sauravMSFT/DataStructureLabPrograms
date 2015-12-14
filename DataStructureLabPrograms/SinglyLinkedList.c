#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <conio.h>
//#include <process.h>
#include <malloc.h>

int count = 0;
struct NODE
{
	int info;
	struct NODE *ptr;
};
typedef struct NODE* node;

void CreateAndInsert(node*start, int pos)

{
	int i;
	node prev = NULL, cur = *start, temp;
	if (pos <= 0 || pos > count + 1)
	{
		printf("You entered an invalid position.");
		return;
	}
	temp = malloc(sizeof(struct NODE));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		return;
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &temp->info);
	temp->ptr = NULL;
	if (*start == NULL)
	{
		*start = temp;
	}
	else
	{
		for (i = 1; i < pos; ++i)
		{
			prev = cur;
			cur = cur->ptr;
		}
		temp->ptr = cur;
		if (pos == 1)*start = temp;
		else prev->ptr = temp;
	}
	++count;
	printf("\nNode with data %d was inserted.", temp->info);
}
void Delete(node *start, int position)
{
	node prev = NULL, cur = *start, temp;
	int data, i;
	if(*start == NULL)
	{
		printf("\nUnderflow. The list is empty.");
		return;
	}
	if ((position > count) || position <= 0)
	{
		printf("\nYou entered an invalid position. Try again.");
		return;
	}
	for (i = 1; i < position; ++i)
	{
		prev = cur;
		cur = cur->ptr;
	}
	temp = cur;
	data = temp->info;
	if (count == 1)
	{
		*start = NULL;
	}
	if (position == 1)
	{
		*start = temp->ptr;
	}
	else
	{
		prev->ptr = temp->ptr;
	}
	//free(cur);
	--count;
	printf("\nNode with data = %d was deleted from the list.", data);
}
void Display(node *start)
{
	node temp;
	temp = *start;
	if (count == 0)
	{
		printf("\nThe list is empty.");
		return;
	}
	//temp = temp->ptr;
	printf("\nThe list contains:\n");
	while (temp!= NULL)
	{
		printf("%d -->", temp->info);
		temp = temp->ptr;
	}
}
int main()
{
	int ch, pos, i;
	node start = NULL;
	while (1)
	{
		
		printf("\nSINGLY LINKED LIST");
		printf("\n1. INSERT \n2. DELETE \n3. DISPLAY\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		//system("cls");
		switch (ch)
		{
		case 1:
				printf("\n1. Insert at front");
				printf("\n2. Insert at rear");
				printf("\n3. Insert at specified position");
				printf("\nEnter your choice: ");
				scanf("%d", &i);
				switch (i)
				{
				case 1: CreateAndInsert(&start, 1);
					break;
				case 2: CreateAndInsert(&start, count + 1);
					break;
				case 3: printf("\nEnter the position where you want to insert the new node: ");
					scanf("%d", &pos);
					CreateAndInsert(&start, pos);
					break;
				default: printf("\n You chose an invalid option.");
				}
			break;
		case 2: printf("\n1. Delete from front");
				printf("\n2. Delete from rear");
				printf("\n3. Delete from specified position");
				printf("\nEnter your choice: ");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1: Delete(&start, 1);
					break;
				case 2: Delete(&start, count);
					break;
				case 3: printf("\nEnter the position from where you want to delete a node: ");
					scanf("%d", &pos);
					Delete(&start, pos);
					break;
				default: printf("\n You chose an invalid option.");
				}
			break;
		case 3: Display(&start);
			break;
		case 4: return;
		default: printf("\nInvalid choice. Try again.");
		}
	}
}
