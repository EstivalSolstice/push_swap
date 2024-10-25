#include "libft.h"

void	ft_checkinputprintf(const char fmt, va_list args)
{
	if(fmt == 'c')
		ft_handle_input_c(args);
	else if (fmt == 's')
		ft_handle_input_s(args);
	else if (fmt == 'p')
		ft_handle_input_p(args);
	else if (fmt == 'd' || fmt == 'i')
		ft_handle_input_d_i(args);
	else if (fmt == 'u')
		ft_handle_input_u(args);
	else if (fmt == 'x')
		ft_handle_input_x(args);
	else if (fmt == 'X')
		ft_handle_input_Xu(args);
	else if (fmt == '%')
		ft_putchar_fd('%', 1);
	else
    {
        write(1, "%", 1);
        write(1, &fmt, 1);
    }
}