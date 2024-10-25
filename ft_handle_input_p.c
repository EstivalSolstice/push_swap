#include "libft.h"

void	ft_handle_input_p(va_list args)
{
    void *p_val = va_arg(args, void *);

   	if (p_val == NULL)
	{
		ft_putstr_fd("(nil)", 1);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_lower((unsigned long)p_val);
	}
}