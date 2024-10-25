#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[99] = "Hello World";
// 	char	dest[99];

// 	printf("src = %s, dest = %s\n", src, dest);
// 	ft_strcpy(dest, src);
// 	printf("source = %s, destination = %s\n", src, dest);
// 	return (0);
// }
