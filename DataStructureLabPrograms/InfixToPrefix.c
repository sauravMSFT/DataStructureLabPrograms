#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30

#include <stdio.h>
#include <conio.h>
#include <string.h>

char prefix[SIZE], infix[SIZE], stack[SIZE], symbol, temp;
int top = -1, length, i = 0, j = 0, k = 0;

void Push(char symbol) { stack[++top] = symbol; }
char Pop(){	return stack[top--];}
int ISP(char symbol)
{
	switch (symbol)
	{
	case '^': return 6;
	case '*':
	case '/': return 3;
	case '+': 
	case '-': return 1;
	case ')': return 0;
	case '#': return -1;
	}
}
int ICP(char symbol)
{
	switch (symbol)
	{
	case '^': return 5;
	case '*':
	case '/': return 4;
	case '+':
	case '-': return 2;
	case ')': return 0;
	case '(': return 9;
	}
}
void InfixToPrefix()
{
	Push('#');
	length = strlen(infix) - 1;
	j = length;
	while (infix[i] != '\0')
	{
		if (infix[i] == '(' || infix[i] == ')')
			j--;
		i++;
	}
	while (length >= k)
	{
		symbol = infix[length];
		switch (symbol)
		{
		case ')':
			Push(symbol);
			break;
		case '(':
			temp = Pop();
			while (temp != ')')
			{
				prefix[j--] = temp;
				temp = Pop();
			}
			break;
		case '^':
		case '*': 
		case '+':
		case '-':
			while (ISP(stack[top]) >= ICP(symbol))
			{
				temp = Pop();
				prefix[j--] = temp;
			}
			Push(symbol);
			break;
		default: prefix[j--] = symbol;
			break;
		}
		length--;
	}
	while (top > 0)
	{
		temp = Pop();
		prefix[j--] = temp;
	}
}
void main()
{
	system("cls");
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	InfixToPrefix();
	printf("\nInfix expression: %s\n", infix);
	printf("\nPrefix expression: %s\n", prefix);
}