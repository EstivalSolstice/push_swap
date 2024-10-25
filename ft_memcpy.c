#include "libft.h"

void	ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char *psrc = (unsigned char *)src;
	unsigned char *pdest = (unsigned char *)dest;

	while (num--)
	{
		*pdest = *psrc;
		psrc++,
		pdest++;
	}
}