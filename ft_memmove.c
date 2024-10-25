#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *pdest = (unsigned char *)dest;
	const unsigned char *psrc = (const unsigned char *)src;

	if (pdest < psrc || pdest >= (psrc + n))
	{
		while(n--)
		{
		*pdest++ = *psrc++;
		}
	}
	else
	{
		pdest = pdest + n;
		psrc = psrc + n;
		while(n--)
		{
			*(--pdest) = *(--psrc); 
		}
	}
	return dest;
}