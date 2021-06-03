#include "ft_printf.h"

void 	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	na;
	unsigned int	i;

	nb = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	na = n;
	while (na >= 10)
	{
		nb = nb * 10;
		na = na / 10;
	}
	while (nb != 0)
	{
		i = n /nb + 48;
		write(fd, &i, 1);
		n = n % nb;
		nb = nb /10;
	}
}

int		ft_count(int b)
{
	int 	nb;

	nb = 0;
	if (b < 0)
		b = -b;
	while (b >= 10)
	{
		b = b/10;
		nb++;
	}
	return (nb + 1);
}