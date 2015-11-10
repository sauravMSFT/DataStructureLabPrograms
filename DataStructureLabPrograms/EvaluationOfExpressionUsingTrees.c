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

node CreateNode();
void Insert(node *, char);
void CreateTree(node *, char[]);
double Evaluate(node *);
void Reverse(char[]);

void main()
{
	char postfix[SIZE], temp[SIZE];
	node root = NULL;
	double ans;
	printf("\nEnter the postfix expression: ");
	scanf("%s", postfix);
	strcpy(temp, postfix);
	Reverse(temp);
	CreateTree(&root, temp);
	ans = Evaluate(&root);
	printf(" = %.4lf", ans);
}
void Reverse(char string[])
{
	int i, j; char t;
	for (i = 0, j = strlen(string) - 1; i <= strlen(string) / 2; ++i, --j)
	{
		t = string[i];
		string[i] = string[j];
		string[j] = t;
	}
}
node CreateNode()
{
	node temp = malloc(sizeof(struct NODE));
	temp->lchild = temp->rchild = NULL;
	return temp;
}
void Insert(node *n, char symbol)
{
	if (*n == NULL)
	{
		*n = CreateNode();
		(*n)->symbol = symbol;
		if (isalpha(symbol))
		{
			printf("\nEnter value for operand (%c): ", symbol);
			scanf("%lf", &((*n)->value));
		}
	}
	else
	{
		if ((*n)->rchild == NULL)
			Insert(&((*n)->rchild), symbol);
		else
			Insert(&((*n)->lchild), symbol);
	}
}
void CreateTree(node *root, char exp[])
{
	int i;
	for (i = 0; i < strlen(exp); ++i)
	{
		Insert(root, exp[i]);
	}
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