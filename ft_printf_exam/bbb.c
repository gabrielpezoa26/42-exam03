#include <stdio.h>
#include <limits.h>

int main()
{
	long i = 0;

	while (i < INT_MAX)
	{
		printf("%ld\n", i);
		i++;
	}
	return (0);
}