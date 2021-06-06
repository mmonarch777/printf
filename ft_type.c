#include "ft_printf.h"

int 	ft_type(char **mass, t_struct *flag, va_list arg)
{
	int 	nb;

	nb = 0;
	if (**mass == 'd')
		nb = ft_print_d(flag, arg);
	if (**mass == 's')
		nb = ft_print_s(flag, arg);
	if (**mass == 'c' || **mass == '%')
		nb = ft_print_c(flag, arg, mass);
	if (**mass == 'p')
		nb = ft_print_ptr(flag, arg);
//	if (**mass == 'x')
//		nb = ft_print_XXX(flag, arg);
	(*mass)++;
	return (nb);
}