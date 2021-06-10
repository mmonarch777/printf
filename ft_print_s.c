#include "ft_printf.h"

static int	ft_print(t_struct *flag, char *mass, int toch, int shir)
{
	int	lenght;

	lenght = 0;
	if (flag->minus != 1)
	{
		if (flag->zero == 1)
			flag->ch = '0';
		while (shir-- > toch)
			lenght += write(1, &flag->ch, 1);
		while (toch--)
			lenght += write(1, mass++, 1 );
	}
	else
	{
		shir -=toch;
		while (toch--)
			lenght += write(1, mass++, 1 );
		while (shir--)
			lenght += write(1, &flag->ch, 1);
	}
	return (lenght);
}

static void	ft_add_f(char *mass, t_struct *flag, int *toch, int *shir)
{
	if (flag->precsion > (int)ft_strlen(mass))
		*toch = (int)ft_strlen(mass);
	else if (flag->precsion < (int)ft_strlen(mass) && flag->tochka == 1)
		*toch = flag->precsion;
	else
		*toch = (int)ft_strlen(mass);
	if (flag->precsion < 0)
		*toch = (int)ft_strlen(mass);
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

int	ft_print_s(t_struct *flag, va_list arg)
{
	int		dlinna;
	char	*mass;
	int		toch;
	int		shir;

	mass = va_arg(arg, char *);
	if (mass == NULL)
		mass = "(null)";
	ft_add_f(mass, flag, &toch, &shir);
	dlinna = ft_print(flag, mass, toch, shir);
	return (dlinna);
}
