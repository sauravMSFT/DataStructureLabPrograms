#define _CRT_SECURE_NO_WARNINGS

#define SIZE 10
#include <stdio.h>
#include <conio.h>
void Push(int num, int *top, int st[])
{
	if (*top == SIZE - 1)
	{
		printf("\n Stack Overflow.\n");
		return;
	}
	st[++(*top)] = num;
	printf(" '%d' was inserted in the stack.", num);
	return;
}
void Pop(int *top, int st[])
{
	if (*top == -1)
	{
		printf("\n Stack Underflow.\n");
		return;
	}
	printf("\n '%d' was deleted from the stack.\n", st[*top]);
	//st[(*top)--];
	(*top)--;
	return;
}
void Display(int *top, int st[])
{
	int i = *top;
	if (*top == -1)
	{
		printf("\n The stack is empty.\n");
		return;
	}
	printf("\n The stack contains the following:\n -->");
	for (; i >=0; --i)
	{
		printf("%d ", st[i]);
	}
	return;
}
int main()
{
	int top, stack[SIZE], num, choice;
	top = -1;
	//clrscr();
	//system("cls");
	while (1)
	{
		printf("\n MAIN MENU\n STACK IMPLEMENTATION");
		printf("\n 1. PUSH\n 2. POP\n 3. DISPLAY\n 4. EXIT");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		//clrscr();
		//system("cls");
		switch (choice)
		{
		case 1:
			printf("\n PUSH\n Enter the number to be inserted: ");
			scanf("%d", &num);
			Push(num, &top, stack);
			break;
		case 2: 
			printf("\n POP");
			Pop(&top, stack);
			break;
		case 3:
			printf("\n DISPLAY");
			Display(&top, stack);
			break;
		case 4: 
			return 0;
		default:printf("\n Invalid choice.\n");
		}
	}
}