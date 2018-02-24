/* 
 * C program to simulate the tower of hanoi.
 * Takes as input the number of disks, and generates
 * the sequence of steps to move the disks from 'S' to 'D'.
 *
 */

#include <stdio.h>

void towerOfHanoi(int a, char from, char aux, char to) {
	if (a == 1) {
		printf("Move disc %d from %c to %c\n", a, from, to);
		return;
	}

	towerOfHanoi(a - 1, from, to, aux);
	printf("Move disc %d from %c to %c\n", a, from, to);
	towerOfHanoi(a - 1, aux, from, to);
}

int main() {
	int n;

	printf("Tower of Hanoi\n");
	printf("Enter number of discs: ");
	scanf("%d", &n);
	towerOfHanoi(n, 'S', 'A', 'D');
}
