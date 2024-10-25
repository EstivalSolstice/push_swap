#include "libft.h"

void	ft_handle_input_Xu(va_list args)
{
	unsigned int nX = va_arg(args, unsigned int);
	ft_puthex_lower(nX);
}