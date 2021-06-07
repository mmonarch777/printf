#include "ft_printf.h"

static int	ft_no_minus(unsigned int number, t_struct *flag, int toch, int shir)
{
	int	len;

	len = 0;
	while (shir-- > toch)
	{
		if (flag->zero == 1 && flag->tochka != 1)
			flag->ch = '0';
		len += write(1, &flag->ch, 1);
	}
	while (toch-- > ft_count((unsigned int)number))
		len += write(1, "0", 1);
	len += ft_count(number);
	ft_putnbr_fd(number, 1);
	return (len);
}

static int ft_minus(unsigned int number, t_struct *flag, int toch, int shir)
{
	int	len;

	len = 0;
	shir -= toch;
	while (toch-- > ft_count((unsigned int)number))
		len += write(1, "0", 1);
	len += ft_count((unsigned int)number);
	ft_putnbr_fd(number,1);
	while (shir-- > 0)
		len += write(1, &flag->ch, 1);
	return (0);
}

int 	ft_print_u(t_struct *flag, va_list arg)
{
	unsigned int	number;
	int				dlina;
	int 			toch;
	int 			shir;

	dlina = 0;
	number = va_arg(arg, unsigned int);
	if (!number && flag->tochka == 1 && flag->precsion == 0)
		return (0);
	if (flag->precsion > ft_count((unsigned int)number))
		toch = flag->precsion;
	else
		toch = ft_count ((unsigned int)number);
	if (flag->widht > toch)
		shir = flag->widht;
	else
		shir = toch;
	if (flag->minus != 1)
		dlina = ft_no_minus(number, flag, toch, shir);
	else
		dlina = ft_minus(number, flag, toch, shir);
	return (dlina);
}
