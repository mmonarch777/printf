#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef  struct s_struct
{
	int 	minus;
	int 	zero;
	int		widht;
	int 	tochka;
	int 	precsion;
	int		type;
	int 	ch;
}		t_struct;

int		ft_printf(const char *format, ...);
int  	ft_parsing_flag(char **mass, va_list arg, t_struct *flag);
int 	ft_type(char **mass, t_struct *flag, va_list arg);
int		ft_print_d(t_struct *flag, va_list arg);
int 	ft_add_flag(t_struct *flag, long long nb);
int 	ft_print_negative(t_struct *flag, long long nb, int toch, int shir);
void 	ft_putnbr_fd(int n, int fd);
int		ft_count(int b);
#endif
