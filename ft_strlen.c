#include "libft.h"

int	ft_strlen(char *str)
{
	int	counter = 0;

	if (!str)
	{
		return (0);
	}

	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char string[] = "Hello World";
	printf("length of string: %d\n", ft_strlen(string));
	return (0);
}

//create a function that counts and returns the number of characters in a string
*/