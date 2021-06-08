#include "ft_printf.h"

void 	ft_putnbr_fd(long long n, int fd)
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

int	ft_count(long long b)
{
	int	nb;

	nb = 0;
	if (b < 0)
		b = -b;
	while (b >= 10)
	{
		b = b / 10;
		nb++;
	}
	return (nb + 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	char	*mass;
	int		i;

	if (!s)
		return (0);
	mass = (char *)s;
	i = 0;
	while (mass[i] != '\0')
	{
		if (mass[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
