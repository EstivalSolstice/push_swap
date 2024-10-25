#include "libft.h"

int	ft_atoi(char *str)
{
	int	result;
	int	dashes;

	result = 0;
	dashes = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			dashes = -dashes;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * dashes);
}

// int	main(void)
// {
// 	char	src[99] = " -1234 567";
// 	int		result;

// 	result = ft_atoi(src);
// 	printf("Result: %d\n", result);
// 	return (0);
// }
