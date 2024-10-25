#include "libft.h"

void	ft_handle_input_u(va_list args)
{
	unsigned int nu = va_arg(args, unsigned int);
	ft_putnbr_fd_mod(nu, 1);
}