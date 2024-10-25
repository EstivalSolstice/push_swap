#include "libft.h"

void ft_puthex_upper(unsigned long num)
{
    char *hex_digits = "0123456789ABCDEF";
    
    if (num >= 16)
	{
        ft_puthex_upper(num / 16);
	}
	
    ft_putchar_fd(hex_digits[num % 16], 1);
}