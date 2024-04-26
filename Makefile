NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c  ls_functions.c libft/split_function.c libft/libft_fun.c check_nbrs.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c check_doubles.c \
		printf/ft_hex.c printf/ft_printf.c printf/ft_putadress.c printf/ft_Upphex.c\
		printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putstr.c printf/ft_putunsigned.c\
		check_overflow.c libft/libft2.c actions/sa_sb_ss.c actions/pa_pb.c\
		actions/ra_rb_rr.c  actions/rra_rrb_rrr.c sorting/sort_three.c sorting/sort_five.c\
		sorting/sort_utils.c sorting/stack_sort.c sorting/set_cost_to_push.c\
		sorting/stack_sort_utils2.c
		
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