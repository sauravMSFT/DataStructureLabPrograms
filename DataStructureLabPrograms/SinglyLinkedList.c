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
typedef struct NODE node;

node * GetNode()
{
	node *temp;
	int x;
	temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		exit(0);
		//return null;
	}
	++count;
	printf("\nEnter the value to be stored: ");
	scanf("%d", &x);
	temp->info = x;
	temp->ptr = NULL;
	return temp;
}
void Insert(node *start, node *temp, int position)
{
	int i;
	node *prev, *cur, *x;
	prev = NULL;
	cur = start;
	if ((position > count + 1) || position <= 0)
	{
		printf("You entered an invalid position. Try again.");
		return;
	}
	if (count == 1)
	{
		start = temp;
		return;
	}
	if (position == 1)
	{
		x = start;
		start = temp;
		temp->ptr = x;
		return;
	}
	for (i = 0; i < position; ++i)
	{
		prev->ptr = cur;
		cur = cur->ptr;
	}

	prev->ptr = temp;
	temp->ptr = cur;
}
void Delete(node *start, int position)
{
	int i;
	node *prev, *cur;
	prev = NULL;
	cur = start;
	if ((position > count) || position <= 0)
	{
		printf("\nYou entered an invalid position. Try again.");
		return;
	}
	for (i = 0; i < position; ++i)
	{
		prev->ptr = cur;
		cur = cur->ptr;
	}

	prev->ptr = NULL;
	free(cur);
	--count;
}
void Display(node *start)
{
	node *temp;
	temp = start;
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
	int ch, pos;
	node *start, *temp;
	start = NULL;
	while (1)
	{
		
		printf("\nSINGLY LINKED LIST");
		printf("\n1. INSERT FRONT\n2. INSERT AT SPECIFIED LOCATION");
		printf("\n3. DELETE FRONT\n4. DELETE REAR");
		printf("\n5. DISPLAY\n6. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		system("cls");
		switch (ch)
		{
		case 1: 
			temp = GetNode();
			Insert(start, temp, 1);
			break;
		case 2:
			temp = GetNode();
			printf("\nEnter the position to insert the node: ");
			scanf("%d", &pos);
			Insert(start, temp, pos);
			break;
		case 3:
			Delete(start, 1);
			break;
		case 4:
			Delete(start, count);
			break;
		case 5:
			Display(start);
			break;
		case 6:
			return 0;
		default: printf("\nYou entered an invalid choice. Try again.");
		}
	}
}
