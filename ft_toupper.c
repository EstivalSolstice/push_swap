#include "libft.h"

int ft_toupper(int c)
{
	int n = 0;
	if (c >= 97 && c <= 122)
	{
		n = c - 32;
		return n;
	}
	else
	{
	return c;
	}
}
