#include "ft_printf.h"

static void	ft_initialize_flag(t_struct *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->widht = 0;
	flag->tochka = 0;
	flag->precsion = 0;
	flag->type = 0;
	flag->ch = ' ';
}

int 	ft_printf(const char *format, ...)
{
	int			length;
	char		*mass;
	va_list 	arg;
	t_struct	flag;

	length = 0;
	mass = (char *)format;
	va_start(arg, format);
	ft_initialize_flag(&flag);
	while (*mass)
	{
		if (*mass == '%')
		{
			mass++;
			length += ft_parsing_flag(&mass, arg, &flag);
		}
		if (*mass && *mass != '%')
			length += write(1, mass++, 1);
	}
	va_end(arg);
	return (length);
}
