#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 30

int top = -1, num, length, i = 0, j = 0;
char temp, symbol, infix[SIZE], postfix[SIZE], stack[SIZE];
void Push(char symbol)
{
	stack[++top] = symbol;
	return;
}
int Pop()
{
	return stack[top--]; 
}
int Precedence(char symbol)
{
	int p;
	switch (symbol)
	{
	case '^': p = 3;
		break;

	case '*': 
	case '/': p = 2;
		break;

	case '+': 
	case '-': p = 1;
		break;

	case '(':
	case ')': p = 0;
		break;

	case '#': p = -1;
		break;

	default:
		break;

	}
	return p;
}
void InfixToPostfix(char infix[], char postfix[])
{
	length = strlen(infix);
	Push('#');
	while (i < length)
	{
		symbol = infix[i];
		switch (symbol)
		{
		case '(': Push(symbol);
			break;

		case ')': temp = Pop();
			while (temp != '(')
			{
				postfix[j++] = temp;
				temp = Pop();
			}break;

		case '^': case '*':
		case '/':
		case '+':
		case '-': if (Precedence(stack[top]) >= Precedence(symbol))
				  {
					  temp = Pop();
			 		  postfix[j++] = temp;
			      }
				  Push(symbol);
			break;

		default: postfix[j++] = symbol;
		}
		i++;
	}
	while (top > 0)
	{
		postfix[j++] = Pop();
		return;
	}
}
void main()
{
	//clrscr();
	system("cls");
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	InfixToPostfix(infix, postfix);
	printf("Infix expression is = %s\n", infix);
	printf("Postfix expression is = %s\n", postfix);
}
