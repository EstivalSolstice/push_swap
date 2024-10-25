#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t src_len = 0;
	size_t dst_len = 0;

	char *pdst = dst;
	const char *psrc = src;

	while (*psrc)
	{
		psrc++;
		src_len++;
	}

	while (*pdst)
	{
		pdst++;
		dst_len++;

		if (dst_len == dstsize)
		{
			return dst_len + src_len;
		}
	}

	size_t frspc = dstsize - dst_len;

	while (*src && frspc > 1)
	{
		*pdst++ = *src++;
		frspc--;
	}
	
	if (frspc > 0)
	{
		*pdst = '\0';
	}

	return dst_len + src_len;
}
