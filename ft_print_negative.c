#include "ft_printf.h"

static int ft_no_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int		dlinna;

	dlinna = 0;
	if (flag->zero == 1 && flag->tochka != 1)
		flag->ch = '0';
	if (flag->ch == '0')
		dlinna += write(1, "-", 1);
	while (shir-- > (toch + 1))
		dlinna += write(1, &flag->ch, 1);
	if (flag->ch == ' ')
		dlinna += write(1, "-", 1);
	while(toch-- > ft_count(nb))
		dlinna += write(1, "0", 1);
	ft_putnbr_fd(nb, 1);
	dlinna += ft_count(nb);
	return (dlinna);
}

static int ft_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int		dlinna;

	dlinna = 0;
	shir -= toch;
	dlinna += write(1, "-", 1);
	while(toch-- > ft_count(nb))
		dlinna += write(1, "0", 1);
	ft_putnbr_fd(nb, 1);
	dlinna += ft_count(nb);
	while(shir-- > (toch))
		dlinna += write(1, &flag->ch, 1);
	return (dlinna);

}

int 	ft_print_negative(t_struct *flag, long long nb, int toch, int shir)
{
	int		dlinna;

	dlinna = 0;
	nb = -nb;
	if (flag->minus != 1)
		dlinna = ft_no_minus(flag, nb, toch, shir);
	else
		dlinna = ft_minus(flag, nb, toch, shir);
	return (dlinna);
}

