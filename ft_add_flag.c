#include "ft_printf.h"

static int 	ft_no_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int		len;

	len = 0;
	if (flag->zero == 1 && flag->tochka != 1)
		flag->ch = '0';
	while (shir-- > toch)
		len += write(1, &flag->ch, 1);
	while (toch-- > ft_count(nb))
		len += write(1, "0", 1);
	if (nb == 0 && flag->tochka == 1 && flag->precsion ==0)
		len += write(1, " ", 1);
	else
	{
		len += ft_count(nb);
		ft_putnbr_fd(nb, 1);
	}
	return (len);
}

static int	ft_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int		len;

	len = 0;
	shir -= toch;
	while (toch-- > ft_count(nb))
		len += write(1, "0", 1);
	if (nb == 0 && flag->tochka == 1 && flag->precsion ==0)
		len += write(1, " ", 1);
	else
	{
		len += ft_count((int) nb);
		ft_putnbr_fd(nb, 1);
	}
	while (shir--)
		len += write(1, " ", 1);
	return (len);
}

static int	ft_print_positive(t_struct *flag, long long nb, int toch, int shir)
{
	int		len;

	len = 0;
	if (flag->minus != 1)
		len = ft_no_minus(flag, nb, toch, shir);
	else
		len = ft_minus(flag, nb, toch, shir);
	return (len);
}

int 	ft_add_flag(t_struct *flag, long long nb)
{
	int		toch;
	int		shir;
	int		summ;

	if (flag->precsion > ft_count(nb))
		toch = flag->precsion;
	else
		toch = ft_count(nb);
	if (flag->widht > toch)
		shir = flag-> widht;
	else
		shir = toch;
	if (nb >= 0)
		summ = ft_print_positive(flag, nb, toch, shir);
	else
		summ = ft_print_negative(flag, nb, toch, shir);
	return (summ);
}
