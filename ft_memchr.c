#include "libft.h"

void *ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char *p = (unsigned char *)ptr;
	unsigned char c = (unsigned char)value;

	while (n--)
	{
		if (*p == c)
		{
			return p;
		}
		p++;
	}
	return NULL;
}
