#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void InsertionSort(int a[], int size)
{
	int i, j, temp;
	for (i = 1; i < size; ++i)
	{
		for (j = i; j > 0; --j)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
			{
				break;
			}
		}
	}
}
void Display(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf(" %d ", a[i]);
	}
}
int main()
{
 	int size, i, *a;
	//int size, i;
	//int a[20];
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);
	a = malloc(sizeof(int)*size);
	printf("\nEnter %d numbers: ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n\nYou have entered the following:");
	Display(a, size);
	printf("\n\nThe sorted array is:");
	InsertionSort(a, size);
	Display(a, size);

	return 0;
}