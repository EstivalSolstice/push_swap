#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((*s1 || *s2) && (counter < n))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		counter++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*string1 = "Hallo";
// 	char	*string2 = "Hai";
// 	unsigned int x = 3;

// 	printf("%d", ft_strncmp(string1, string2, x));
// 	return (0);
// }
