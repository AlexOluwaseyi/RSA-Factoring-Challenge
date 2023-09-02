#include <stdio.h>
#include <stdlib.h>

int factor(int num)
{
	int div = 2;

	while (div != num)
	{
		if (num % div == 0)
			return (div);
		else
			div++;
	}
}

int main(int argc, char *argv[])
{
	FILE *file;
	long number;
	int result, fac;
	char line[256];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Failed to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (fscanf(file, "%ld", &number) != 1)
		{
			fprintf(stderr, "Error reading line in file\n");
			exit(EXIT_FAILURE);
		}
		fac = factor(number);
		result = number / fac;
		printf("%ld=%d*%d\n", number, result, fac);
	}
	return (0);
}
