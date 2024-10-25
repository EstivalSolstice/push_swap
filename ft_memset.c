#include "libft.h"

void *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *ptr2 = (unsigned char *)ptr;
    while (num--)
	{
        *ptr2++ = (unsigned char)value;
    }
    return ptr;
}
