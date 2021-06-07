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
	int 	hex;
}		t_struct;

int		ft_printf(const char *format, ...);
int  	ft_parsing_flag(char **mass, va_list arg);
int 	ft_type(char **mass, t_struct *flag, va_list arg);
int		ft_print_d(t_struct *flag, va_list arg);
int 	ft_add_flag(t_struct *flag, long long nb);
int 	ft_print_negative(t_struct *flag, long long nb, int toch, int shir);
void 	ft_putnbr_fd(long long n, int fd);
int		ft_count(long long b);
size_t	ft_strlen(const char *str);
int		ft_print_s(t_struct *flag, va_list arg);
int 	ft_print_c(t_struct *flag, va_list arg, char **mass);
int		ft_print_ptr(t_struct *flag, va_list arg);
int		ft_strchr(const char *s, int c);
int 	ft_print_u(t_struct *flag, va_list arg);
int		ft_count_ptr(unsigned long adres);
void	ft_putnbr_hex(unsigned long adres, t_struct *flag);
int		ft_print_XXX(t_struct *flag, va_list arg, char **mass);
#endif
