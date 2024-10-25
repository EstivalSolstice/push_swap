#include "libft.h"

void	ft_putnbr_fd_mod(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_fd_mod(n / 10, fd);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
}
