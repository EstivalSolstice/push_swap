#include "libft.h"

void ft_puthex_lower(unsigned long num)
{
    char *hex_digits = "0123456789abcdef";
    
    if (num >= 16)
	{
        ft_puthex_lower(num / 16);
	}
	
    ft_putchar_fd(hex_digits[num % 16], 1);
}