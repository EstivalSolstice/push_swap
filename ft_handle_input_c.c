#include "libft.h"

void	ft_handle_input_c(va_list args)
{
	char c = (char)va_arg(args, int);
	write(1, &c, 1);
}