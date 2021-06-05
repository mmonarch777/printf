#include "ft_printf.h"

static int ft_count_ptr(unsigned long adres)
{
	int 	i;

	i = 0;
	while (adres > 15)
	{
		adres /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_print_ptr(t_struct *flag, va_list arg)
{
	unsigned long 	adres;
	int 			dlina;
//	int 			toch;
//	int 			shir;
//
	dlina = 0;
	adres = va_arg(arg, unsigned long);
	if (flag->precsion > ft_count_ptr((int)adres))
		write(1, " ", 1);
	return (dlina);
}

