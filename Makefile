NAME = libftprintf.a

SRC =	ft_printf.c			ft_parsing_flag.c			ft_type.c\
		ft_print_d.c		ft_all.c					ft_add_flag.c\
		ft_print_negative.c	ft_print_s.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $?

%.o : %.c
		gcc $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean
		make all

.PHONY : clean fclean all re