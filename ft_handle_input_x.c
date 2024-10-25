#include "libft.h"

void	ft_handle_input_x(va_list args)
{
	unsigned int nx = va_arg(args, unsigned int);
	ft_puthex_lower(nx);
}