#include "ft_printf.h"

static int 	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	else
		return (0);
}

int  	ft_parsing_flag(char **mass, va_list arg, t_struct *flag)
{
	int 		nb;

	while (ft_isalpha(**mass) != 1)
	{
		if (**mass == '-')
			flag->minus = 1;
		if (**mass == '0' && (*(*mass - 1) == '%' || *(*mass - 1) == '-'))
			flag->zero = 1;
		if (ft_isdigit(**mass) && flag->tochka < 1)
			flag->widht = (flag->widht * 10) + (**mass - 48);
		if (**mass == '*' && flag->tochka < 1)
			flag->widht = va_arg(arg, int);
		if(**mass == '.')
			flag->tochka = 1;
		if (ft_isdigit(**mass) && flag->tochka == 1)
			flag->precsion = (flag->precsion * 10) + (**mass - 48);
		if (**mass == '*' && flag->tochka == 1)
			flag->precsion = va_arg(arg, int);
		if (**mass == '%')
			break;
		if (!(ft_strchr("1234567890*%.-", **mass)))
			break;
		(*mass)++;
	}
	if (!(ft_strchr("cspdiuxX%", **mass)))
		return (0);
	nb = ft_type(mass, flag, arg);
	return (nb);
}
