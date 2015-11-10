#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#define SIZE 40
struct NODE
{
	double value;
	char symbol;
	struct NODE *lchild, *rchild;
};	typedef struct NODE *node;
void Push(node **stack, int *top, node *temp)
{
	(*stack)[++(*top)] = *temp;
}
node Pop(node **stack, int *top)
{
	return(*stack)[(*top)--];
}
node CreateNode()
{
	node temp = malloc(sizeof(struct NODE));
	temp->lchild = temp->rchild = NULL;
	return temp;
}
void ReadData(node *n)
{
	printf("\nEnter value for operand (%c): ", (*n)->symbol);
	scanf("%lf", &((*n)->value));
}
int IsOperator(char ch)
{
	switch (ch)
	{
	case '-':
	case '+':
	case '/':
	case '*':
	case '^': return 1;
	default: return 0;
	}
}
node CreateTree(char exp[])
{
	node *stack = malloc(sizeof(struct NODE)*strlen(exp)), temp;
	int i, top = -1;
	for (i = 0; i < strlen(exp); ++i)
	{
		temp = CreateNode();
		temp->symbol = exp[i];
		if (IsOperator(exp[i]) == 0)
		{
			ReadData(&temp);
		}
		else
		{
			(temp)->rchild = Pop(&stack, &top);
			(temp)->lchild = Pop(&stack, &top);
		}
		Push(&stack, &top, &temp);
	}
	temp = Pop(&stack, &top);
	free(stack);
	return temp;
}
double Evaluate(node *n)
{
	if ((*n)->rchild == NULL)
		//Any node will not have a single child
	{
		return ((*n)->value);
	}
	switch ((*n)->symbol)
	{
	case '*': return (Evaluate(&((*n)->lchild)) * Evaluate(&((*n)->rchild)));
	case '/': return (Evaluate(&((*n)->lchild)) / Evaluate(&((*n)->rchild)));
	case '+': return (Evaluate(&((*n)->lchild)) + Evaluate(&((*n)->rchild)));
	case '-': return (Evaluate(&((*n)->lchild)) - Evaluate(&((*n)->rchild)));
	case '^': return pow(Evaluate(&((*n)->lchild)), Evaluate(&((*n)->rchild)));
	default:  return 0;
	}
}
void main()
{
	char postfix[SIZE];
	node root = NULL;
	double ans;
	printf("\nEnter the postfix expression: ");
	scanf("%s", postfix);
	root = CreateTree(postfix);
	ans = Evaluate(&root);
	printf("\nResult = %.2lf\n", ans);
}

