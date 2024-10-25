#include "libft.h"

void	ft_handle_input_s(va_list args)
{
	char *str = va_arg(args, char *);
	int index = 0;

    while (str[index] != '\0')
	{
    	write(1, &str[index], 1);
    	index++;
    }
}