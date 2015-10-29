#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void TowerOfHanoi(int a, char from, char aux, char to) 
{
	if (a == 1)
	{
		printf("\nMove disc  %d  from  %c  to  %c \n", a, from, to);
		return;
	}
	else
	{
		TowerOfHanoi(a - 1, from, to, aux);
		printf("\nMove disc  %d  from  %c  to  %c \n", a, from, to);
		TowerOfHanoi(a - 1, aux, from, to);
	}
}
int main()
{
	int n;
	printf("\n*****Tower of Hanoi*****\n");
	printf("\nEnter number of discs: ");
	scanf("%d", &n);
	TowerOfHanoi(n, 'S', 'A', 'D');
	return 0;
}