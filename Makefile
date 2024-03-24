NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c  ls_functions.c split_function.c libft_fun.c check_nbrs.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c convert_to_int.c\
		printf/ft_hex.c printf/ft_printf.c printf/ft_putadress.c printf/ft_Upphex.c\
		printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putstr.c printf/ft_putunsigned.c\

		
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 