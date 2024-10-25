#include "libft.h"

char	*ft_strdup(char *src)
{
	int		index = 0;
	int 	len = 0;
	char	*dest;

	while (src[len] != '\0')
	{
        len++;
    }

	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*srcstr;
// 	char	*deststr;

// 	srcstr = "Hello";
// 	printf("Source: %s\n", srcstr);
// 	deststr = ft_strdup(srcstr);
// 	printf("Destination: %s\n", deststr);
//  free(deststr);
// 	return (0);
// }
