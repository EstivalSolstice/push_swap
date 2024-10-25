#include "libft.h"

int ft_tolower(int c)
{
	int n = 0;
	if (c >= 65 && c <= 90)
	{
		n = c + 32;
		return n;
	}
	else
	{
	return c;
	}
}