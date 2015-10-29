#define _CRT_SECURE_NO_WARNINGS

#define SIZE 10

#include <stdio.h>
#include <conio.h>
void Insert(int *front, int*rear, int queue[])
{
	printf("\n INSERT");
	int num;
	if (*rear == SIZE - 1)
	{
		printf("\n Queue Overflow.");
		return;
	}
	printf("\n Enter the number to be inserted: ");
	scanf("%d", &num);
	queue[++(*rear)] = num;
	if (*front == -1)
	{
		//(*front)++;
		*front = 0;
	}
	printf("\n '%d' was inserted in the queue.\n", num);
	return;
}
void Delete(int *front, int*rear, int queue[])
{
	printf("\n DELETE");
	if (*front == -1)
	{
		printf("\n Queue Underflow.");
		return;
	}
	printf("\n '%d' was deleted from the queue.\n", queue[(*front)]);
	if (*front == *rear)
	{
		*front = *rear = -1;
	}
	else
	{
		(*front)++;
	}
	return;
}
void Display(int *front, int *rear, int queue[])
{
	printf("\n DISPLAY");
	int i;
	if (*front == -1)
	{
		printf("\n The queue is empty.");
		return;
	}
	printf("\n The queue contains the following:\n ");
	for (i = (*front); i <= (*rear); ++i)
	{
		printf("%d ", queue[i]);
	}
	printf(" <-- \n");
	return;
}
int main()
{
	int front, rear, queue[SIZE], num, choice;
	front = rear = -1;
	//clrscr();
	system("cls");
	while (1)
	{
		cheqeu
		printf("\n MAIN MENU");
		printf("\n 1. INSERT\n 2. DELETE\n 3. DISPLAY\n 4. EXIT");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		//clrscr();
		system("cls");
		switch (choice)
		{
		case 1:
			Insert(&front, &rear, queue);
			break;
		case 2:
			Delete(&front, &rear, queue);
			break;
		case 3:
			Display(&front, &rear, queue);
			break;
		case 4:
			return 0;
		default:printf("\n Invalid choice.\n");
		}
	}
}