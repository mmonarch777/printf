#include "ft_printf.h"

static void	ft_putnbr_hexx(unsigned long adres)
{
	unsigned long	copy;
	unsigned long	i;
	unsigned long	nb;

	copy = adres;
	i = 1;
	while (copy > 15)
	{
		copy /= 16;
		i *= 16;
	}
	while (i > 1)
	{
		nb = adres / i;
		write(1, &"0123456789abcdef"[nb], 1);
		adres %= i;
		i /= 16;
	}
	write(1, &"0123456789abcdef"[adres], 1);
}

static int	ft_no_minus(unsigned long adres, t_struct *flag, int toch, int shir)
{
	int	dlina;

	dlina = 0;
	if (flag->zero == 1 && flag->tochka != 1)
	{
		flag->ch = '0';
		dlina += write(1, "0x", 2);
	}
	while (shir-- > (toch + 2))
		dlina += write(1, &flag->ch, 1);
	if (flag->ch == ' ')
		dlina += write(1, "0x", 2);
	while (toch-- > ft_count_ptr(adres))
		dlina += write(1, "0", 1);
	ft_putnbr_hexx(adres);
	dlina += ft_count_ptr(adres);
	return (dlina);
}

static int	ft_print(unsigned long adres, t_struct *flag, int toch, int shir)
{
	int	dlina;

	dlina = 0;
	if (flag->minus != 1)
		dlina = ft_no_minus(adres, flag, toch, shir);
	else
	{
		dlina += write(1, "0x", 2);
		shir -= (toch + 2);
		while (toch-- > ft_count_ptr(adres))
			dlina += write(1, "0", 1);
		ft_putnbr_hexx(adres);
		dlina += ft_count_ptr(adres);
		while (shir-- > 0)
			dlina += write(1, &flag->ch, 1);
	}
	return (dlina);
}

int	ft_print_ptr(t_struct *flag, va_list arg)
{
	unsigned long	adres;
	int				dlina;
	int				toch;
	int				shir;

	adres = va_arg(arg, unsigned long);
	if (!adres && flag->tochka == 1 && flag->precsion == 0 && flag->widht == 0)
		return (0);
	if (flag->precsion > ft_count_ptr(adres))
		toch = flag->precsion;
	else
		toch = ft_count_ptr(adres);
	if (flag->widht < 0)
	{
		flag->minus = 1;
		flag->widht = -flag->widht;
	}
	if (flag->widht > toch)
		shir = flag->widht;
	else
		shir = toch;
	dlina = ft_print(adres, flag, toch, shir);
	return (dlina);
}
