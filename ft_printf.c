#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	const char *ptr = fmt;

	while(*ptr != '\0')
	{
		if(*ptr == '%')
		{
			ptr++;
			ft_checkinputprintf(*ptr, args);
		}
		else
        {
            write(1, ptr, 1);
        }
		ptr++;
	}
	va_end(args);
	return 0;
}


// int main()
// {
//     ft_printf("Hello World!\n");
// 	printf("Hello World!\n");

//     ft_printf("Integer: %d\n", 42);
// 	printf("Integer: %d\n", 42);
	
//     ft_printf("String: %s\n", "Test String");
// 	printf("String: %s\n", "Test String");

//     ft_printf("Hex Lower: %x\n", 255);
// 	printf("Hex Lower: %x\n", 255);

//     ft_printf("Pointer: %p\n", main);
// 	printf("Pointer: %p\n", main);

//     return 0;
// }