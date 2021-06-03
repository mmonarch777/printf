#include "ft_printf.h"

int		ft_print_d(t_struct *flag, va_list arg)
{
	int 		dlinna;
	long long 	number;

	number = va_arg(arg, int);
	dlinna = ft_add_flag(flag, number);
	return (dlinna);
}
