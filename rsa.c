#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/**
 * divisibility - Find divisors and factors of a given number.
 * @integer: The input long long integer to be analyzed.
 * @size: A pointer to an integer to store the size of the result array.
 *
 * This function calculates the divisors and factors of the input integer
 * 'integer' up to its square root and stores them in a dynamically allocated
 * integer array. The size of the result array is stored in the 'size'
 * variable.
 *
 * Return: A pointer to the dynamically allocated integer array containing
 *         divisors and factors of 'inte', or NULL if no divisors were found.
*/

int *divisibility(long integer, int *size)
{
	int sqrt_integer = (int)sqrt(integer);
	int *new_list = malloc(2 * sqrt_integer * sizeof(int));
	int count = 0;
	int num_div;

	for (num_div = 2; num_div <= sqrt_integer; num_div++)
	{
		if (integer % num_div == 0)
		{
			new_list[count++] = num_div;
			if (num_div != integer / num_div && num_div != integer)
				new_list[count++] = integer / num_div;
		}
	}
	*size = count;
	return (new_list);
}

/**
 * isprime - Check if a number is prime.
 * @new_list: An integer array containing divisors and factors.
 * @size: The size of the 'new_li' array.
 *
 * This function checks if the input number is prime based on the size of the
 * 'new_list' array. If the array is empty (size is 0), it indicates the number
 * is prime, and the function returns 1; otherwise, it returns 0.
 *
 * Return: 1 if the number is prime, 0 if it's not prime.
*/

int isprime(int *new_list, int size)
{
	(void)new_list;
	if (size == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * This function reads a long long integer from a specified file, checks if
 * it's a prime number, and prints the result along with its divisors or
 * factors if it's not prime. The program measures and displays the execution
 * time.
 *
 * Return: 0 on success, or an error code on failure.
*/

int main(int argc, char *argv[])
{
	FILE *file;
	int *result, size;
	long number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./rsa filename\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fscanf(file, "%ld", &number) != 1)
	{
		fprintf(stderr, "Error: Unable to read the number from the file.\n");
		exit(EXIT_FAILURE);
	}


	result = divisibility(number, &size);

	/* qsort(result, size, sizeof(int), compare); */

	printf("%ld=%d*%d\n", number, result[0], result[1]);

	/* Free the dynamically allocated memory */
	free(result);

	return (0);
}
