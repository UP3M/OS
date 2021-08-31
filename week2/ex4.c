// C program to swap two variables using a function
#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int x, y;
	printf("Enter First integer: ");
	scanf("%d", &x);
	printf("\nEnter Second integer: ");
	scanf("%d", &y);
	swap(&x, &y);
	printf("\nAfter Swapping: First = %d, Second = %d", x, y);
	return 0;
}
