#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

void Append(char string[], char value)
{
	int length = strlen(string);
	string[length] = value;
}
void Push(char stack[], int *top, char symbol)
{
	stack[++(*top)] = symbol;
}
char Pop(char stack[], int *top)
{
	return stack[(*top)--]; 
}
char Peep(char stack[], int top)
{
	return stack[top];
}
int StackEmpty(int top)
{
	if (top == -1)return 1;
	return 0;
}
int IsOperator(char ch)
{
	switch (ch)
	{
	case '/':
	case '*':
	case '+':
	case '-': return 1;
	default: return 0;
	}
}
int Precedence(char symbol)
{
	switch (symbol)
	{
	case '*':
	case '/': return 2;
	case '+': 
	case '-': return 1;
	default: return 0;
	}
}
void InfixToPostfix(char infix[], char postfix[])
{
	#define SIZE 30
	int top = -1, i;
	char symbol, temp, stack[SIZE];
	strcpy(postfix, "");
	for (i = 0; i < (int)strlen(infix); ++i)
	{
		symbol = infix[i];
		if (symbol == '(')
		{
			Push(stack, &top, symbol);
		}
		else if (symbol == ')')
		{
			temp = Pop(stack, &top);
			while (temp != '(')
			{
				Append(postfix, temp);
				temp = Pop(stack, &top);
			}
		}
		else if (IsOperator(symbol))
		{
			if (Precedence(Peep(stack, top)) > Precedence(symbol))
			{
				temp = Pop(stack, &top);
				Append(postfix, temp);
			}
			Push(stack, &top, symbol);
		}
		else
		{
			Append(postfix, symbol);
		}
	}
	while (!StackEmpty(top))
	{
		Append(postfix, Pop(stack, &top));
	}
}
void main()
{
	#define SIZE 30
	char infix[SIZE] = { 0 }, postfix[SIZE] = { 0 };
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	InfixToPostfix(infix, postfix);
	printf("Infix expression is = %s\n", infix);
	printf("Postfix expression is = %s\n", postfix);
}
