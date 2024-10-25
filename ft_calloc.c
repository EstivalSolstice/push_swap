#include "libft.h"

void *ft_calloc(size_t num, size_t size)
{
	size_t t_size = 0;

	if (num == 0 || size == 0 || SIZE_MAX / size < num)
	{
        return NULL;
    }

	t_size = num * size;

	void *memory = malloc(t_size);

	if (memory == NULL)
	{
        return NULL;
    }

	unsigned char *pmemory = (unsigned char *)memory;
	int value = 0;

    while (t_size--)
	{
        *pmemory++ = (unsigned char)value;
    }
	return memory;
}
