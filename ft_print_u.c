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
	if (number == 0 && flag->tochka == 1 && flag->precsion ==0)
		len += write(1, " ", 1);
	else
	{
		len += ft_count((unsigned int)number);
		ft_putnbr_fd(number, 1);
	}
	return (len);
}

static int	ft_minus(unsigned int number, t_struct *flag, int toch, int shir)
{
	int	len;

	len = 0;
	shir -= toch;
	while (toch-- > ft_count((unsigned int)number))
		len += write(1, "0", 1);
	if (number == 0 && flag->tochka == 1 && flag->precsion ==0)
		len += write(1, " ", 1);
	else
	{
		len += ft_count((unsigned int)number);
		ft_putnbr_fd(number, 1);
	}
	while (shir-- > 0)
		len += write(1, &flag->ch, 1);
	return (len);
}

static void	ft_start(unsigned int nb, t_struct *flag, int *toch, int *shir)
{
	if (flag->precsion < 0)
	{
		flag->tochka = 0;
		*toch = ft_count((unsigned int)nb);
	}
	else if (flag->precsion > ft_count((unsigned int)nb))
		*toch = flag->precsion;
	else
		*toch = ft_count ((unsigned int)nb);
	if (flag->widht < 0)
	{
		flag->minus = 1;
		flag->widht = -flag->widht;
	}
	if (flag->widht > *toch)
		*shir = flag->widht;
	else
		*shir = *toch;
}

int 	ft_print_u(t_struct *flag, va_list arg)
{
	unsigned int	number;
	int				dlina;
	int				toch;
	int				shir;

	dlina = 0;
	number = va_arg(arg, unsigned int);
	if (!number && flag->tochka == 1 && flag->precsion == 0 && flag->widht == 0)
		return (0);
	ft_start(number, flag, &toch, &shir);
	if (flag->minus != 1)
		dlina = ft_no_minus(number, flag, toch, shir);
	else
		dlina = ft_minus(number, flag, toch, shir);
	return (dlina);
}
