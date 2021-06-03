#include "ft_printf.h"

int 	ft_type(char **mass, t_struct *flag, va_list arg)
{
	int 	nb;

	nb = 0;
	if (**mass == 'd')
		nb = ft_print_d(flag, arg);
//	if ()
	(*mass)++;
	return (nb);
}