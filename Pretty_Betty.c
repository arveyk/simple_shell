#include <stdio.h>

/**
 * main - prints the elements of an array
 *
 * Return: Always zero
 */
int  main(void)
{

	int arr[7], r;


	for (r = 0; r <= 7; r++)
	{
		*(arr + 1) = r;
		printf("%i, %dn\n", *(arr + 1), arr[r]);
	}

	return (0);
}
