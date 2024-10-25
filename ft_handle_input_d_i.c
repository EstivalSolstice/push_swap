#include "libft.h"

void	ft_handle_input_d_i(va_list args)
{
	int n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
}