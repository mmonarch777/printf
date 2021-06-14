#include "ft_printf.h"

static int	ft_no_minus(unsigned int nb, t_struct *flag, int toch, int shir)
{
	int	len;

	len = 0;
	while (shir-- > toch)
	{
		if (flag->zero == 1 && flag->tochka != 1)
			flag->ch = '0';
		len += write(1, &flag->ch, 1);
	}
	while (toch-- > ft_count_ptr((unsigned int)nb))
		len += write(1, "0", 1);
	if (nb == 0 && flag->tochka == 1 && flag->precsion == 0)
		len += write(1, " ", 1);
	else
	{
		ft_putnbr_hex((unsigned int)nb, flag);
		len += ft_count_ptr((unsigned int)nb);
	}
	return (len);
}

static int	ft_minus(unsigned int nb, t_struct *flag, int toch, int shir)
{
	int	len;

	len = 0;
	shir -= toch;
	while (toch-- > ft_count_ptr((unsigned int)nb))
		len += write(1, "0", 1);
	if (nb == 0 && flag->tochka == 1 && flag->precsion == 0)
		len += write(1, " ", 1);
	else
	{
		ft_putnbr_hex((unsigned int)nb, flag);
		len += ft_count_ptr((unsigned int)nb);
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
		*toch = ft_count_ptr((unsigned int)nb);
	}
	if (flag->precsion > ft_count_ptr((unsigned int)nb))
		*toch = flag->precsion;
	else
		*toch = ft_count_ptr((unsigned int)nb);
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

int	ft_print_XXX(t_struct *flag, va_list arg, char **mass)
{
	unsigned int	nb;
	int				dlina;
	int				toch;
	int				shir;

	nb = va_arg(arg, int);
	if (!nb && flag->tochka == 1 && flag->precsion == 0 && flag->widht == 0)
		return (0);
	if (**mass == 'X')
		flag->hex = 'X';
	ft_start(nb, flag, &toch, &shir);
	if (flag->minus != 1)
		dlina = ft_no_minus(nb, flag, toch, shir);
	else
		dlina = ft_minus(nb, flag, toch, shir);
	return (dlina);
}
