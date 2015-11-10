#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct NODE
{
	int info;
	struct NODE *lchild, *rchild;
	int rt;
};	typedef struct NODE *node;

